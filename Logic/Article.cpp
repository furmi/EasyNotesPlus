//
//  Article.cpp
//  EasyNotePlus_thomas
//
//  Created by Thomas Fuhrmann on 08/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#include "Article.h"
#include "ExportStrategy.h"

using namespace EasyNote;

namespace EasyNote
{
    void Article::load()
    {
        if (!this->isLoaded())   //permet de tester si la note est déjà chargée
        {
        //conversion de l'ID en string
            std::ostringstream oss;
            oss << this->getId();
            std::string id = oss.str();

            string fichier = (id+".enp");
            ifstream file(fichier.c_str(), ios::in);  //ouverture du fichier en lecture
            if (file)
            {
                string title, text;
                file >> title >> text;  //permet de lire les éléments à partir du fichier
                file.close();
                //écriture des éléments dans l'objet
                this->setText(text);
                this->is_Loaded = 1; //signifie que le fichier est chargé
                this->is_Modified = 0;
            }
            else
                cerr << "Impossible d'ouvrir le fichier !" << endl;
        }
    }

    void Article::save()
    {
    //conversion de l'ID en string
            std::ostringstream oss;
            oss << this->getId();
            std::string id = oss.str();

    //sauvegarde du fichier qui correspond à la note
        if(this->isModified())  //permet de tester si la note a été modifiée
        {
            string fichier;
            fichier.append(id+".enp");
            ofstream file(fichier.c_str(), ios::out | ios::trunc);  //ouverture en écriture, fichier vierge
            if (file)
            {
                cout<<"dans file\n";
                file << this->getTitle() << "\n" << this->getText() << endl; //permet d'écrire dans un fichier
                file.close();
                this->is_Modified = 0;  //objet sauvegardé donc il n'est plus modifié
            }
            else
                cerr << "Impossible d'ouvrir le fichier !" << endl;
    //sauvegarde des identifiants de la note dans le fichier descripteur du NotesManager
        //recherche dans le fichier de description si la note est référencée
            string fichierDesc = "desc.enp";
            bool existe = 0;    //flag qui permet de savoir si une note est référencée dans le fichier
            ifstream fileDesc(fichierDesc.c_str(), ios::in | ios::out | ios::ate);  //ouverture en lecture et en écriture pour modifier le titre si jamais il a été changé
            if (fileDesc)
            {
                string typeDoc, title;
                unsigned long int idfile;
                while(!fileDesc.eof())  //on parcourt le fichier afin de voir si l'ID existe déjà
                {
                    fileDesc >> typeDoc >> idfile >> title;
                    if (idfile == this->getId())    //l'ID existe, il faut vérifier que le titre n'a pas été changé
                    {
                        /*if (title != this->getTitle())  //le titre a été changé, il faut le mettre à jour
                        {

                        }
                        */  //à implémenter si on veut que le titre des notes soit modifiable
                        existe = 1; //indique que la note est référencée
                        break;  //pour sortir de la boucle
                    }
                }
                fileDesc.close();
            }
            else
                cerr << "Impossible d'ouvrir le fichier !" << endl;
        //si la note n'est pas référencée dans le fichier de description, on l'ajoute
            if(!existe) //si la note n'est pas référencée dans le fichier
            {
                //on ouvre le fichierDesc en écriture et on ajoute la note en dernière position
                ofstream file(fichierDesc.c_str(), ios::out | ios::app);  //ouverture en écriture, ajout en fin de fichier
                if (file)
                {
                    file << "Article" << " " << this->getId() << " " << this->getTitle() << endl; //permet d'écrire dans un fichier
                    file.close();
                }
                else
                    cerr << "Impossible d'ouvrir le fichier !" << endl;
            }
        }
    }

    Article Article::operator=(const Article& a)
    {
        this->Note::operator=(a);
        text = a.text;
        return *this;
    }

    ostream& operator<<(ostream& f, const Article& a)
    {
        f<<a;
        f<<"Texte : "<<a.getText()<<"\n";
        return f;
    }

    string Article::exportAsPart(ExportStrategy* es, unsigned int titleLevel)
    {
        return es->exportNote(this, titleLevel);
    }

    Article::~Article() {}
}

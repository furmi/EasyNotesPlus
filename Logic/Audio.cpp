//
//  Audio.cpp
//  EasyNotePlus_thomas
//
//  Created by Thomas Fuhrmann on 08/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#include "Audio.h"
#include "ExportStrategy.h"

using namespace EasyNote;

namespace EasyNote
{
    string Audio::exportAsPart(ExportStrategy* es, unsigned int titleLevel)
    {
        cout<<"arrivé dans ExportAsPart Audio\n";
        return es->exportNote(this, titleLevel);
    }

    void Audio::save()
    {
    //appel à la méthode save() de la classe mère (permet d'enregistrer la note physiquement)
        Media::save();
    //sauvegarde des identifiants de la note dans le fichier descripteur du NotesManager
    //recherche dans le fichier de description si la note est référencée
        string fichierDesc = "desc.enp";
        bool existe = 0;    //flag qui permet de savoir si une note est référencée dans le fichier
        ifstream fileDesc(fichierDesc.c_str(), ios::in | ios::out | ios::ate);  //ouverture en lecture et en écriture pour modifier le titre si jamais il a été changé
        if (fileDesc)
        {
            string typeDoc, title;
            unsigned long int id;
            while(!fileDesc.eof())  //on parcourt le fichier afin de voir si l'ID existe déjà
            {
                fileDesc >> typeDoc >> id >> title;
                if (id == this->getId())    //l'ID existe, il faut vérifier que le titre n'a pas été changé
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
                file << "Audio" << " " << this->getId() << " " << this->getTitle() << endl; //permet d'écrire dans un fichier
                file.close();
            }
            else
                cerr << "Impossible d'ouvrir le fichier !" << endl;
        }
    }

	Audio::~Audio() {}
}

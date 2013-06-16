//
//  Article.cpp
//  EasyNotePlus_thomas
//
//  Created by Thomas Fuhrmann on 08/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#include "Article.h"
#include "ExportStrategy.h"

#include <QFile>       // Pour utiliser le fichier
#include <QString>     // Stocke le contenu du fichier
#include <QTextStream> // Flux sortant du fichier

using namespace EasyNote;

namespace EasyNote
{
    void Article::load()
    {
        qDebug()<<"dans le load\n";
        if (!this->isLoaded())   //permet de tester si la note est déjà chargée
        {
        //conversion de l'ID en QString
            qDebug()<<"dans le if\n";
            QString id = QString::number(this->getId());
			
			QString nom = (id+".enp");
            QFile fichier(nom);
            //ifstream file(fichier.c_str(), ios::in);  //ouverture du fichier en lecture
            if (fichier.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                qDebug()<<"dans le fichier\n";
				QTextStream flux(&fichier);
                QString title, text;
				title = flux.readLine();
				text = flux.readLine();  //permet de lire les éléments à partir du fichier
                fichier.close();
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

        QString id = QString::number(this->getId());

        qDebug()<<"id : "<<id<<endl;

    //sauvegarde du fichier qui correspond à la note
        if(this->isModified())  //permet de tester si la note a été modifiée
        {
            QString nom = (id+".enp");
            qDebug()<<"nom fichier : "<<nom<<endl;
            QFile fichier(nom);
            if (fichier.open(QIODevice::WriteOnly | QIODevice::Truncate))
            {
				QTextStream flux(&fichier);
                flux.setCodec("UTF-8");
                flux << this->getTitle() << "\n" << this->getText() << endl; //permet d'écrire dans un fichier
                fichier.close();
                this->is_Modified = 0;  //objet sauvegardé donc il n'est plus modifié
            }
            else
                cerr << "Impossible d'ouvrir le fichier !" << endl;
    //sauvegarde des identifiants de la note dans le fichier descripteur du NotesManager
        //recherche dans le fichier de description si la note est référencée
            QString fichierDesc = "desc.enp";
            bool existe = 0;    //flag qui permet de savoir si une note est référencée dans le fichier 
            QFile fileDesc(fichierDesc);
            if (fileDesc.open(QIODevice::ReadWrite | QIODevice::Append)) //ouverture en lecture et en écriture pour modifier le titre si jamais il a été changé
            {
                QString typeDoc, title;
                unsigned long int idfile;
                QTextStream flux(&fileDesc);
                flux.setCodec("UTF-8");
                qDebug()<<"avant while"<<endl;
                qDebug()<<"flux"<<flux.readAll()<<endl;
                while(flux.readLine() != "")  //on parcourt le fichier afin de voir si l'ID existe déjà
                {
                    qDebug()<<"dans while"<<endl;
                    flux >> typeDoc >> idfile >> title;
                    if (idfile == this->getId())    //l'ID existe, il faut vérifier que le titre n'a pas été changé
                    {
                        /*if (title != this->getTitle())  //le titre a été changé, il faut le mettre à jour
                        {

                        }*/
                          //à implémenter si on veut que le titre des notes soit modifiable
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
                qDebug()<<"dans le existe"<<endl;
                //on ouvre le fichierDesc en écriture et on ajoute la note en dernière position
                QFile fileDesc(fichierDesc);
                QTextStream flux(&fileDesc);
                flux.setCodec("UTF-8");
				if (fileDesc.open(QIODevice::WriteOnly | QIODevice::Append))
                {
                    flux << "Article" << " " << this->getId() << " " << this->getTitle() << endl; //permet d'écrire dans un fichier
                    fileDesc.close();
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
        //f<<"Texte : "<<a.getText()<<"\n";
        return f;
    }

    QString Article::exportAsPart(ExportStrategy* es, unsigned int titleLevel)
    {
        return es->exportNote(this, titleLevel);
    }

    Article::~Article() {}
}

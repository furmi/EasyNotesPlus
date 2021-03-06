//
//  Audio.cpp
//  EasyNotePlus_thomas
//
//  Created by Thomas Fuhrmann on 08/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#include <QTextStream>
#include <QFile>
#include "Audio.h"
#include "ExportStrategy.h"

using namespace EasyNote;

namespace EasyNote
{
    QString Audio::exportAsPart(ExportStrategy* es, unsigned int titleLevel)
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
            QString fichierDesc = "desc.enp";
            bool existe = 0;    //flag qui permet de savoir si une note est référencée dans le fichier 
            QFile fileDesc(fichierDesc);
            if (fileDesc.open(QIODevice::ReadWrite | QIODevice::Append)) //ouverture en lecture et en écriture pour modifier le titre si jamais il a été changé
            {
                QString typeDoc, title;
                unsigned long int idfile;
                QTextStream flux(&fileDesc);
                flux.setCodec("UTF-8");
                while(!flux.atEnd())  //on parcourt le fichier afin de voir si l'ID existe déjà
                {
                    flux >> typeDoc >> idfile >> title;
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
                QFile fileDesc(fichierDesc);
                QTextStream flux(&fileDesc);
                flux.setCodec("UTF-8");
				if (fileDesc.open(QIODevice::WriteOnly | QIODevice::Append))
                {
					
                    flux << "Audio" << " " << this->getId() << " " << this->getTitle() << endl; //permet d'écrire dans un fichier
                    fileDesc.close();
                }
                else
                    cerr << "Impossible d'ouvrir le fichier !" << endl;
			}
    }

	Audio::~Audio() {}
}

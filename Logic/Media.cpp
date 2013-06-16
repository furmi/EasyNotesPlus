//
//  Media.cpp
//  EasyNotePlus_thomas
//
//  Created by Thomas Fuhrmann on 08/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#include <QTextStream>
#include <QFile>
#include "Media.h"

using namespace EasyNote;

namespace EasyNote
{
	Media::~Media()
	{

	}

    void Media::load()
    {
        if (!this->isLoaded())   //permet de tester si la note est déjà chargée
        {
        //conversion de l'ID en string

            QString id = QString::number(this->getId());

		//Chargement de l'ensemble des attributs de Media à partir du fichier
            QString nom = (id+".enp");
            QFile fichier(nom);
            if (fichier.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                QString title, desc, path;
                QTextStream flux(&fichier);
                title = flux.readLine();
				desc = flux.readLine();
				path = flux.readLine();
                fichier.close();
                //écriture des éléments dans l'objet
                this->setDescription(desc);
                this->setPath(path);
                this->is_Loaded = 1; //signifie que le fichier est chargé
                this->is_Modified = 0;
            }
            else
                cerr << "Impossible d'ouvrir le fichier !" << endl;
        }
    }

    void Media::save()
    {
    //conversion de l'ID en string

        QString id = QString::number(this->getId());

    //sauvegarde du fichier qui correspond à la note
        if(this->isModified())  //permet de tester si la note a été modifiée
        {
            QString nom = (id+".enp");
            QFile fichier(nom);
            if (fichier.open(QIODevice::WriteOnly | QIODevice::Truncate))
            {
				QTextStream flux(&fichier);
                flux << this->getTitle() << "\n" << this->getDescription() << "\n" << this->getPath() << endl; //permet d'écrire dans un fichier
                fichier.close();
                this->is_Modified = 0;  //objet sauvegardé donc il n'est plus modifié
            }
            else
                cerr << "Impossible d'ouvrir le fichier !" << endl;
        }
    /* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
    /* La méthode sera surchagée dans les classes filles de Media afin de pouvoir
    avoir une méthode adéquate pour l'insertion de la note dans le fichier de description
    du NoteManager (à gérer au niveau des filles car il faut indiquer le type de document.
    La méthode surchargée fera appel à la méthode de Média pour ce qui est de la sauvegarde
    du fichier sur le disque dur.
    */
    }
}

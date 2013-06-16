//
//  NotesManager.cpp
//  EasyNotePlus_julien
//
//  Created by Julien Nicolas on 31/05/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#include <QString>
#include "NotesManager.h"
#include "NotesIterator.h"
#include "ConstNotesIterator.h"
#include "NoteFactory.h"
#include "Note.h"
#include "ArticleFactory.h"
#include "DocumentFactory.h"
#include "ArticleFactory.h"
#include "VideoFactory.h"
#include "ImageFactory.h"
#include "AudioFactory.h"

//class Note;
class ExportStrategy;

using namespace EasyNote;


namespace EasyNote 
{

	// Initialisation de l'attribut statique

	NotesManager* NotesManager::instance = 0;

	// CONSTRUCTEURS/DESTRUCTEURS

	NotesManager::NotesManager():
	path("hello")
	{
		// Construction des diverses factories
		
		factories["Document"] = new DocumentFactory;
		factories["Article"] = new ArticleFactory;
		factories["Video"] = new VideoFactory;
		factories["Image"] = new ImageFactory;
		factories["Audio"] = new AudioFactory;
	}

	NotesManager::~NotesManager ()
	{
		// Destruction des factories
		
		delete factories["Document"];
		delete factories["Article"];
		delete factories["Video"];
		delete factories["Image"];
		delete factories["Audio"];
		
		// Destruction du Note manager
		
		releaseInstance();
	}

	// MÉTHODES STATIQUES

	NotesManager* NotesManager::getInstance()
	{
		if (instance == 0)
			instance = new NotesManager;
	
		return NotesManager::instance;
	}

	void NotesManager::releaseInstance()
	{
		if (instance != 0)
			delete instance;
	}
	
	// MÉTHODES DES ITÉRATEURS
	
	NotesManager::NotesIterator NotesManager::begin ()
	{
		NotesIterator it(notes.begin());
	
		return it;
	}
	
	NotesManager::NotesIterator NotesManager::end()
	{
		NotesIterator it(notes.end());
		
		return it;
	}
	
	NotesManager::ConstNotesIterator NotesManager::cbegin () const
	{
		ConstNotesIterator it(notes.begin());
		
		return it;
	}
	
	NotesManager::ConstNotesIterator NotesManager::cend () const
	{
		ConstNotesIterator it(notes.end());
		
		return it;
	}
	
	// Méthode d'accès à factories
	
	Note* NotesManager::getNewNote (QString str,QString title)
	{
		return factories[str]->buildNewNote(title);
	} 
	
	// LOAD du NotesManager (charge les fichiers de son descripteur

    void NotesManager::loadNM()
    {
        QString nom = ("desc.enp");
		QFile fichier(nom);
		if (fichier.open(QIODevice::ReadOnly | QIODevice::Text))
            QString typeNote, title;
            unsigned long int id;
            QTextStream flux(&fileDesc);
            while(!flux.atEnd())  //on boucle sur tout le fichier pour récupérer toutes les informations
            {
                flux >> typeNote >> id >> title;  //permet de lire les éléments à partir du fichier (ligne par ligne)
                //appel aux factories pour créer les note en mémoire
                if (typeNote=="")
                    cout<<"vide\n";
                else
                    addNote(factories[typeNote]->buildNote(id, title));
                cout<<"Occurence : "<<typeNote<<"  "<<id<<"  "<<title<<"\n";
            }
        }
        else
            cerr << "Impossible d'ouvrir le fichier !" << endl;
    }
    
    void NotesManager::loadNote(Note* n)
    {
        n->load();
    }

}



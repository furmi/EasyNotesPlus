//
//  NotesManager.cpp
//  EasyNotePlus_julien
//
//  Created by Julien Nicolas on 31/05/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#include <string>
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
		
		factories["DocumentFactory"] = new DocumentFactory;
		factories["ArticleFactory"] = new ArticleFactory;
		factories["VideoFactory"] = new VideoFactory;
		factories["ImageFactory"] = new ImageFactory;
		factories["AudioFactory"] = new AudioFactory;
	}

	NotesManager::~NotesManager ()
	{
		// Destruction des factories
		
		delete factories["DocumentFactory"];
		delete factories["ArticleFactory"];
		delete factories["VideoFactory"];
		delete factories["ImageFactory"];
		delete factories["AudioFactory"];
		
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
	
	Note* NotesManager::getNewNote (string str,string title)
	{
		return factories[str]->buildNewNote(title);
	} 

}



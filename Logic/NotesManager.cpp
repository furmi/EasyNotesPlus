//
//  NotesManager.cpp
//  EasyNotePlus_julien
//
//  Created by Julien Nicolas on 31/05/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#include <iostream>
#include <string>
#include "NotesManager.h"
#include "NotesIterator.h"
#include "ConstNotesIterator.h"

class Note;
class ExportStrategy;
class NoteFactory;

using namespace EasyNote;


namespace EasyNote 
{

	// Initialisation de l'attribut statique

	NotesManager* NotesManager::instance = 0;

	// CONSTRUCTEURS/DESTRUCTEURS

	NotesManager::NotesManager():
	path("hello"),notes(set<Note*>()),factories(map<string,NoteFactory*>()),strategies(map<string,ExportStrategy*>())
	{
	
	}

	NotesManager::~NotesManager ()
	{
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
	
	NotesManager::ConstNotesIterator NotesManager::cbegin ()
	{
		ConstNotesIterator it(notes.begin());
		
		return it;
	}
	
	NotesManager::ConstNotesIterator NotesManager::cend ()
	{
		ConstNotesIterator it(notes.end());
		
		return it;
	}
	
	

}



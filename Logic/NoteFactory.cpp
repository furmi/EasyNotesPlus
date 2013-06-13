//
//  NoteFactory.cpp
//  EasyNotePlus_julien
//
//  Created by Julien Nicolas on 12/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#include "NoteFactory.h"
#include <string>
#include "Note.h"
#include "NotesManager.h"


/*********************************************************************
						REMARQUE IMPORTANTE

Lors du chargement d'une note grâce à une des factories, ce sera au 
NoteManager de charger le contenu de la note dans l'attribut prévu
à cet effet (text pour Article).

Voici l'instruction qui sera à exécuter:


 // Récupération du contenu de la note
 
 note->load();


***********************************************************************/


using namespace std;
using namespace EasyNote;


namespace EasyNote
{
	NoteFactory::~NoteFactory()
	{
		
	}

	Note* NoteFactory::buildNote(unsigned long int id_,const string& title)
	{
		// Création de la note
		
		Note* note = factory();
		
		// Initialisation de la note vierge avec les attributs de celle que l'on charge
		
		note->setTitle(title);
		note->setId(id_);
		
		
		
		return note;
	}
	
	Note* NoteFactory::buildNewNote (const string& title)
	{
		// Création de la note
		
		return factory();
	}
	
	Note* NoteFactory::buildNoteCopy(const Note& note)
	{
		// Création de la note 
		
		Note* n = factory();
		
		// Recopie des attribus
		
		*n = note;
		
		// Changement de l'id car c'est une copie, pas un clone
		
		n->setId(Note::generateTimeStamp());
		
		return n;
	}
	
	
}
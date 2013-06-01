//
//  ConstNotesIterator.h
//  EasyNotePlus_julien
//
//  Created by Julien Nicolas on 01/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#ifndef EasyNotePlus_julien_ConstNotesIterator_h
#define EasyNotePlus_julien_ConstNotesIterator_h
#include "NotesManager.h"
#include <set>
#include <string>

using namespace EasyNote;

namespace EasyNote
{

	class NotesManager::ConstNotesIterator
	{
	public:
	
		// Méthodes de déplacement
	
		NotesIterator first() const; // retourne un itérateur sur le premier élément
		NotesIterator end () const; //retourne un itérateur sur le dernier élément
		Note* operator++ (int) const; // Méthode next (c'est la notation post-fixée)
		Note* operator-- (int) const;
		Note* operator* () const; // Retourne l'élément courant
	
		// Méthodes de contrôle
	
		// Vrai si l'itérateur est arrivé au bout du set (on ne devrait pas spécialiser? parcequ'on peut se déplacer dans les deux sens)
	
		bool isDone () const; 
	
		// Constructeurs 
	
		ConstNotesIterator(); 
		ConstNotesIterator(set<Note*>::iterator);
	
		// Attributs
	
		set<Note*> iterator;	// Pointe vers la structure de données à parcourir pour qu'il l'ait tjr à jour
		
	};

}


#endif

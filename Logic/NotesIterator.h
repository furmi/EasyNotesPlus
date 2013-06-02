//
//  NotesIterator.h
//  EasyNotePlus_julien
//
//  Created by Julien Nicolas on 01/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#ifndef EasyNotePlus_julien_NotesIterator_h
#define EasyNotePlus_julien_NotesIterator_h
#include "NotesManager.h"
#include <string>
#include <set>

using namespace EasyNote;


namespace EasyNote
{
	// toute la classe peut être publique car elle est mise dans la partie privée de NotesManager

	class NotesManager::NotesIterator
	{
	public:
	
		// Méthodes de déplacement
	
		NotesIterator first(); // retourne un itérateur sur le premier élément
		NotesIterator end (); //retourne un itérateur sur le dernier élément
		Note* operator++ (int); // Méthode next (c'est la notation post-fixée)
		Note* operator-- (int);
		Note* operator* (); // Retourne l'élément courant
	
		// Méthodes de contrôle
	
		// Vrai si l'itérateur est arrivé au bout du set (on ne devrait pas spécialiser? parcequ'on peut se déplacer dans les deux sens)
	
		bool isDone (); 
	
		// Constructeurs 
	
		NotesIterator(); 
		NotesIterator(set<Note*>::iterator );
	
		// Attributs
	
		set<Note*>::iterator iterator;	// Pointe vers la structure de données à parcourir pour qu'il l'ait tjr à jour
	};

}





#endif
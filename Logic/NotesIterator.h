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
	
		NotesIterator& operator++ ();
		NotesIterator& operator-- ();
		NotesIterator operator++ (int); // Méthode next (c'est la notation post-fixée)
		NotesIterator operator-- (int);
		Note* operator* (); // Retourne l'élément courant
	
		// Méthodes de comparaison
		
		bool operator==(const NotesIterator&);
		bool operator!=(const NotesIterator&);
		
		// Méthodes d'accès aux données
		
		const string getTitle () const; // À redéfinir
		unsigned int getId() const; // À redéfinir
	
	private:
		friend class NotesManager;
	
		// Constructeurs 
		
		NotesIterator(); 
		NotesIterator(set<Note*>::iterator );
			
		// Attributs
	
		set<Note*>::iterator iterator;	
	};

}





#endif

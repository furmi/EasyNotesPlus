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
#include <QString>

using namespace EasyNote;

namespace EasyNote
{

	// toute la classe peut être publique car elle est mise dans la partie privée de NotesManager
	
	class NotesManager::ConstNotesIterator
	{
	public:
		
		// Méthodes de déplacement
		
		ConstNotesIterator& operator++ ();
		ConstNotesIterator& operator-- ();
		ConstNotesIterator operator++ (int); // Méthode next (c'est la notation post-fixée)
		ConstNotesIterator operator-- (int);
		const Note* const operator* () const; // Retourne l'élément courant
		
		// Méthodes de comparaison
		
		bool operator==(const ConstNotesIterator&) const;
		bool operator!=(const ConstNotesIterator&) const;
		
		// Méthodes d'accès aux données
		
		const QString getTitle () const; // À redéfinir
		unsigned int getId() const; // À redéfinir
		
		
	private:
		
		friend class NotesManager;
		
		// Constructeurs 
		
		ConstNotesIterator(); 
		ConstNotesIterator(set<Note*>::iterator );
	
		// Attributs
		
		set<Note*>::iterator iterator;	
	};

}


#endif

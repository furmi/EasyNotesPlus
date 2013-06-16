//
//  NoteFactory.h
//  EasyNotePlus_julien
//
//  Created by Julien Nicolas on 02/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#ifndef EasyNotePlus_julien_NoteFactory_h
#define EasyNotePlus_julien_NoteFactory_h

#include <QString>

using namespace std;

//class Note;


namespace EasyNote
{
	using namespace EasyNote;
	class Note;

	class NoteFactory
	{
	public:
		// Destructeur
		
		virtual ~NoteFactory(); // Pas définit car inutilisable
	
		// Méthodes
	
		Note* buildNote(unsigned long int id_,const QString& title);
		Note* buildNewNote (const QString& title);
		Note* buildNoteCopy(const Note& note);
		
		virtual Note* factory()=0;
		
	/*protected:
		unsigned long int newId(); Ne me serre pas car la génération
	d'un id est gérée par le constructeur de la classe Note */
	};
	
}


#endif

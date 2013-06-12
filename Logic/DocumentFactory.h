//
//  DocumentFactory.h
//  EasyNotePlus_julien
//
//  Created by Julien Nicolas on 12/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#ifndef EasyNotePlus_julien_DocumentFactory_h
#define EasyNotePlus_julien_DocumentFactory_h

#include "NoteFactory.h"
#include <string>

using namespace std;


namespace EasyNote
{
	using namespace EasyNote;
	class Note;

	class DocumentFactory:public NoteFactory
	{
			
	public:
		virtual Note* factory();
		
		// Destructeur
		
		virtual ~DocumentFactory();
	
	};

}



#endif

//
//  ImageFactory.h
//  EasyNotePlus_julien
//
//  Created by Julien Nicolas on 12/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#ifndef EasyNotePlus_julien_ImageFactory_h
#define EasyNotePlus_julien_ImageFactory_h

#include "NoteFactory.h"

using namespace std;
//class string;

namespace EasyNote
{
	using namespace EasyNote;
	class Note;
	
	class ImageFactory:public NoteFactory
	{
	public:
		virtual ~ImageFactory();
		
		virtual Note* factory();
	};
}

#endif

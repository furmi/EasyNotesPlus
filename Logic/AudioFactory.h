//
//  AudioFactory.h
//  EasyNotePlus_julien
//
//  Created by Julien Nicolas on 12/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#ifndef EasyNotePlus_julien_AudioFactory_h
#define EasyNotePlus_julien_AudioFactory_h

#include "NoteFactory.h"

using namespace std;
//class string;

namespace EasyNote
{
	using namespace EasyNote;
	class Note;
	
	class AudioFactory:public NoteFactory
	{
	public:
		virtual ~AudioFactory();
		
		virtual Note* factory();
	};
}

#endif

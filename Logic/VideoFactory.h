//
//  VideoFactory.h
//  EasyNotePlus_julien
//
//  Created by Julien Nicolas on 12/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#ifndef EasyNotePlus_julien_VideoFactory_h
#define EasyNotePlus_julien_VideoFactory_h

#include "NoteFactory.h"

using namespace std;
//class string;

namespace EasyNote
{
	using namespace EasyNote;
	class Note;
	
	class VideoFactory:public NoteFactory
	{
	public:
		virtual ~VideoFactory();
	
		virtual Note* factory();
	};
}


#endif

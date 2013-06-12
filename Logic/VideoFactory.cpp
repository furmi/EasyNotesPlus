//
//  VideoFactory.cpp
//  EasyNotePlus_julien
//
//  Created by Julien Nicolas on 12/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#include "VideoFactory.h"
#include "Note.h"
#include "Video.h"

using namespace std;
using namespace EasyNote;

namespace EasyNote 
{
	VideoFactory::~VideoFactory()
	{
		
	}
	
	Note* VideoFactory::factory()
	{
		return new Video;
	}
}
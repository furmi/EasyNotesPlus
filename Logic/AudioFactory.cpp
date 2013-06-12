//
//  AudioFactory.cpp
//  EasyNotePlus_julien
//
//  Created by Julien Nicolas on 12/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//


#include "AudioFactory.h"
#include "Note.h"
#include "Audio.h"

using namespace std;
using namespace EasyNote;

namespace EasyNote 
{
	AudioFactory::~AudioFactory()
	{
		
	}
	
	Note* AudioFactory::factory()
	{
		return new Audio;
	}
}
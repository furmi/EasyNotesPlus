//
//  ImageFactory.cpp
//  EasyNotePlus_julien
//
//  Created by Julien Nicolas on 12/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//


#include "ImageFactory.h"
#include "Note.h"
#include "Image.h"

using namespace std;
using namespace EasyNote;

namespace EasyNote 
{
	ImageFactory::~ImageFactory()
	{
		
	}
	
	Note* ImageFactory::factory()
	{
		return new Image;
	}
}
//
//  DocumentFactory.cpp
//  EasyNotePlus_julien
//
//  Created by Julien Nicolas on 12/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#include "DocumentFactory.h"
#include "Note.h"
#include "Document.h"

using namespace std;
using namespace EasyNote;

namespace EasyNote 
{
	DocumentFactory::~DocumentFactory()
	{
		
	}

	Note* DocumentFactory::factory()
	{
		return new Document;
	}
}
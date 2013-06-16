//
//  ArticleFactory.cpp
//  EasyNotePlus_julien
//
//  Created by Julien Nicolas on 12/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#include "ArticleFactory.h"
#include "Note.h"
#include "Article.h"

using namespace std;
using namespace EasyNote;

namespace EasyNote 
{
	ArticleFactory::~ArticleFactory()
	{
		
	}
	
	Note* ArticleFactory::factory()
	{
		return new Article;
	}
}

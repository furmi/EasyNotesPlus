//
//  ArticleFactory.h
//  EasyNotePlus_julien
//
//  Created by Julien Nicolas on 12/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#ifndef EasyNotePlus_julien_ArticleFactory_h
#define EasyNotePlus_julien_ArticleFactory_h

#include "NoteFactory.h"
#include "Article.h"
#include "Note.h"
#include <QString>

using namespace std;

namespace EasyNote
{
	using namespace EasyNote;
	
	class ArticleFactory:public NoteFactory
	{
		
	public:
		virtual Note* factory();
		
		// Destructeur
		
		virtual ~ArticleFactory();
		
	};
	
}

#endif

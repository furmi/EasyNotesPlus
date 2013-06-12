//
//  Article.cpp
//  EasyNotePlus_thomas
//
//  Created by Thomas Fuhrmann on 08/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#include "Article.h"

using namespace EasyNote;

namespace EasyNote
{
    void Article::load()
    {

    }

    Article Article::operator=(const Article& a)
    {
        this->Note::operator=(a);
        text = a.text;
        return *this;
    }

    ostream& operator<<(ostream& f, const Article& a)
    {
        f<<a;
        f<<"Texte : "<<a.getText()<<"\n";
        return f;
    }

    Article::~Article() {}
}

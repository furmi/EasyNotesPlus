//
//  Document.cpp
//  EasyNotePlus_thomas
//
//  Created by Thomas Fuhrmann on 08/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#include "Document.h"

using namespace EasyNote;

namespace EasyNote
{
    Document Document::operator=(const Document& d)
    {
        this->Note::operator=(d);
        //copie de l'ensemble du contenu de d dans le document en cours
        this->notes = d.notes;
        return *this;
    }

    void Document::load()
    {

    }

    Document::~Document() {}
}


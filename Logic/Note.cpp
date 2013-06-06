//
//  Notes.cpp
//  EasyNotePlus_thomas
//
//  Created by Thomas Fuhrmann on 05/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#include "Note.h"

using namespace EasyNote;

namespace EasyNote
{
    //unsigned int Note::coefficient_timestamp = 0;

    /*int Note::getMilliCount()
    {
        timeb tb;
        ftime(&tb);
        int nCount = tb.millitm + (tb.time & 0xfffff) * 1000;
        return nCount;
    }*/

    ostream& operator<<(ostream& f, const Note& n)
    {
        f<<"ID : "<<n.getId()<<"\n";
        f<<"Titre : "<<n.getTitle()<<"\n";
        return f;
    }

    //
    /*
    ****************************************
    */
    //

    ostream& operator<<(ostream& f, const Article& a)
    {
        f<<a;
        f<<"Texte : "<<a.getText()<<"\n";
        return f;
    }
}



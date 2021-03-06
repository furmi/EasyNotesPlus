//
//  Note.cpp
//  EasyNotePlus_thomas
//
//  Created by Thomas Fuhrmann on 05/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#include "Note.h"
#include "ExportStrategy.h"

//using namespace EasyNote;

namespace EasyNote
{
	Note::~Note()
	{
	}

	ostream& operator<<(ostream& f, const Note& n)
    {
        f<<"ID : "<<n.getId()<<"\n";
        //f<<"Titre : "<<n.getTitle()<<"\n";
        return f;
    }

    Note& Note::operator=(const Note& n)
    {
        id = generateTimeStamp();
        title = n.title;
        is_Loaded = 1;
        is_Modified = 1;

		return *this;
    }

    unsigned long int Note::generateTimeStamp()
    {
        struct timeval detail_time;
        unsigned long int timeSys;
        gettimeofday(&detail_time,NULL);
        usleep(1);
        timeSys = time(0);
        timeSys = timeSys*1000+detail_time.tv_usec/1000;
        return timeSys;
    }

    QString Note::exportN(ExportStrategy* es)
    {
        QString exp = "";
        exp.append(es->header(this));
        exp.append(this->exportAsPart(es,1));
        exp.append(es->footer(this));
        return exp;
    }
}

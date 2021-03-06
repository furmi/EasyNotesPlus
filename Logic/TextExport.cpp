//
//  TextExport.cpp
//  EasyNotePlus_thomas
//
//  Created by Thomas Fuhrmann on 10/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#include "TextExport.h"

using namespace EasyNote;

namespace EasyNote
{
    //FOOTER & HEADER
    QString TextExport::header(const Note* n)
    {
        return "\nheader du l'exportNote\n";
    }

    QString TextExport::footer(const Note* n)
    {
        return "\nfooter du l'exportNote\n";
    }

    //EXPORT
    /*QString TextExport::exportNoteN(const Note* n, unsigned int titleLevel)
    {
        cout<<"dans export note\n";
        QString es = "";
        es.append(n->getTitle()+"\n");
       // es.append(exportNote(n,titleLevel)+"\n");
        es.append(footer(n));
        return es;
    }*/

    QString TextExport::exportNote(const Document* d)
    {
        QString es = "";  //retour de la m�thode
        QString tmp = "";
        list<Note*>::const_iterator it;
        for(it = d->notes.begin(); it != d->notes.end(); it++)
            cout<<"dans la boucle du doc\n";
            cout<<"avant tmp\n";
            tmp = (*it)->exportN(this);
            cout<<"apr�s tmp\n";
            //es.append(tmp);
        return es;
    }

    QString TextExport::exportNote(const Article* article, unsigned int titleLevel)
    {
        return (article->getTitle()+"\n"+article->getText());
    }
    QString TextExport::exportNote(const Audio* audio, unsigned int titleLevel)
    {
        return (audio->getTitle()+"\n"+audio->getPath()+"\n"+audio->getDescription());
    }
    QString TextExport::exportNote(const Image* image, unsigned int titleLevel)
    {
        return (image->getTitle()+"\n"+image->getPath()+"\n"+image->getDescription());
    }
    QString TextExport::exportNote(const Video* video, unsigned int titleLevel)
    {
        return (video->getTitle()+"\n"+video->getPath()+"\n"+video->getDescription());
    }

    TextExport::~TextExport() {}
}

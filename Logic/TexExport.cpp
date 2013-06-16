//
//  TexExport.cpp
//  EasyNotePlus_thomas
//
//  Created by Thomas Fuhrmann on 12/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#include "TexExport.h"

using namespace EasyNote;

namespace EasyNote
{
    //FOOTER & HEADER
    QString TexExport::header(const Note* n)
    {
        QString es = "";
        es.append("\\documentclass[a4paper,11pt]{report}\n");
        es.append("\\usepackage{graphicx}\n");
        es.append("\\usepackage[french]{babel}\n");
        es.append("\\usepackage[latin1]{inputenc}\n");
        es.append("\\usepackage[T1]{fontenc}\n");
        es.append("\\begin{document}\n");
        return es;
    }

    QString TexExport::footer(const Note* n)
    {
        return "\\end{document}";
    }

    //EXPORT
    /*QString TexExport::exportNote(const Note* n, unsigned int titleLevel)
    {
        QString es = "";
        es.append(header(n));
        es.append("\\chapter{");
        es.append(n->getTitle());
        es.append("}\n");
        es.append("\\paragraph\n");
        //es.append(n->getText());
        es.append(footer(n));
        return es;
    }*/

    QString TexExport::exportNote(const Document* d)
    {
        QString es = "";  //retour de la méthode
        list<Note*>::const_iterator it;
        for(it = d->notes.begin(); it != d->notes.end(); it++)
            //es.append(exportNote(*it,1));
        return es;
    }

    QString TexExport::exportNote(const Article* article, unsigned int titleLevel)
    {
        return ("\\paragraph{"+article->getTitle()+"}\n"+article->getText()+"\n");
    }

    QString TexExport::exportNote(const Audio* audio, unsigned int titleLevel)
    {
        return ("\\paragraph{"+audio->getTitle()+"}\n"+audio->getPath()+"\n"+"\\paragraph\n"+audio->getDescription()+"\n");
    }

    QString TexExport::exportNote(const Image* image, unsigned int titleLevel)
    {
        return ("\\paragraph{"+image->getTitle()+"}\n"+"\\begin{center}\n\\includegraphics{"+image->getPath()+"}\n\\paragraph\n"+image->getDescription()+"\n");
    }

    QString TexExport::exportNote(const Video* video, unsigned int titleLevel)
    {
        return ("\\paragraph{"+video->getTitle()+"}\n"+video->getPath()+"\n"+"\\section{niveau2}\n"+video->getDescription()+"\n");
    }

    TexExport::~TexExport() {}
}

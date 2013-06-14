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
    string TexExport::header(const Note* n)
    {
        string es = "";
        es.append("\\documentclass[a4paper,11pt]{report}\n");
        es.append("\\usepackage{graphicx}\n");
        es.append("\\usepackage[french]{babel}\n");
        es.append("\\usepackage[latin1]{inputenc}\n");
        es.append("\\usepackage[T1]{fontenc}\n");
        es.append("\\begin{document}\n");
        return es;
    }

    string TexExport::footer(const Note* n)
    {
        return "\\end{document}";
    }

    //EXPORT
    /*string TexExport::exportNote(const Note* n, unsigned int titleLevel)
    {
        string es = "";
        es.append(header(n));
        es.append("\\chapter{");
        es.append(n->getTitle());
        es.append("}\n");
        es.append("\\paragraph\n");
        //es.append(n->getText());
        es.append(footer(n));
        return es;
    }*/

    string TexExport::exportNote(const Document* d)
    {
        string es = "";  //retour de la méthode
        list<Note*>::const_iterator it;
        for(it = d->notes.begin(); it != d->notes.end(); it++)
            //es.append(exportNote(*it,1));
        return es;
    }

    string TexExport::exportNote(const Article* article, unsigned int titleLevel)
    {
        return ("\\paragraph{"+article->getTitle()+"}\n"+article->getText()+"\n");
    }

    string TexExport::exportNote(const Audio* audio, unsigned int titleLevel)
    {
        return ("\\paragraph{"+audio->getTitle()+"}\n"+audio->getPath()+"\n"+"\\paragraph\n"+audio->getDescription()+"\n");
    }

    string TexExport::exportNote(const Image* image, unsigned int titleLevel)
    {
        return ("\\paragraph{"+image->getTitle()+"}\n"+"\\begin{center}\n\\includegraphics{"+image->getPath()+"}\n\\paragraph\n"+image->getDescription()+"\n");
    }

    string TexExport::exportNote(const Video* video, unsigned int titleLevel)
    {
        return ("\\paragraph{"+video->getTitle()+"}\n"+video->getPath()+"\n"+"\\section{niveau2}\n"+video->getDescription()+"\n");
    }

    TexExport::~TexExport() {}
}

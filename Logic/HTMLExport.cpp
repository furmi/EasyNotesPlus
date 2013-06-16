//
//  HTMLExport.cpp
//  EasyNotePlus_thomas
//
//  Created by Thomas Fuhrmann on 13/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#include "HTMLExport.h"

using namespace EasyNote;

namespace EasyNote
{
    //FOOTER & HEADER
    QString HTMLExport::header(const Note* n)
    {
        QString es = "";
        es.append("<html>\n");
        es.append("<head>\n");
        es.append("<meta charset=""utf-8"">\n");
        es.append("</head>\n");
        es.append("<body>\n");
        return es;
    }

    QString HTMLExport::footer(const Note* n)
    {
        return "</body>\n</html>";
    }

    //EXPORT
    /*QString HTMLExport::exportNote(const Note* n, unsigned int titleLevel)
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

    QString HTMLExport::exportNote(const Document* d)
    {
        QString es = "";  //retour de la méthode
        list<Note*>::const_iterator it;
        for(it = d->notes.begin(); it != d->notes.end(); it++)
            //es.append(exportNote(*it,1));
        return es;
    }

    QString HTMLExport::exportNote(const Article* article, unsigned int titleLevel)
    {
        //conversion de titleLevel en QString

        QString titre = QString::number(titleLevel);

        QString es = "";
        //balise pour le titre
        es.append("<h"+titre+">\n");
        //ajout du titre
        es.append(article->getTitle()+"\n");
        //fermeture de la balise de titre
        es.append("</h"+titre+">\n");
        //contenu du paragraphe
        es.append("<p>\n"+article->getText()+"\n</p>\n");
        return es;
    }

    QString HTMLExport::exportNote(const Audio* audio, unsigned int titleLevel)
    {
        //conversion de titleLevel en string

        QString titre = QString::number(titleLevel);

        QString es = "";
        //balise pour le titre
        es.append("<h"+titre+">\n");
        //ajout du titre
        es.append(audio->getTitle());
        //fermeture de la balise de titre
        es.append("</h"+titre+">\n");
        //ajout du fichier audio
        es.append("<audio controls>\n");
        es.append("<source src="+audio->getPath()+" />\n");
        es.append("</audio>\n");
        //contenu du paragraphe
        es.append("<p>\n"+audio->getDescription()+"\n</p>\n");
        return es;
    }

    QString HTMLExport::exportNote(const Image* image, unsigned int titleLevel)
    {
        //conversion de titleLevel en string

        QString titre = QString::number(titleLevel);

        QString es = "";
        //balise pour le titre
        es.append("<h"+titre+">\n");
        //ajout du titre
        es.append(image->getTitle());
        //fermeture de la balise de titre
        es.append("</h"+titre+">\n");
        //ajout du fichier image
        es.append("<img src="+image->getPath()+" title="+image->getTitle()+" alt="+image->getDescription()+" />\n");
        //fermeture de la balise de titre
        es.append("</h"+titre+">\n");
        return es;
    }

    QString HTMLExport::exportNote(const Video* video, unsigned int titleLevel)
    {
        //conversion de titleLevel en string

        QString titre = QString::number(titleLevel);

        QString es = "";
        //balise pour le titre
        es.append("<h"+titre+">");
        //ajout du titre
        es.append(video->getTitle());
        //fermeture de la balise de titre
        es.append("</h"+titre+">\n");
        //ajout du fichier video
        es.append("<video controls>\n");
        es.append("<source src="+video->getPath()+" />\n");
        es.append("</video>\n");
        //contenu du paragraphe
        es.append("<p>\n"+video->getDescription()+"\n</p>\n");
        //fermeture de la balise de titre
        es.append("</h"+titre+">\n");
        return es;
    }

    HTMLExport::~HTMLExport() {}
}

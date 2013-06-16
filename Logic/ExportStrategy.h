//
//  ExportStrategy.h
//  EasyNotePlus_thomas
//
//  Created by Thomas Fuhrmann on 10/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#ifndef EasyNotePlus_thomas_ExportStrategy_h
#define EasyNotePlus_thomas_ExportStrategy_h

#include "Note.h"
#include "Document.h"
#include "Article.h"
#include "Video.h"
#include "Audio.h"
#include "Image.h"
#include<map>

/** \class ExportStrategy
*
*   Classe abstraite qui donne le corps des stratgey d'export.
*/

using namespace EasyNote;

// Références

//class Note;

namespace EasyNote
{
    class ExportStrategy
    /**
	*	\class ExportStrategy : \brief Classe abstraite d'export
	*/
    {
    // Attributes

    //METHODES
    public:

    // CONSTRUCTEURS / DESTRUCTEURS
        ExportStrategy() {}
        virtual ~ExportStrategy();

    //EXPORT
        //virtual QString exportNoteN(const Note* n, unsigned int titleLevel);  //permet d'exporter une note en entier
        virtual QString exportNote(const Document* d) = 0;   //permet d'exporter un document
        virtual QString exportNote(const Article* n, unsigned int titleLevel) = 0;  //permet d'exporter un article
        virtual QString exportNote(const Image* n, unsigned int titleLevel) = 0;  //permet d'exporter une image
        virtual QString exportNote(const Audio* n, unsigned int titleLevel) = 0;  //permet d'exporter un son
        virtual QString exportNote(const Video* n, unsigned int titleLevel) = 0;  //permet d'exporter une vidéo

    //FOOTER & HEADER
        virtual QString header(const Note* n) = 0;
        virtual QString footer(const Note* n) = 0;

    //GETTER
        static map<QString, ExportStrategy*> getStrategies();
    };
}

#endif

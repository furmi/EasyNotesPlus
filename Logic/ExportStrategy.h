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
        //virtual string exportNoteN(const Note* n, unsigned int titleLevel);  //permet d'exporter une note en entier
        virtual string exportNote(const Document* d) = 0;   //permet d'exporter un document
        virtual string exportNote(const Article* n, unsigned int titleLevel) = 0;  //permet d'exporter un article
        virtual string exportNote(const Image* n, unsigned int titleLevel) = 0;  //permet d'exporter une image
        virtual string exportNote(const Audio* n, unsigned int titleLevel) = 0;  //permet d'exporter un son
        virtual string exportNote(const Video* n, unsigned int titleLevel) = 0;  //permet d'exporter une vidéo

    //FOOTER & HEADER
        virtual string header(const Note* n) = 0;
        virtual string footer(const Note* n) = 0;

    //GETTER
        static map<string, ExportStrategy*> getStrategies();
    };
}

#endif

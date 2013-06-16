//
//  HTMLExport.h
//  EasyNotePlus_thomas
//
//  Created by Thomas Fuhrmann on 13/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#ifndef EasyNotePlus_thomas_HTMLExport_h
#define EasyNotePlus_thomas_HTMLExport_h

#include "Note.h"
#include "Document.h"
#include "Article.h"
#include "Audio.h"
#include "Image.h"
#include "Video.h"
#include<map>
#include<list>
#include<QString>
#include "ExportStrategy.h"
#include <sstream>

/** \class HTMLExport
*
*   Sous classe de la classe ExportStrategy
*   Permet d'exporter une note sous format HTML
*/

using namespace EasyNote;

// Références

//class Note;

namespace EasyNote
{
    class HTMLExport : public ExportStrategy
    /**
	*	\class HTMLExport : \brief Classe permettant l'export d'une note au format HTML.
	*/
    {
    // Attributes

    //METHODES
    public:
    // CONSTRUCTEURS / DESTRUCTEURS
        HTMLExport() {}
        virtual ~HTMLExport();

    //EXPORT
        //virtual QString exportNote(const Note* n, unsigned int titleLevel);
        virtual QString exportNote(const Article* article, unsigned int titleLevel);
        virtual QString exportNote(const Audio* audio, unsigned int titleLevel);
        virtual QString exportNote(const Image* image, unsigned int titleLevel);
        virtual QString exportNote(const Video* video, unsigned int titleLevel);
        virtual QString exportNote(const Document* d);

    //FOOTER & HEADER
        virtual QString header(const Note* n);
        virtual QString footer(const Note* n);
    };
}

#endif

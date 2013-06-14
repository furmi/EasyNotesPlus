//
//  TextExport.h
//  EasyNotePlus_thomas
//
//  Created by Thomas Fuhrmann on 10/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#ifndef EasyNotePlus_thomas_TextExport_h
#define EasyNotePlus_thomas_TextExport_h

#include "Note.h"
#include "Document.h"
#include "Article.h"
#include "Video.h"
#include "Audio.h"
#include "Image.h"
#include<map>
#include<list>
#include<string>
#include "ExportStrategy.h"

/** \class TextExport
*
*   Sous classe de la classe ExportStrategy
*   Permet d'exporter une note sous format texte.
*/

using namespace EasyNote;

// Références

//class Note;

namespace EasyNote
{
    class TextExport : public ExportStrategy
    /**
	*	\class TextExport : \brief Classe permettant l'export d'une note au format texte.
	*/
    {
    // Attributes

    //METHODES
    public:
    // CONSTRUCTEURS / DESTRUCTEURS
        TextExport() {}
        virtual ~TextExport();

    //EXPORT
        //virtual string exportNoteN(const Note* n, unsigned int titleLevel);
        virtual string exportNote(const Article* article, unsigned int titleLevel);
        virtual string exportNote(const Audio* audio, unsigned int titleLevel);
        virtual string exportNote(const Image* image, unsigned int titleLevel);
        virtual string exportNote(const Video* video, unsigned int titleLevel);
        virtual string exportNote(const Document* d);

    //FOOTER & HEADER
        virtual string header(const Note* n);
        virtual string footer(const Note* n);
    };
}

#endif

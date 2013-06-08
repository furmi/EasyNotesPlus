//
//  Document.h
//  EasyNotePlus_thomas
//
//  Created by Thomas Fuhrmann on 08/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#ifndef EasyNotePlus_thomas_Document_h
#define EasyNotePlus_thomas_Document_h

#include "Note.h"
#include <list>

/** \class Document
*
*   Classe permet d'instancier des objets de type Document.
*   Cette classe est la sous-classe de la classe Note.
*   Un document est composé de plusieurs Note (quelque que soit leur type).
*/

using namespace EasyNote;

// Références

class ExportStrategy;
class Note;

namespace EasyNote
{
    class Document : public Note
    /**
	*	\class Document : \brief Classe fille de Note, gère des documents.
	*/
    {
    // Attributes
    public:
        list<Note*> notes;

    //METHODES

    // CONSTRUCTEURS / DESTRUCTEURS
        Document():Note(),notes(0) {}
        Document(const string& titre):Note(titre), notes(0) {}
        Document(const Document& d):Note(d), notes(d.notes) {}
        Document operator=(const Document&);
        virtual ~Document() {}

    // LOAD
        void load();
    };
}

#endif



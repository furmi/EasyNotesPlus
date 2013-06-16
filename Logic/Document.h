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

using namespace std;

// Références

//class ExportStrategy;
//class Note;

namespace EasyNote
{
    class Document : public Note
    /**
	*	\class Document : \brief Classe fille de Note, gère des documents.
	*/
    {
    friend class NotesManager;
    // Attributes
    public:
        list<Note*> notes;

    //METHODES

    // CONSTRUCTEURS / DESTRUCTEURS
        Document():Note(),notes(0) {}
        Document(const QString& titre):Note(titre), notes(0) {}
        Document(const Document& d):Note(d), notes(d.notes) {}
        Document operator=(const Document&);
        virtual ~Document();

    // LOAD / SAVE
	private:
	virtual void load();
        virtual void save();

        virtual QString exportAsPart(ExportStrategy* es, unsigned int titleLevel);
    };
}

#endif

//
//  Article.h
//  EasyNotePlus_thomas
//
//  Created by Thomas Fuhrmann on 08/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#ifndef EasyNotePlus_thomas_Article_h
#define EasyNotePlus_thomas_Article_h
#include "Note.h"

/** \class Article
*
*   Classe permet d'instancier des objets de type Article.
*   Cette classe est la sous-classe de la classe Note
*/

using namespace std;
//using namespace EasyNote;

// Références
friend class NotesManager;

//class ExportStrategy;
//class Note;

namespace EasyNote
{
    class Article : public Note
    /**
	*	\class Article : \brief Classe fille de Note, gère des articles.
	*/
    {
    // Attributes

	QString text;

    //METHODES

    public:

    // CONSTRUCTEURS / DESTRUCTEURS
        Article():Note(),text("") {}
        Article(const QString& titre,const QString& texte):Note(titre), text(texte) {}
        Article(const Article& a):Note(a), text(a.getText()) {}
        Article operator=(const Article&);
        virtual ~Article();

	 // GETTERS
        const QString& getText() const {return text;}

	 // SETTERS

        void setText(const QString& newText) {text = newText; is_Modified = 1;}

    private:
        //friend class NotesManager;
    // LOAD / SAVE
        virtual void load();
        virtual void save();

    // EXPORT

        virtual QString exportAsPart(ExportStrategy* es, unsigned int titleLevel);
    };
}

#endif

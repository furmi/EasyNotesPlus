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

	string text;

    //METHODES

    public:

    // CONSTRUCTEURS / DESTRUCTEURS
        Article():Note(),text("") {}
        Article(const string& titre,const string& texte):Note(titre), text(texte) {}
        Article(const Article& a):Note(a), text(a.getText()) {}
        Article operator=(const Article&);
        virtual ~Article();

	 // GETTERS
        const string& getText() const {return text;}

	 // SETTERS

        void setText(const string& newText) {text = newText; is_Modified = 1;}

    // LOAD / SAVE
        void load();
        void save();

    // EXPORT

        virtual string exportAsPart(ExportStrategy* es, unsigned int titleLevel);
    };
}

#endif

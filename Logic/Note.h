//
//  Notes.h
//  EasyNotePlus_thomas
//
//  Created by Thomas Fuhrmann on 05/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#ifndef EasyNotePlus_thomas_Notes_h
#define EasyNotePlus_thomas_Notes_h
#include <string>
#include <iostream>
#include <ctime>

/** \class Notes
*
*   Classe abstraite qui donne la structure de base de l'ensemble des objets à gérer.
*   Cette classe est la super classe de Article, Document et Media.
*   Elle possède une unique méthode virtuelle pure : load.
*/

using namespace std;

// Références

class ExportStrategy;

namespace EasyNote
{
    class Note
    /**
	*	\class Note : \brief super-classe abstraite de tous les objets gérés.
	*/
    {
    // ATTRIBUTES
    protected:
        string title;
        bool isLoaded;
        bool isModified;
    private:
        unsigned int id;
        //static unsigned int coefficient_timestamp;

    //METHODES

    public:

        //static int getMilliCount();

    // CONSTRUCTEURS / DESTRUCTEURS
                //de base l'attribut isModified est à 1 pour prendre en charge la sauvegarde à la création
        Note():title(0),isLoaded(0),isModified(1),id(time(0)-100000000) {}
        Note(const Note& n):title(n.getTitle()),isLoaded(0),isModified(1),id(time(0)+10000000) {}
        Note operator=(const Note&);
        Note(const string& titre):title(titre),isLoaded(0),isModified(1),id(time(0)-100000000) {}
        virtual ~Note() {}

	 // GETTERS
        const unsigned int getId() const {return id;}
        const string& getTitle() const {return title;}

	 // SETTERS

        void setTitle(const string& newTitle) {title = newTitle;}

        //Export
    /**
	 * \fn export: \brief Exporte une note.
	 */
//        string export (const ExportStrategy* es);

    protected:
    /**
	 * \fn load: \brief Charge une note (virtuelle pure)
	 */
//        virtual void load() = 0;

    /**
	 * \fn exportAsPart: \brief Charge une note par parties
	 */

        string exportAsPart(ExportStrategy* es, unsigned int titleLevel);
    };

    ostream& operator<<(ostream& f, const Note& n);


//
//
/*
********************************************************************************
*/
//
//

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
        Article():Note(),text(0) {}
        Article(const string& titre,const string& texte):Note(titre), text(texte) {}
        Article(const Article& a):Note(a), text(a.getText()) {}
        Article operator=(const Article&);
        virtual ~Article() {}

	 // GETTERS
        const string& getText() const {return text;}

	 // SETTERS

        void setText(const string& newText) {text = newText;}

    // LOAD
        void load();

    };
}

#endif

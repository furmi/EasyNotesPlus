//
//  Media.h
//  EasyNotePlus_thomas
//
//  Created by Thomas Fuhrmann on 08/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#ifndef EasyNotePlus_thomas_Media_h
#define EasyNotePlus_thomas_Media_h

#include "Note.h"
#include <string>

/** \class Media
*
*   Classe abstraite qui donne la structure des fichiers média (vidéo, image, son).
*   Cette classe est la sous-classe de la classe Note.
*   Cette classe est la super-classe des classes Image, Video et Audio.
*/

using namespace EasyNote;
using namespace std;

// Références

class ExportStrategy;
//class Note;

namespace EasyNote
{
    class Media :public Note
    /**
	*	\class Media : \brief Classe fille de Note, abstraite, donne la structure des médias.
	*/
    {
    // Attributes
    protected:
        /**
        *	\var description: \brief attribut contenant la description du média
        */
		string description;
        /**
        *	\var path: \brief attribut contenant le chemin du média
        */
        string path;

    //METHODES
    public:

    // CONSTRUCTEURS / DESTRUCTEURS
        Media():Note(),description(""), path("") {}
        Media(const string& titre, const string& desc):Note(titre), description(desc), path("") {}
        Media(const  string& titre, const  string& desc, const  string& chemin):Note(titre), description(desc), path(chemin) {}
        Media(const Media& m):Note(m), description(m.getDescription()), path(m.getPath()) {}
        Media operator=(const Media&);
        virtual ~Media();

    // GETTERS
        const string& getDescription() const {return description;}
        const string& getPath() const {return path;}

	// SETTERS

        void setDescription(const string& newText) {description = newText;}
        void setPath(const string& newPath) {path = newPath;}

    // LOAD
    protected:
        void load();
    };
}

#endif

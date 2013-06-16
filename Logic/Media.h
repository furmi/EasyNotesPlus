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
#include <QString>

/** \class Media
*
*   Classe abstraite qui donne la structure des fichiers média (vidéo, image, son).
*   Cette classe est la sous-classe de la classe Note.
*   Cette classe est la super-classe des classes Image, Video et Audio.
*/

using namespace std;

// Références
friend class NotesManager;
class ExportStrategy;

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
		QString description;
        /**
        *	\var path: \brief attribut contenant le chemin du média
        */
        QString path;

    //METHODES
    public:

    // CONSTRUCTEURS / DESTRUCTEURS
        Media():description(""), path("") {}
        Media(const QString& titre, const QString& desc):Note(titre), description(desc), path("") {}
        Media(const  QString& titre, const  QString& desc, const  QString& chemin):Note(titre), description(desc), path(chemin) {}
        Media(const Media& m):Note(m), description(m.getDescription()), path(m.getPath()) {}
//        Media operator=(const Media&);
        virtual ~Media();

    // GETTERS
        const QString& getDescription() const {return description;}
        const QString& getPath() const {return path;}

	// SETTERS

        void setDescription(const QString& newText) {description = newText;}
        void setPath(const QString& newPath) {path = newPath;}

        virtual QString exportAsPart(ExportStrategy* es, unsigned int titleLevel) = 0;

    // LOAD / SAVE
    protected:
        void load();
        void save();
    };
}

#endif

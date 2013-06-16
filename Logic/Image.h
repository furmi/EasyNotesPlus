//
//  Image.h
//  EasyNotePlus_thomas
//
//  Created by Thomas Fuhrmann on 08/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#ifndef EasyNotePlus_thomas_Image_h
#define EasyNotePlus_thomas_Image_h

#include "Media.h"

/** \class Image
*
*   Classe qui instancie des images sous forme binaire.
*   Cette classe est la sous-classe de la classe Media.
*/

//using namespace EasyNote;
using namespace std;

// Références


//class ExportStrategy;
//class Note;

namespace EasyNote
{
    class Image : public Media
    /**
	*	\class Image : \brief Classe fille de Media, instancie des images.
	*/
    {
    friend class NotesManager;
    // Attributes

    //METHODES
    public:

    // CONSTRUCTEURS / DESTRUCTEURS
        Image() {}
        Image(const QString& titre, const QString& desc):Media(titre,desc) {}
        Image(const QString& titre, const QString& desc, const QString& chemin):Media(titre,desc,chemin) {}
        Image(const Image& i):Media(i) {}
        Image operator=(const Image&);
        virtual ~Image();

        virtual QString exportAsPart(ExportStrategy* es, unsigned int titleLevel);

    //Surcharge de la fonction save() pour ajouter la Note au fichier de description du NoteManager
    protected:
        void save();
    };
}

#endif

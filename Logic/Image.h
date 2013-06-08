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

using namespace EasyNote;

// R�f�rences

class ExportStrategy;
class Note;

namespace EasyNote
{
    class Image : public Media
    /**
	*	\class Image : \brief Classe fille de Media, instancie des images.
	*/
    {
    // Attributes

    //METHODES
    public:

    // CONSTRUCTEURS / DESTRUCTEURS
        Image():Media() {}
        Image(const string& titre, const string& desc):Media(titre,desc) {}
        Image(const string& titre, const string& desc, const string& chemin):Media(titre,desc,chemin) {}
        Image(const Image& i):Media(i) {}
        Image operator=(const Image&);
        virtual ~Image() {}
    };
}

#endif

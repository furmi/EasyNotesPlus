//
//  Video.h
//  EasyNotePlus_thomas
//
//  Created by Thomas Fuhrmann on 08/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#ifndef EasyNotePlus_thomas_Video_h
#define EasyNotePlus_thomas_Video_h

#include <QString>
#include "Media.h"

/** \class Video
*
*   Classe qui instancie des vidéos sous forme binaire.
*   Cette classe est la sous-classe de la classe Media.
*/

using namespace std;


// Références
friend class NotesManager;

//class ExportStrategy;
//class Note;

namespace EasyNote
{
	using namespace EasyNote;

    class Video : public Media
    /**
	*	\class Video : \brief Classe fille de Media, instancie des vidéos.
	*/
    {
    // Attributes

    //METHODES
    public:

    // CONSTRUCTEURS / DESTRUCTEURS
        Video() {}
        Video(const  QString& titre, const  QString& desc):Media(titre,desc) {}
        Video(const  QString& titre, const  QString& desc, const  QString& chemin):Media(titre,desc,chemin) {}
        Video(const Video& i):Media(i) {}
        Video operator=(const Video&);
        virtual ~Video();

        virtual QString exportAsPart(ExportStrategy* es, unsigned int titleLevel);

    //Surcharge de la fonction save() pour ajouter la Note au fichier de description du NoteManager
    protected:
        void save();
    };
}

#endif

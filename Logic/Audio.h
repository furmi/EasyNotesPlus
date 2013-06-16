//
//  Audio.h
//  EasyNotePlus_thomas
//
//  Created by Thomas Fuhrmann on 08/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#ifndef EasyNotePlus_thomas_Audio_h
#define EasyNotePlus_thomas_Audio_h

#include "Media.h"

/** \class Audio
*
*   Classe qui instancie des sons sous forme binaire.
*   Cette classe est la sous-classe de la classe Media.
*/

//using namespace EasyNote;
using namespace std;

// Références
friend class NotesManager;

//class ExportStrategy;
//class Note;

namespace EasyNote
{
    class Audio : public Media
    /**
	*	\class Audio : \brief Classe fille de Media, instancie des fichiers audios.
	*/
    {
    // Attributes

    //METHODES
    public:

    // CONSTRUCTEURS / DESTRUCTEURS
        Audio() {}
        Audio(const string& titre, const string& desc):Media(titre,desc) {}
        Audio(const string& titre, const string& desc, const string& chemin):Media(titre,desc,chemin) {}
        Audio(const Audio& i):Media(i) {}
        Audio operator=(const Audio&);
        virtual ~Audio();

        virtual string exportAsPart(ExportStrategy* es, unsigned int titleLevel);

    //Surcharge de la fonction save() pour ajouter la Note au fichier de description du NoteManager
    protected:
        void save();
    };
}

#endif

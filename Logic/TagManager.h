//
//  TagManager.h
//  EasyNotePlus_thomas
//
//  Created by Thomas Fuhrmann on 16/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#ifndef EasyNotePlus_thomas_TagManager_h
#define EasyNotePlus_thomas_TagManager_h
#include <map>
#include <set>
#include <QString>
#include "Note.h"

/** \class TagManager
*
*   Classe permet la gestion des Tags.
*/

using namespace std;

// Références

namespace EasyNote
{
    class TagManager
    /**
	*	\class TagManager : \brief Classe qui permet de gérer les tags.
	*/
    {
    // Attributes

        static TagManager* instance;
        map<Note*,set<QString> > assoc; //map<ID_Note,vector<tags>> liste des associations
        set<QString> tags;   //liste des tags


    //METHODES

        // CONSTRUCTEURS / DESTRUCTEURS
        TagManager();
        TagManager(const TagManager& tm);
        TagManager operator=(const TagManager& tm);
        ~TagManager();

        // SINGLETON
    public:
        /**
        *	\fn getInstance: \brief retourne l'instance
        */

        static TagManager* getInstance ();

        /**
         * \fn releaseInstance: \brief Supprimme le singleton
         */

        static void releaseInstance();

        // Gestion des tags
        void addTag(Note* n, const QString& tag); //permet d'ajouter un tag à une note
        void removeTag(Note* n, const QString& tag);  //permet de supprimer une association tag/note
        void removeTag(const QString& tag); //permet de supprimer un tag (supprime toutes les associations tag/note

        //Recherche
        set<Note*> searchNote(set<QString>);  //search = OU entre les tags
        set<Note*> filterNote(set<QString>);   //filtre = ET entre les tags
    };
}

#endif

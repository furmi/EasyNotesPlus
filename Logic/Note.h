//
//  Note.h
//  EasyNotePlus_thomas
//
//  Created by Thomas Fuhrmann on 05/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#ifndef EasyNotePlus_thomas_Note_h
#define EasyNotePlus_thomas_Note_h
#include <string>
#include <iostream>
#include <ctime>
#include <sys/time.h>
#include <unistd.h>

/** \class Note
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
        bool is_Loaded;
        bool is_Modified;
    private:
        unsigned long int id;

    //METHODES

    public:
    /**
	 * \fn generateTimeStamp: \brief Permet de générer un ID unique
	 */
        static unsigned long int generateTimeStamp();

    // CONSTRUCTEURS / DESTRUCTEURS
                //de base l'attribut isModified est à 1 pour prendre en charge la sauvegarde à la création
        Note():title(0),is_Loaded(1),is_Modified(1),id(generateTimeStamp()) {}
        Note(const Note& n):title(n.getTitle()),is_Loaded(1),is_Modified(1),id(generateTimeStamp()) {}
        Note operator=(const Note&);
        Note(const string& titre):title(titre),is_Loaded(1),is_Modified(1),id(generateTimeStamp()) {}
        virtual ~Note();

	 // GETTERS
        const unsigned long int getId() const {return id;}
        const string& getTitle() const {return title;}
        const bool isModified() const {return is_Modified;}
        const bool isLoaded() const {return is_Loaded;}

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
}

#endif

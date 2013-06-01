//
//  NotesManager.h
//  EasyNotePlus_julien
//
//  Created by Julien Nicolas on 31/05/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#ifndef EasyNotePlus_julien_NotesManager_h
#define EasyNotePlus_julien_NotesManager_h
#include <set>
#include <map>
#include <string> // Temporaire, j'inclus Qt une fois que j'ai implémenté qqs trucs 

/** \class NotesManager
*
*	Permet la gestion de toutes les notes de l'application.
*	Elle permet notamment la création et la destruction des notes.
*	Cette classe est un singleton.
*/

using namespace std;

// Références

class Note;
class NoteFactory;
class ExportStrategy;



namespace EasyNote
{
// Classe : au passage il manque des choses sur les factories, si on veut les obtenir par exemple

class NotesManager
{
public:
	
	 // GETTERS
	
	/**
	*	\fn getInstance: \brief retourne l'instance  
	*/
	
	static NotesManager* getInstance ();
	
	
	/**
	*
	*/
	
	const string getPath () const {return this->path;}
	
	 // SETTERS
	 
	void setPath (string& path_){this->path = path_;}
	 
	 
	 // DIVERS
	 
	/**
	 * \fn releaseInstance: \brief Supprimme le singleton
	 */
	
	static void releaseInstance();
	
	/**
	*	\fn load : \brief charge la note en mémoire vive.
	*/
	
	//void load();	Décommenter dès que notes ou un de ses classes filles est implémentée
	
private:
	class NotesIterator;	// Itérateur non constant
	class ConstNotesIterator;	// Itérateur constant
	
public:
	// Méthode de NotesManager permettant d'obtenir l'itérateur
	
	NotesIterator begin ();
	NotesIterator end ();
		
private:
	// MÉTHODES PRIVÉES

	/** 
	 *	Constructeurs/Destructeur
	 */
	
	NotesManager();
	NotesManager(const NotesManager& noteMan);
	~NotesManager();
	
	/**
	*	Opérateur d'affectation
	*/
	
	NotesManager& operator=(const NotesManager&);
	
	
	// ATTRIBUTS
	
	/**
	*	\var instance: \brief attribut contenant l'instance du singleton
	*/
	
	static NotesManager* instance;
	
	/**
	*	\var notes: \brief ensemble de pointeur de notes, contient toutes les notes en mémoire.
	*/
	
	set<Note*> notes;
	
	/**
	*	\var path: \brief chemin absolu du répertoire de sauvegarde (je pensais mettre le répertoire courant au départ)
	*/
	
	string path;
	
	/**
	*	\var factories: \brief tableau associatif contenant toutes les "usines de fabrication" (design pattern factory method)
	*	\brief  permettant de fabriquer les différents types de notes
	*/
	
	map<string,NoteFactory*> factories;
	
	/**
	*	\var strategies: \brief tableau associatif contenant toutes les stratégies d'exportation d'une note.
	*/
	
	map<string,ExportStrategy*> strategies;
	
	// CLASSES
	
};

}



#endif

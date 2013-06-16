//
//  TagManager.cpp
//  EasyNotePlus_thomas
//
//  Created by Thomas Fuhrmann on 16/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#include "TagManager.h"

using namespace EasyNote;

namespace EasyNote
{
    // Initialisation de l'attribut statique

	TagManager* TagManager::instance = 0;

		// CONSTRUCTEURS/DESTRUCTEURS

	TagManager::TagManager():assoc(),tags(){}

	TagManager::~TagManager ()
	{
		// Destruction du TagManager

		releaseInstance();
	}

    // MÉTHODES STATIQUES

	TagManager* TagManager::getInstance()
	{
		if (instance == 0)
			instance = new TagManager;

		return TagManager::instance;
	}

	void TagManager::releaseInstance()
	{
		if (instance != 0)
			delete instance;
	}

	// Gestion des tags
    void TagManager::addTag(Note* n, const QString& tag)
    {
        map<Note*,set<QString> >::iterator itMap;
        itMap = assoc.find(n);  //on recherche si la note existe
        if(itMap == assoc.end())   //la note n'existe pas, on la rajoute
        {
            set<QString> tmp;
            tmp.insert(tag);
            assoc.insert(pair<Note*,set<QString> >(n,tmp));
            tags.insert(tag);   //on ajoute le Tag à la liste des Tags du TagManager
        }
        else    //la note existe, on cherche si le tag existe
        {
            set<QString>::iterator itTag;
            itTag = itMap->second.find(tag);   //on recherche le tag dans la note correspondante
            if(itTag == itMap->second.end())   //le tag n'existe pas encore
            {
                itMap->second.insert(tag);     //on ajoute le tag
                tags.insert(tag);   //on ajoute le Tag à la liste des Tags du TagManager
            }
        }
    }

    void TagManager::removeTag(Note* n, const QString& tag)
    {
        map<Note*,set<QString> >::iterator itMap;
        itMap = assoc.find(n);  //on recherche si la note existe
        if(itMap != assoc.end())   //la note n'existe pas, on la rajoute
        {
            set<QString>::iterator itTag;
            itTag = itMap->second.find(tag);   //on recherche le tag dans la note correspondante
            if(itTag != itMap->second.end())   //le tag n'existe pas encore
            {
                itMap->second.erase(tag);     //on ajoute le tag
            }
        }
    }

    void TagManager::removeTag(const QString& tag)
    {
        map<Note*,set<QString> >::iterator itMap;
        for(itMap = assoc.begin(); itMap != assoc.end(); itMap++)   //on parvourt la liste de Note et on supprime le tag
            removeTag((*itMap).first, tag);
        tags.erase(tag);    //on supprime le tag de la liste de tag du TagManager
    }

    //Recherche
    set<Note*> TagManager::searchNote(set<QString> tags)  //OU entre les tags
    {
        map<Note*,set<QString> >::iterator itMap; //parcourt des notes
        set<Note*> ret; //set de retour avec la liste des notes
        set<QString>::iterator itTag;    //permet la recherche dans le set
        set<QString>::iterator itParam;  //permet de parcourir le set de tags envoyé en paramètre
        for(itMap = assoc.begin(); itMap != assoc.end(); itMap++)
        {
            for(itParam = tags.begin(); itParam != tags.end(); itParam++)
            {
                itTag = itMap->second.find(*itParam);
                if(itTag != itMap->second.end())   //le tag existe
                {
                    ret.insert((*itMap).first); //on ajoute la note à la liste de retour
                }
            }
        }
        return ret;
    }

    set<Note*> TagManager::filterNote(set<QString> tags)  //ET entre les tags
    /* Fonctionnement :
    Pour chaque Tag de tags, on recherche l'ensemble des notes correspondantes (via serachNote).
    On travail sur 2 set : old et current. Pour chaque pas de la boucle, on a dans current le set de note
    qui correspond au tag courant. Old est une mémoire du pas d'avant.
    A chaque pas on fait l'intersection entre les éléments de old et de current et on sauvegarde
    le résultat dans old. Cela permet, une fois tous les tags parcouru, de renvoyer le set de note
    où on aura un ET entre les tags.
    */
    {
        set<Note*> tmp; //set temporaire pour les opérations d'intersection
        set<Note*> old; //set désignant la mémoire de parcourt
        set<Note*>::iterator itold; //iterator sur old
        set<Note*> current; //set contenant la liste actuelle de note
        set<Note*>::iterator itcurrent; //iterator sur current
        set<QString>::iterator ittags;   //iterator sur tags passé en paramètre
        set<QString> param;  //

        ittags = tags.begin();
        param.insert(*ittags);
        //cout<<"Parametre (1er tag) "<<(*(param.begin()))<<endl;
        old = this->searchNote(param);  //liste des note qui ont le premier tag
        if (tags.size() == 1)
            return old; //si on a qu'un seul tag, la méthode renvoit la liste du tag
        else
        {
            ittags++;   //on commence au deuxième élément comme on a déjà récupéré le premier
            for(ittags; ittags != tags.end(); ittags++)  //on parcourt la liste des tags
            {
                //on récupère la liste de note associé au tag courant
                param.clear();
                param.insert(*ittags);
                current = this->searchNote(param);
                //on fait l'intersection entre current et old
                for(itold = old.begin(); itold != old.end(); itold++)   //boucle sur old
                {
                    for(itcurrent = current.begin(); itcurrent != current.end(); itcurrent++)   //boucle sur current
                    {
                        if((*itold) == (*itcurrent))   //la note se trouve dans les deux sets
                        {
                            tmp.insert((*itold)); //on ajoute la note à la liste de retour
                        }
                    }
                }
                old = tmp;  //on met à jour la "mémoire" de parcourt qui coutient l'intersection des deux set
            }
            return old;
        }
    }
}//fin du namespace

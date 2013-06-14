//
//  Document.cpp
//  EasyNotePlus_thomas
//
//  Created by Thomas Fuhrmann on 08/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#include "Document.h"
#include "ExportStrategy.h"

using namespace EasyNote;

namespace EasyNote
{
    Document Document::operator=(const Document& d)
    {
        this->Note::operator=(d);
        //copie de l'ensemble du contenu de d dans le document en cours
        this->notes = d.notes;
        return *this;
    }

void Document::load()
    {
        if (!this->isLoaded())   //permet de tester si la note est déjà chargée
        {
            list<Note*>::iterator it;
            for(it = this->notes.begin(); it != this->notes.end(); it++)
                //*it->load();
            this->is_Loaded = 1; //signifie que le fichier est chargé
            this->is_Modified = 0;
        }
    }

    void Document::save()
    {
        if(this->isModified())  //permet de tester si la note a été modifiée
        {
            list<Note*>::iterator it;
            for(it = this->notes.begin(); it != this->notes.end(); it++)
                //*it->save();
            this->is_Modified = 0;
        }
    }

    string Document::exportAsPart(ExportStrategy* es, unsigned int titleLevel)
    {
        string exp = "";
        cout<<"arrivé dans ExportAsPart Document\n";
        list<Note*>::iterator it;
        for(it = this->notes.begin(); it != this->notes.end(); it++)
            cout<<"dans la boucle du doc\n";
            cout<<"avant tmp\n";
//            exp = exp + es->exportNote(*it,++titleLevel);
            cout<<"après tmp\n";
            //es.append(tmp);
        return exp;
    }

    Document::~Document() {}
}

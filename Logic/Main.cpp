//
//  Main.cpp
//  EasyNotePlus_julien
//
//  Created by Julien Nicolas on 31/05/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#include <iostream>
#include "NotesManager.h"


using namespace std;
using namespace EasyNote;

int main (int argc,char* argv[])
{
	NotesManager* nm = NotesManager::getInstance();
	
	// Test d'affichage des données du NotesManager
	
	cout << endl << "Chemin :" << nm->getPath() << endl; // J'ai mis hello pour le chemin mais c'est du debug
	
	return EXIT_SUCCESS;
}
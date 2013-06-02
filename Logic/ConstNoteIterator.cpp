//
//  ConstNoteIterator.cpp
//  EasyNotePlus_julien
//
//  Created by Julien Nicolas on 01/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#include <iostream>
#include <set>
#include <string>
#include "NotesManager.h"
#include "ConstNotesIterator.h"


using namespace EasyNote;
using namespace std;

namespace EasyNote
{
	// CONSTRUCTEURS
	
	NotesManager::ConstNotesIterator::ConstNotesIterator ()
	{
		
	}
	
	NotesManager::ConstNotesIterator::ConstNotesIterator (set<Note*>::iterator it)
	{
			iterator = it;
	}
	
	const NotesManager::ConstNotesIterator& NotesManager::ConstNotesIterator::operator++ ()
	{
		++iterator;
		
		return *this;
	}
	
	const NotesManager::ConstNotesIterator& NotesManager::ConstNotesIterator::operator-- () 
	{
		--iterator;
		
		return *this;
	}
	
	const NotesManager::ConstNotesIterator NotesManager::ConstNotesIterator::operator++ (int)
	{
		ConstNotesIterator temp(iterator);
		iterator++;
		
		return temp;
	}
	
	const NotesManager::ConstNotesIterator NotesManager::ConstNotesIterator::operator-- (int)
	{
		ConstNotesIterator temp(iterator);
		iterator--;
		
		return temp;
	}
	
	const Note* const NotesManager::ConstNotesIterator::operator* () const
	{
		return *iterator;
	}
	
	bool NotesManager::ConstNotesIterator::operator==(const NotesManager::ConstNotesIterator& ni) const
	{
		return iterator == ni.iterator; 
	}
	
	bool NotesManager::ConstNotesIterator::operator!=(const ConstNotesIterator& ni) const
	{
		return iterator != ni.iterator;
	}
	
}
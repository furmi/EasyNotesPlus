//
//  NotesIterator.cpp
//  EasyNotePlus_julien
//
//  Created by Julien Nicolas on 01/06/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#include <iostream>
#include <set>
#include "NotesManager.h"
#include "NotesIterator.h"

using namespace EasyNote;
using namespace std;

class Note;

namespace EasyNote
{
	NotesManager::NotesIterator::NotesIterator()
	{
		
	}
	
	NotesManager::NotesIterator::NotesIterator(set<Note*>::iterator it)
	{
		iterator = it;
	}
	
	NotesManager::NotesIterator& NotesManager::NotesIterator::operator++ ()
	{
		++iterator;
	
		return *this;
	}
	
	NotesManager::NotesIterator& NotesManager::NotesIterator::operator-- ()
	{
		--iterator;
		
		return *this;
	}
	
	NotesManager::NotesIterator NotesManager::NotesIterator::operator++ (int)
	{
		NotesIterator temp(iterator);
		iterator++;
		
		return temp;
	}
	
	NotesManager::NotesIterator NotesManager::NotesIterator::operator-- (int)
	{
		NotesIterator temp(iterator);
		iterator--;
		
		return temp;
	}
	
	Note* NotesManager::NotesIterator::operator* ()
	{
		return *iterator;
	}
	
	bool NotesManager::NotesIterator::operator==(const NotesManager::NotesIterator& ni)
	{
		return iterator == ni.iterator; 
	}
	
	bool NotesManager::NotesIterator::operator!=(const NotesIterator& ni)
	{
		return iterator != ni.iterator;
	}
	
}
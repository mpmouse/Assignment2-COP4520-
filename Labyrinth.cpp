/**
 *  Created by: Mari Peele
 *  Course: COP 4520
 *	Semester: Spring 2023
 *  Project: Programming Assignment 2 (Minotaur's Birthday Party)
 */

#include "Labyrinth.h"
#include "Guest.h"

Labyrinth::Labyrinth()
{
	mVisitorCount.store(0);
	mPlate = new Plate();
}

Labyrinth::~Labyrinth() = default;

int Labyrinth::getVisitorCount()
{
	return 	mVisitorCount;
}

void Labyrinth::recieveGuest(Guest *guest)
{
	bool completedLabrith = false;

	while (completedLabrith == false)
	{
		if (door.try_lock())
		{
			guest->enterLabrinth(mPlate);
			completedLabrith = true;
			mVisitorCount++;
			door.unlock();
		}
	}
}

void Labyrinth::resetPlate()
{
	mPlate->reset();
}
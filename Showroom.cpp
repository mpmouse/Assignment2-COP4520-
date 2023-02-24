/**
 *  Created by: Mari Peele
 *  Course: COP 4520
 *	Semester: Spring 2023
 *  Project: Programming Assignment 2 (Minotaur's Birthday Party)
 */


#include "Showroom.h"


Showroom::Showroom()
{
	mVisitors.store(0);
}

Showroom::~Showroom() = default;

void Showroom::reset()
{
	mVisitors.store(0);
}

void Showroom::setBusy()
{
	door.lock();
}

bool Showroom::checkSign()
{
	bool viewed = false;

	if (door.try_lock())
	{
		enterShowroom();

		viewed = true;

		door.unlock();
	}
	else
	{
		/** Walk on by **/
	}

	return viewed;
}

void Showroom::enterShowroom()
{
	/**
	*
	*   T T
	*   | |
	*  /   \
	* / $$$ \
	* \     /
	* /     \
	* \_____/
	*
	*/

	// Ooooooooh Aaaaahhhhh

	mVisitors++;
}
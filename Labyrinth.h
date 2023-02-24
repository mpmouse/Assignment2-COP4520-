/**
 *  Created by: Mari Peele
 *  Course: COP 4520
 *	Semester: Spring 2023
 *  Project: Programming Assignment 2 (Minotaur's Birthday Party)
 */

#ifndef LABYRINTH_H
#define LABYRINTH_H


#include "Plate.h"
#include <mutex>
#include <atomic>

class Guest;

class Labyrinth
{
public:

	Labyrinth();

	~Labyrinth();

	void recieveGuest(Guest *guest);

	void resetPlate();

	int getVisitorCount();


private:
	std::atomic<int> mVisitorCount;
	Plate *mPlate;
	std::mutex door;
};

#endif // !LABYRINTH_H


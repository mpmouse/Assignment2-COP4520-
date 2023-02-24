/**
 *  Created by: Mari Peele
 *  Course: COP 4520
 *	Semester: Spring 2023
 *  Project: Programming Assignment 2 (Minotaur's Birthday Party)
 */

#include "Timer.h"
#include "Party.h"

#include <iostream>



int main(int argc, char **argv, char **env) {

	int mGuests = 100;

	Timer mTimer;

	mTimer.startTimer();

	//std::cout << "Trial " << 1 << ":" << std::endl;
	Party labrinthParty(mGuests); // threads are started at creation, creating the party starts the party
	labrinthParty.mingle();
	labrinthParty.printStatistics();

	/*
	for (int i = 2; i < 11; i++)
	{
		std::cout << "Trial " << i << ":" << std::endl;
		labrinthParty.resetParty();
		labrinthParty.printStatistics();

		std::cout << std::endl;
	}
	*/

	mTimer.stopTimer();

	return 0;
}
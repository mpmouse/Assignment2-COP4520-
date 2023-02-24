/**
 *  Created by: Mari Peele
 *  Course: COP 4520
 *	Semester: Spring 2023
 *  Project: Programming Assignment 2 (Minotaur's Birthday Party)
 */

#ifndef GUEST_H
#define GUEST_H

#include "Plate.h"
#include "Showroom.h"

#include <thread>

class Party;

class Guest
{

public:

	Guest();

	~Guest();

	bool gaveUpOnVase();

	bool seenVase();

	void viewVase();

	bool isHungry();

	void eat(Plate *plate);

	bool makeDecision();

	void enterLabrinth(Plate *plate);

	void enterParty(int guestId, Party *invitation);

	void checkShowroom(Showroom *showroom);

	void party();

	void goHome();

	void setGuestCount(int guestCount);

private:
	bool mHungry; // Guests are full after one cupcake
	bool mViewedVase;
	int mFullPlateVisits;
	std::thread mThread;
	int mGuestId;
	Party *mParty;
	int mTriedShowroom;
	int mGuestCount;
};

#endif // !GUEST_H

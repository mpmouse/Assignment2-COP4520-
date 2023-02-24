/**
 *  Created by: Mari Peele
 *  Course: COP 4520
 *	Semester: Spring 2023
 *  Project: Programming Assignment 2 (Minotaur's Birthday Party)
 */

#ifndef PARTY_H
#define PARTY_H

#include <mutex>
#include <vector>
#include <random>

#include "Plate.h"
#include "Showroom.h"
#include "Labyrinth.h"

class Guest;

class Party {

public:

	Party(int guests);

	~Party();

	void resetParty();

	int randomGuest();

	void sendInGuest(Guest *guest);

	void tryShowroom(int guestId);

	void inviteGuests();

	void mingle();

	bool didAllGuestsEat();

	void endParty();

	void printStatistics();

	Showroom *getShowroom();

	bool checkForAnnouncment();

	void makeAnnouncment();

private:
	Showroom *mShowroom;
	int mGuestCount;
	std::vector<Guest> mGuestList;
	std::atomic<bool> mAnnouncment;
	std::mutex door;
	std::mutex mutex;
	Labyrinth *mLabyrinth;
	std::mt19937 mRandomizer;
	std::uniform_int_distribution<int> mRandomDistribution;
};

#endif // !PARTY_H

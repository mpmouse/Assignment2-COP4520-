/**
 *  Created by: Mari Peele
 *  Course: COP 4520
 *	Semester: Spring 2023
 *  Project: Programming Assignment 2 (Minotaur's Birthday Party)
 */

#include <iostream>

#include "Party.h"
#include "Guest.h"

 
Party::Party(int guests) :
	mRandomDistribution(0, guests)
{
	std::random_device seeder;
	mRandomizer.seed(seeder());
	mGuestCount = guests;
	mShowroom = new Showroom();
	mShowroom->reset();
	srand(time(NULL));
	mAnnouncment.store(false);
	mLabyrinth = new Labyrinth();
	inviteGuests();
}

Party::~Party() = default;

void Party::resetParty()
{
	mLabyrinth->resetPlate();
	mShowroom->reset();
	inviteGuests();
	srand(time(NULL));
	mAnnouncment.store(false);
}

int Party::randomGuest()
{
	std::lock_guard<std::mutex> lock(mutex);

	int guest = mRandomDistribution(mRandomizer);

	return guest;
}

Showroom *Party::getShowroom()
{
	return mShowroom;
}

void  Party::sendInGuest(Guest *guest)
{	
	mLabyrinth->recieveGuest(guest);

	//mAnnouncment = guest->makeAnnouncment(mGuestCount);
}

void Party::inviteGuests()
{			
	mGuestList = std::vector<Guest>(mGuestCount);

	for (int i = 0; i < mGuestList.size(); i++)
	{
		mGuestList[i].setGuestCount(mGuestCount); // Known by guests from creating the strategy BEFORE starting the game.
		mGuestList[i].enterParty(i, this);

	}
}

void Party::mingle()
{

	while (!mAnnouncment)
	{
		/**
		 * Minotaur: "Welcome! You may wander my castle and 
		 * have a good time but please follow these rules:
		 * 
		 * Only one may enter my showroom at a time. Please wait
		 * for the sign to say "Available" before viewing the vase.
		 * 
		 * Flip the sign to "Busy" when viewing the vase and flip
		 * the sign back to "Available" when you are done.
		 * 
		 * You may decide a strategy before entering the labrinth 
		 * to know when everyone has entered but you may not discuss
		 * your time in the labrinth once the game has started.
		 * 
		 * When the announcment has been made that all guests have 
		 * toured the labrinth, please collect your belongings and 
		 * go home.
		 * 
		 * Enjoy!!"
		 */
	}

	endParty();
}

void Party::tryShowroom(int guestId)
{
	mGuestList[guestId].checkShowroom(mShowroom);
}

bool Party::didAllGuestsEat()
{
	int hungryGuests = 0;
	bool allFull = false;
			
	for (int i = 0; i < mGuestCount; i++)
	{
		if (mGuestList[i].isHungry())
		{
			hungryGuests++;
		}
	}

	if (hungryGuests == 0)
	{
		allFull = true;
	}

	std::cout << "Number of guests who entered the labyrinth: " << (mGuestCount - hungryGuests) << std::endl;

	return allFull;
}

void Party::endParty()
{
	for (int i = 0; i < mGuestList.size(); i++)
	{
		mGuestList[i].goHome();
	}
}

void Party::printStatistics()
{
	std::cout << "Guest Count: " << mGuestCount << std::endl;
	std::cout << "Visits to labrinth: " << mLabyrinth->getVisitorCount() << std::endl;

	if (didAllGuestsEat())
	{
		std::cout << "All guests have visited the labrinth." << std::endl;

	}
	else
	{
		std::cout << "Not all guests have visited the labrinth." << std::endl;
	}
}

bool Party::checkForAnnouncment()
{
	return mAnnouncment;
}

void Party::makeAnnouncment()
{
	mAnnouncment.store(true);
}



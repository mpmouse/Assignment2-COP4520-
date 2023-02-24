/**
 *  Created by: Mari Peele
 *  Course: COP 4520
 *	Semester: Spring 2023
 *  Project: Programming Assignment 2 (Minotaur's Birthday Party)
 */


#include "Guest.h"
#include "Party.h"

Guest::Guest()
{
	mHungry = true;
	mViewedVase = false;
	mFullPlateVisits = 0;
	mTriedShowroom = 0;
}

Guest::~Guest() = default;

void Guest::setGuestCount(int guestCount)
{
	mGuestCount = guestCount;
}

bool Guest::gaveUpOnVase()
{
	if (mTriedShowroom >= 5)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Guest::seenVase()
{
	return mViewedVase;
}

void Guest::viewVase()
{
	mViewedVase = true;
}
	
bool Guest::isHungry()
{
	return mHungry;
}

void Guest::eat(Plate *plate)
{
	plate->eat();
	mHungry = false;
}

bool Guest::makeDecision()
{
	bool announcment = false;

	if (mFullPlateVisits >= (mGuestCount * 100))
	{
		announcment = true;
	}

	return announcment;
}

void Guest::enterLabrinth(Plate *plate)

{
	if (plate->isEmpty())
	{
		plate->requestFood();

		if (isHungry())
		{
			eat(plate);
		}
	}
	else // Plate is full
	{
		mFullPlateVisits++;

		if (isHungry())
		{
			eat(plate);
		}
	}
}

void Guest::enterParty(int guestId, Party *invitation)
{
	mGuestId = guestId;

	mParty = invitation;

	mThread = std::thread(&Guest::party, this);

}

void Guest::party()
{
	while (!mParty->checkForAnnouncment())
	{

		// select random id to send into party
		if (mParty->randomGuest() == mGuestId)
		{
			mParty->sendInGuest(this);

			if (makeDecision())
			{
				mParty->makeAnnouncment();
			}
		}
		else if (!this->seenVase() && !this->gaveUpOnVase()) // Consider a way to randomize or delay this
		{
			checkShowroom(mParty->getShowroom());
		}
	}
}

void Guest::goHome()
{
	if (mThread.joinable())
	{
		mThread.join();
	}

}

void Guest::checkShowroom(Showroom *showroom)
{
	mViewedVase = showroom->checkSign();

	mTriedShowroom++;
}

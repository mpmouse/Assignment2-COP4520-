/**
 *  Created by: Mari Peele
 *  Course: COP 4520
 *	Semester: Spring 2023
 *  Project: Programming Assignment 2 (Minotaur's Birthday Party)
 */


#include "Plate.h"

Plate::Plate()
{
	mCupcake = true;
	mPlatesEaten = 0;
}

void Plate::reset()
{
	mCupcake = true;
	mPlatesEaten = 0;
}

int Plate::getTotalEaten() // TODO remove
{
	return mPlatesEaten;
}

bool Plate::isEmpty()
{
	return mCupcake;
}

void Plate::eat()
{
	mCupcake = false;
	mPlatesEaten++; // TODO remove

}

void Plate::requestFood()
{
	mCupcake = true;
}


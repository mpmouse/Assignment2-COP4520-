/**
 *  Created by: Mari Peele
 *  Course: COP 4520
 *	Semester: Spring 2023
 *  Project: Programming Assignment 2 (Minotaur's Birthday Party)
 */

#ifndef PLATE_H
#define PLATE_H


class Plate
{

public:

	Plate();

	void reset();

	int getTotalEaten(); // TODO remove

	bool isEmpty();

	void eat();

	void requestFood();

private:
	bool mCupcake;
	int mPlatesEaten;  // TODO remove
};

#endif // !PLATE_H

/**
 *  Created by: Mari Peele
 *  Course: COP 4520
 *	Semester: Spring 2023
 *  Project: Programming Assignment 2 (Minotaur's Birthday Party)
 */

#ifndef SHOWROOM_H
#define SHOWROOM_H

#include <mutex>
#include <atomic>

class Showroom
{

public:

	Showroom();

	~Showroom();

	void reset();

	void setBusy();

	bool checkSign();

	void enterShowroom();

private:
	std::atomic<int> mVisitors;
	std::mutex door;
};

#endif // !SHOWROOM_H
/**
 *  Created by: Mari Peele
 *  Course: COP 4520
 *	Semester: Spring 2023
 *  Project: Programming Assignment 2 (Minotaur's Birthday Party)
 */


#include "Timer.h"

Timer::Timer()
{
	// Do nothing
}

Timer::~Timer() = default;

void Timer::startTimer()
{
	mStartTime = std::chrono::steady_clock::now();
}

void Timer::stopTimer()
{
	mEndTime = std::chrono::steady_clock::now();
}

std::chrono::milliseconds Timer::getExecutionTime()
{
	auto timeElapsed = mEndTime - mStartTime;

	return std::chrono::duration_cast<std::chrono::milliseconds>(timeElapsed);
}
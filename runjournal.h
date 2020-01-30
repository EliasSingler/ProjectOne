#include<iostream>
#include "runtime.h"
#ifndef RUNJOURNAL_H
#define RUNJOURNAL_H

class Runjournal 
{
public:
//default constructor
Runtime();
//add to journal
void record(Runtime run);

//displays all runs
void displayAllRuns();

// searching for particular time and displays first ruin that matches that time (shows distance and pace
// allows removeal of this run in case it was recorded incorrectly)

// search and display all runs of particular distance
void searchDisplay(double dis);

// sort array by time

//sort array by distance

// reports opn the total time for all the runs record in the journal

// reports the average pace for all the runs in the journal

private:
Runtime journal[200];
int filled;

};

#endif
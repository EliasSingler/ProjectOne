#include<iostream>
#include "runtime.h"
#ifndef RUNJOURNAL_H
#define RUNJOURNAL_H

class Runjournal 
{
public:
//default constructor
Runjournal();

//add to journal
void record(Runtime run);

//displays all runs
void display();

// searching for particular time and displays first ruin that matches that time (shows distance and pace
// allows removal of this run in case it was recorded incorrectly)
void find_remove(Runtime r);

// search and display all runs of particular distance
void distance_view(double dis);

// sort array by time
void time_sort();

//sort array by distance
void distance_sort();

// reports opn the total time for all the runs record in the journal
void total_time();

// reports the average pace for all the runs in the journal
void average_pace();

// total distance in all the runs in the journal
void total_distance();

private:
Runtime journal[200];
int filled;

};

#endif
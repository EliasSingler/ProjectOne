#include "runjournal.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

Runjournal::Runjournal()
{
    for(size_t i = 0, i<200;i++)
    {
        journal[i] = 0;
    }
    filled = 0;
}
void Runjournal::record(Runtime run)
{
    journal[filled] = run;
}

void Runjournal::display()
{
    for(size_t i = 0; i<filled; i++)
    {
        cout<< "Distance: " << journal[i].get_distance() << " Time: " << journal[i].get_time().get_hours() << ":" 
        << journal[i].get_time().get_minutes()<< ":" << journal[i].get_time().get_seconds() << endl;
    }
}

/*
void Runjournal::searchDisplay(double dis)
{
    for(size_t i = 0; i < filled; i++)
    {
        if(distance == dis)
        {
            cout<< "Distance: " << journal[i].get_distance() << " Time: " << journal[i].get_time().get_hours() << ":" << journal[i].get_time().get_minutes()<< ":" << journal[i].get_time().get_seconds() << endl;
        }
    }
}
*/
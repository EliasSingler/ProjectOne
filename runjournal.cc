#include "runjournal.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

Runjournal::Runjournal()
{
    Runtime temp;
    for(size_t i = 0; i<200;i++)
    {
        journal[i] = temp;
    }
    filled = 0;
}
void Runjournal::record(Runtime run)
{
    journal[filled] = run;
}

void Runjournal::display()
{
    for(int i = 0; i<filled; i++)
    {
        cout<< "Distance: " << journal[i].get_distance() << " Time: " << journal[i].get_time().get_hours() << ":" 
        << journal[i].get_time().get_minutes()<< ":" << journal[i].get_time().get_seconds() << endl;
    }
}

void find_remove(Runtime r)
{

}

void distance_view(double dis)
{

}

void time_sort()
{

}

void distance_sort()
{

}

void total_time()
{

}

void average_pace()
{

}

void total_distance()
{
    
}
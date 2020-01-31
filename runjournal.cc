#include "runjournal.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

Runjournal::Runjournal()
{
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

// not complete
void Runjournal::find_remove(Runtime r)
{
    for(int i = 0; i<filled; i++)
    {
        if(journal[i]==r)
        {
            cout << "Distance: " << journal[i].get_distance() << ", Pace: " << journal[i].pace() << endl;
        }
    }
}

void Runjournal::distance_view(double dis)
{
    for(int i = 0; i<filled; i++)
    {
        if(journal[i].distance_equal(dis))
        {
        cout<< "Distance: " << journal[i].get_distance() << " Time: " << journal[i].get_time().get_hours() << ":" 
        << journal[i].get_time().get_minutes()<< ":" << journal[i].get_time().get_seconds() << endl;
        }
    }
}

void Runjournal::time_sort()
{

}

void Runjournal::distance_sort()
{

}

void Runjournal::total_time()
{
    MyTime time;
    for(int i = 0; i < filled; i++)
    {
        time = time + journal[i].get_time();
    }
    cout << "Total time: " << setw(2)<< setfill('0') << time.get_hours() <<':'<<setw(2)<<
    setfill('0')<<time.get_minutes() <<':'<<setw(2)<<setfill('0')<<time.get_seconds() << endl;
}

void Runjournal::average_pace()
{
    int i;
    MyTime totalPace;
    for(i = 0; i < filled; i++)
    {
        totalPace = journal[i].pace() + totalPace;
    }
    totalPace = totalPace / filled;
    cout << "The average pace of all the runs is: " << setw(2)<< setfill('0') << totalPace.get_hours() <<':'<<setw(2)<<
    setfill('0')<<totalPace.get_minutes() <<':'<<setw(2)<<setfill('0')<<totalPace.get_seconds() << endl;
}

void Runjournal::total_distance()
{
    double total;
    for(int i = 0; i < filled; i++)
    {
        total = total + journal[i].get_distance();
    }
    cout << "The total distance is: " << total << endl;
}
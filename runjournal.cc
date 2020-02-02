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
    filled++;
}

void Runjournal::display()
{
    for(int i = 0; i<filled; i++)
    {
        cout<< journal[i].get_time() << " " << journal[i].get_distance() << endl;
    }
}

// not complete (check the remove part)
void Runjournal::find_remove(Runtime r)
{
    char choice;
    for(int i = 0; i<filled; i++)
    {
        if(journal[i]==r)
        {
            cout << "Distance: " << journal[i].get_distance() << ", Pace: " << journal[i].pace() << endl;
            cout << "Would you like to remove this run? (y/n)" << endl;
            cin >> choice;
            if(choice == 'y')
            {
                for(int j = i; j< filled; j++)
                {
                    journal[j] = journal[j+1];
                }
                filled--;
                break;
            }
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
    Runtime small;
    int smallest;
    Runtime temp;
    for(int i = 0; i < filled; i++)
    {
        small = journal[i];
        smallest = i;
        for(int j = i; j < filled; j++)
        {
            if(journal[j].get_time() < small.get_time())
            {
                small = journal[j];
                smallest = j;
            }
        }
        temp = journal[i];
        journal[i] = small;
        journal[smallest] = temp;

    }
}

void Runjournal::distance_sort()
{
    Runtime small;
    int smallest;
    Runtime temp;
    for(int i = 0; i < filled; i++)
    {
        small = journal[i];
        smallest = i;
        for(int j = i; j < filled; j++)
        {
            if(journal[j].get_distance() < small.get_distance())
            {
                small = journal[j];
                smallest = j;
            }
        }
        temp = journal[i];
        journal[i] = small;
        journal[smallest] = temp;

    }
}


MyTime Runjournal::total_time()
{
    MyTime time;
    for(int i = 0; i < filled; i++)
    {
        time = time + journal[i].get_time();
    }
    return time;
}

MyTime Runjournal::average_pace()
{
    int i;
    MyTime totalPace;
    for(i = 0; i < filled; i++)
    {
        totalPace = journal[i].pace() + totalPace;
    }
    totalPace = totalPace / filled;
    return totalPace;
}

double Runjournal::total_distance()
{
    double total;
    for(int i = 0; i < filled; i++)
    {
        total = total + journal[i].get_distance();
    }
    return total;
}
#include "runtime.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

Runtime::Runtime()
{
    distance = 0;
    rtime.Reset(0,0,0);
}

Runtime Runtime::operator +(const Runtime& rhs)const
{
    Runtime temp;
    temp.distance = distance + rhs.distance;
    temp.rtime = rtime + rhs.rtime;
    return temp;
}

Runtime Runtime::operator -(const Runtime& rhs)const
{
    Runtime temp;
    temp.distance = distance - rhs.distance;
    temp.rtime = rtime - rhs.rtime;
    return temp;
}

Runtime Runtime::operator *(const double& rhs) const
{
    Runtime temp;
    temp.distance = distance*rhs;
    temp.rtime = rtime*rhs;
    return temp;
}

Runtime Runtime::operator /(const double& rhs) const
{
    Runtime temp;
    temp.distance = distance/rhs;
    temp.rtime = rtime/rhs;
    return temp;
}


bool Runtime::operator == (const Runtime& rhs)const
{
    if( (distance - rhs.distance)< .1 && rtime ==rhs.rtime)
    {
        return true;
    }
    else {return false;}
}

bool Runtime::operator != (const Runtime& rhs)const
{
    if( fabs(distance - rhs.distance) < .09 && rtime== rhs.rtime)
    {
        return false;
    }
    else {return true;}
}

bool Runtime::distance_equal(double d) const
{
    return (fabs(distance - d) < .09);
}


void Runtime::input(istream&ins){
        char junk;
        ins>>distance;
        ins.get(junk);
        ins>>rtime;
        ins.get(junk);
}

void Runtime::output(std::ostream& outs)const
{
        outs<< rtime.get_hours() <<':'<<setw(2)<<setfill('0')<<rtime.get_minutes();
        outs<<':'<<setw(2)<<setfill('0')<<rtime.get_seconds() << " " << distance << endl;
}

// not sure if this is correct
Runtime operator *(const double& lhs, const Runtime& rhs)
{
    Runtime temp;
    temp.set_distance(lhs* rhs.get_distance());
    temp.set_time(lhs*rhs.get_time());
    return temp;
}

ostream& operator <<(ostream& outs, const Runtime& rhs)
{
    rhs.output(outs);
    return outs;
}

istream& operator >>(istream& ins, Runtime& rhs)
{
    rhs.input(ins);
    return ins;
}

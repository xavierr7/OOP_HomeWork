#pragma once
#include <string>
#include "\all-projects\academic-projects\local\cpp-projects\ArtemMillerPV111\OOP\PV111-OOP-master\Library\Queue.h"
#include "Functions.h"

using std::string;
using std::cout;
using std::endl;


class People
{
	string name;
	u_int  timeBeingAtTheStop = 0;

public:

	People()
	{
		name = randomizerOfName();
	}
	void incrementTime()
	{
		++timeBeingAtTheStop;
	}
	u_int getTime()
	{
		return timeBeingAtTheStop;
	}

	friend ostream& operator << (ostream& out, const People p);
};

inline ostream& operator<<(ostream& out, const People p)
{
	
}

class Minibus
{
	string brand;
	u_int  number;
	u_int  emptyPlaces;

public:
	Minibus()
	{
		brand = randomizerOfBrand();
		number = rand() % 1 + 100;
		setEmptyPlaces();
	}
	
	void setEmptyPlaces()
	{
		emptyPlaces = rand() % 5 + 15;
	}

	friend ostream& operator << (ostream& out, const Minibus mb);

};

ostream& operator<<(ostream& out, const Minibus mb)
{
	
}

class Halt
{
	Queue<People>  qPeople;
	Queue<Minibus> qMinibus;
	u_int average_Passenger_ArrivalTime;
	u_int average_TimeOfArrival_OfMinibuses;
	u_int maximum_NumberOfPeople_AtTheStop;
	u_int averageTime_BeingOnStop;

public:

};


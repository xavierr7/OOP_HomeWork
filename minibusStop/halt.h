#pragma once
#include<iostream>
#include <windows.h>
#include <string>
#include "/all-projects/academic-projects/local/cpp-projects/Local Repository/Containers/Queue/Queue.h"
#include "Functions.h"
#include <iomanip>

using std::string;
using std::cout;
using std::endl;


//////////////////////
class People
{
	string name;
	size_t  timeBeingAtTheStop = 0;

public:

	People()
	{
		name = randomizerOfName();
	}
	void incrementTime()
	{
		++timeBeingAtTheStop;
	}
	size_t getTime()
	{
		return timeBeingAtTheStop;
	}

	friend ostream& operator << (ostream& out, const People p);
};

ostream& operator<<(ostream& out, const People p)
{
	out << "\"" << left << p.name << "\"  Time being: " << p.timeBeingAtTheStop << " seconds";
	return out;
}
/////////////////////////


/////////////////////////
class Minibus
{
	string brand;
	size_t  number;
	size_t  emptyPlaces;

public:
	Minibus()
	{
		brand = randomizerOfBrand();
		number = rand() % 100 + 1;
		setEmptyPlaces();
	}
	
	void setEmptyPlaces()
	{
		emptyPlaces = rand() % (15 - (5 + 1)) + 5;
	}
	
	size_t getEmptyPlaces()
	{
		return emptyPlaces;
	}

	friend ostream& operator << (ostream& out, const Minibus mb);

};

ostream& operator<<(ostream& out, const Minibus mb)
{
	out << left << (char)185 << mb.number << "\nBrand: " << mb.brand;
	return out;
}
/////////////////////////


////////////////////////
class Halt
{
	Queue<People>  qPeople;
	Queue<Minibus> qMinibus;
	size_t average_Passenger_ArrivalTime;
	size_t average_TimeOfArrival_OfMinibuses;
	size_t maximum_NumberOfPeople_AtTheStop_AtOneMoment;
	size_t averageTime_BeingOnStop = 0;

	void servedPassengers();

public:
	Halt(size_t average_Passenger_ArrivalTime, size_t average_TimeOfArrival_OfMinibuses, size_t maximum_NumberOfPeople_AtTheStop_AtOneMoment)
	{
		if (average_Passenger_ArrivalTime > 1 && average_TimeOfArrival_OfMinibuses > 1 && maximum_NumberOfPeople_AtTheStop_AtOneMoment > 0)
		{
			this->average_Passenger_ArrivalTime = average_Passenger_ArrivalTime;
			this->average_TimeOfArrival_OfMinibuses = average_TimeOfArrival_OfMinibuses;
			this->maximum_NumberOfPeople_AtTheStop_AtOneMoment = maximum_NumberOfPeople_AtTheStop_AtOneMoment;
		}
		Minibus newMinibus;
		qMinibus.enqueue(newMinibus);
	}

	void process();
};

void Halt::servedPassengers()
{
	size_t size;

	if(qPeople.length() > qMinibus.peek().getEmptyPlaces())
		size = qMinibus.peek().getEmptyPlaces();
	else
		size = qPeople.length();

	for (size_t i = 0; i < size; ++i)
		qPeople.dequeue();
	
	Minibus newMinibus;
	newMinibus = qMinibus.peek();
	newMinibus.setEmptyPlaces();
	qMinibus.dequeue();
	qMinibus.enqueue(newMinibus);
}

void Halt::process()
{
	while (true)
	{
		size_t tmpTimeMinibus = rand() % ((average_TimeOfArrival_OfMinibuses + 1) - (average_TimeOfArrival_OfMinibuses - 1) + 1) + average_TimeOfArrival_OfMinibuses - 1;

		size_t tmpTimePeople = rand() % ((average_Passenger_ArrivalTime + 1) - (average_Passenger_ArrivalTime - 1) + 1) + average_Passenger_ArrivalTime - 1;

		for (size_t i = 0; i < tmpTimeMinibus; ++i)
		{
			system("cls");
			cout << "Minibus - " << qMinibus.peek() << endl;
			cout << "On the road..." << endl;
			cout << "-------------------------------------------           -------------------------------------------" << endl;
			
			Queue<People> all_qPeople = qPeople;
			size_t sizePeople = qPeople.length();
			for (size_t i = 0; i < sizePeople; i++)
			{
				averageTime_BeingOnStop += all_qPeople.peek().getTime();
				all_qPeople.dequeue();
			}

			cout << "Average time being people on the stop: ";
			if ( sizePeople == 0)
				cout << "   |\n";
			else
				cout << (averageTime_BeingOnStop /= sizePeople) << " |\n";

			gotoxy(55, 2);
			cout << "MINIBUS HALT ";

			if (i == tmpTimePeople)
			{
				People newPerson;
				qPeople.enqueue(newPerson);

				tmpTimePeople = rand() % ((average_Passenger_ArrivalTime + 1) - (average_Passenger_ArrivalTime - 1) + 1) + average_Passenger_ArrivalTime - 1;
				tmpTimePeople += i;
			}

			Queue<People> new_qPeople;
			size_t size = qPeople.length();
			for (size_t j = 0; j < size; j++)
			{
				People currentPerson = qPeople.peek();
				currentPerson.incrementTime();
				new_qPeople.enqueue(currentPerson);
				qPeople.dequeue();
			}
 			qPeople = new_qPeople;

			gotoxy(82, 2);
			cout << "count " << qPeople.length();
			qPeople.print(54, 4);
			Sleep(1000);
		}

		for (size_t i = 0; i < 6; i++)
		{
			system("cls");
			cout << "Minibus - " << qMinibus.peek() << endl;
			cout << "The Minibus has arrived!" << endl;
			cout << "-------------------------------------------           -------------------------------------------" << endl;
			cout << "Average time being people on the stop: ";
			if (averageTime_BeingOnStop == 0)
				cout << " |\n";
			else
				cout << averageTime_BeingOnStop << " |\n";

			gotoxy(55, 2);
			cout << "MINIBUS HALT     count " << qPeople.length();

			qPeople.print(54, 4);

			gotoxy(0, 6);
			cout << "-------------------------------------\n";
			cout << "|                                   |\n";
			cout << "-------------------------------------\n";
			gotoxy(4, 7);
			cout << "Count of empty places - " << qMinibus.peek().getEmptyPlaces();
			gotoxy(0, 10);
			if (i < 3)
			{
				cout << "Boarding the Minibus...\n";
				cout << "-------------------------------------------\n";
			}
			else
			{
				cout << "People who got on the bus:\n";
				cout << "-------------------------------------------\n";

				Queue<People> all_qPeople = qPeople;
				Queue<People> gotOntTheBus_qPeople;
				size_t size;
				if (qPeople.length() > qMinibus.peek().getEmptyPlaces())
					size = qMinibus.peek().getEmptyPlaces();
				else
					size = qPeople.length();
				for (size_t j = 0; j < size; j++)
				{
					People currentPerson = all_qPeople.peek();
					gotOntTheBus_qPeople.enqueue(currentPerson);
					all_qPeople.dequeue();
				}
				gotOntTheBus_qPeople.print(0, 12);
			}
			Sleep(1000);
		}

		servedPassengers();

		if (qPeople.length() > maximum_NumberOfPeople_AtTheStop_AtOneMoment)
		{
			Minibus newMinibus;
			qMinibus.enqueue(newMinibus);
			average_TimeOfArrival_OfMinibuses /= qMinibus.length();
		}
	}
}
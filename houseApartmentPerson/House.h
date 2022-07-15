#pragma once

#include "Menu.h"
#include "Functions.h"
#include <fstream>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

// чисто логічно я так розумію, в цьому завданні мати конструктори копіювання и перевантажені оператори присвоєння не зовсім доречно, але по завданню треба, тому я зробив.

class House;

class Tenants
{
	friend class Apartment;

	char* FIO = nullptr;
	uint16_t age = 0;

	void setFIO();
	void setFIO(const char* fio);
	void setAge();
	void print();
	string toString();

public:
	Tenants() {}
	~Tenants()
	{
		delete FIO;
	}
	Tenants(const Tenants& person);
	Tenants& operator = (const Tenants& person);
};

class Apartment
{
	friend class House;

	Tenants* tenants = nullptr;
	uint16_t size = 0;

	void addTenants();
	void delTenants();
	void print();
	void menu();

	string toString();


public:
	Apartment() {}
	Apartment(const Apartment& apartment);
	Apartment& operator = (const Apartment& apartment);
	~Apartment()
	{
		delete [] tenants;
	}
};

class House
{
	friend class Apartment;

	Apartment* apartments;
	uint16_t size;
	char* address = nullptr;
	uint16_t countOfFloors;
	bool elevator;
	static uint16_t countOfPeople;


	void workWithApartment();
	void setInfo();
	void showInfo();

public:


	House(uint16_t countOfApartments)
	{
		if (countOfApartments <= 0)
		{
			return;
		}
		else
		{
			size = countOfApartments;
		}
		setInfo();
	}
	~House()
	{
		delete [] apartments;
		delete address;
	}

	House(const House& house);
	House& operator = (const House& house);

	void menu();
};


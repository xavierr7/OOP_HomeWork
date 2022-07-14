#pragma once

#include "Menu.h"
#include "Functions.h"
#include <fstream>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

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
	Tenants* tenants = nullptr;
	uint16_t size = 0;
	uint16_t apartmentNumber = 0;
	uint16_t apartmentArea = 0;

	void addTenants();
	void delTenants();
	void print();
	void menu();

public:
	Apartment() {}
	~Apartment()
	{
		delete[] tenants;
	}
};

class House
{
	Apartment* countOfApartments;
	uint16_t size = 0;
public:

};


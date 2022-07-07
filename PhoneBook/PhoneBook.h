#pragma once
#include"Menu.h"
#include "Functions.h"
#include <iostream>
#include <fstream>

class PhoneBook;

class Abonent
{
	friend class PhoneBook;

	char* FIO = nullptr;
	char* phone = nullptr;
	char* info = nullptr;
	bool isFind = false;

	void setFIO();
	void setFIO(const char* fio);
	void setPhone();
	void setPhone(const char* phone);
	void setInfo();
	void setInfo(const char* info);
	void print();
	string toString();

public:
	Abonent() {}
	~Abonent()
	{
		delete FIO;
		delete phone;
		delete info;
	}
	Abonent& operator = (const Abonent& obj);
	Abonent(const Abonent& obj);
};

class PhoneBook
{
	Abonent* abonents = nullptr;
	int size = 0;
	bool wasDelete = false;
	bool wasRead = false;

	void addAbonent();
	void delAbonent();
	void findAbonent();
	void writeAbonentsToFile();
	void readAbonentsFromFile();
	void print();

public:
	PhoneBook() {}
	~PhoneBook()
	{
		delete[] abonents;
	}
	void menu();
};


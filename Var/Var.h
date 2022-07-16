#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

enum TYPE
{
	_NULL, _INT, _DOUBLE, _STRING
};

class var
{
	TYPE type;
	void* value;

	void copy(const var& v);
	int str_to_int(const char* s);
	double str_to_double(const char* s);
	var concat(const var& v);
public:

	var();
	var(int i);
	var(double d);
	var(const char* s);
	var(const var& v);
	var& operator = (const var& v);
	var operator + (const var& v);
	var operator += (const var& v);
	friend std::ostream& operator <<(std::ostream& out, const var& var);
};


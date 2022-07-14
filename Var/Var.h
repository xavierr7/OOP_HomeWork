#pragma once
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
public:

	var();
	var(int i);
	var(double d);
	var(const char* s);
	var(const var& v);
	var& operator = (const var& v);
	var operator + (const var& v);
	friend std::ostream& operator <<(std::ostream& out, const var& str);
};


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
public:

	var();
	var(int i);
	var(double d);
	var(const char* s);

	friend std::ostream& operator <<(std::ostream& out, const var& str);
};


#pragma once
#include <iostream>
#include <malloc.h>
using namespace std;

class String
{
	char* str;
	size_t length;
public:
	String();
	String(const char* str);
	~String();
	String(const String& other);
	String(String&& other);
	String& operator = (const String& other);
	String operator +(const String& other);
	size_t Length();
	bool operator == (const String& other);
	bool operator != (const String& other);
	char& operator [] (size_t index);
	friend std::ostream& operator << (std::ostream& out, const String& str);
	friend std::istream& operator >> (std::istream& out, String& str);
};


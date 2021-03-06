#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class String
{
	char* str;
	size_t length;
	static size_t countOfCreatedStrings;

	void makeNewStr(const char*);

public:
	String();
	String(const char* str);
	String(const String& other);
	String(String&& other)noexcept;

	~String();

	String& operator = (const String& other);
	String operator +(const String& other);
	String operator +(const char* str);
	String operator *(int number);
	String operator -(const String& other);
	String operator -=(const String& other);
	String operator +=(const String& other);
	bool operator == (const String& other);
	bool operator != (const String& other);
	bool operator > (const String& other);
	bool operator < (const String& other);
	bool operator<=(const String& other);
	bool operator >= (const String& other);
	char& operator [] (size_t index);
	void operator()(const String& other);
	operator char* ();
	friend std::ostream& operator << (std::ostream& out, const String& str);
	friend std::istream& operator >> (std::istream& out, String& str);

	size_t Length();
	static size_t GetCountOfCreatedStrings();

	//String operator* (const String str);
};

String operator*(int n, String str);
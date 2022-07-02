#pragma once

class String
{
	char* str;
public:
	String();
	String(const char* str);
	String(const String& other);
	~String();
	String& operator = (const String& other);
	String operator +(const String& other);

	void Print();
};


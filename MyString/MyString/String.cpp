#include <iostream>
#include "String.h"
using namespace std;

String::String()
{
	str = nullptr;
}

String::String(const char* str)
{
	int length = strlen(str);
	this->str = new char[length+1];
	for (size_t i = 0; i < length; i++)
	{
		this->str[i] = str[i];
	}
	this->str[length] = '\0';
}

String::String(const String& other)
{
	int length = strlen(other.str);
	this->str = new char[length + 1];
	for (size_t i = 0; i < length; i++)
	{
		this->str[i] = other.str[i];
	}

	this->str[length] = '\0';
}

String::~String()
{
	delete[] this->str;
}

String& String::operator=(const String& other)
{
	if (this->str != nullptr)
	{
		delete[]str;
	}

	int length = strlen(other.str);
	this->str = new char[length + 1];
	for (size_t i = 0; i < length; i++)
	{
		this->str[i] = other.str[i];
	}
	this->str[length] = '\0';
	return *this;
}

String String::operator+(const String& other)
{
	String newStr;

	int thisLength = strlen(this->str);
	int otherLength = strlen(other.str);
	newStr.str = new char[thisLength + otherLength + 1];

	size_t i = 0;
	for (; i < thisLength; i++)
	{
		newStr.str[i] = this->str[i];
	}

	
	for (size_t j = 0; j < otherLength; j++, i++)
	{
		newStr.str[i] = other.str[j];
	}
	newStr.str[thisLength + otherLength] = '\0';

	return newStr;
}

void String::Print()
{
	cout << str << endl;
}

#include "String.h"

size_t String::countOfCreatedStrings = 0;

String::String()
{
	str = nullptr;
	length = 0;
}

String::String(const char* str)
{
	makeNewStr(str);
	++countOfCreatedStrings;
}

String::~String()
{
	delete this->str;
	--countOfCreatedStrings;
}

String::String(const String& other)
{
	makeNewStr(other.str);
}

String::String(String&& other)
{
	this->length = other.length;
	this->str = other.str;

	other.str = nullptr;
}

String& String::operator=(const String& other)
{
	if (this->str != nullptr)
	{
		delete str;
	}

	makeNewStr(other.str);
	return *this;
}

String String::operator+(const String& other)
{
	String newStr;

	newStr.length = strlen(this->str) + strlen(other.str);
	newStr.str = new char[newStr.length + 1];

	strcpy(newStr.str, this->str);
	strcat(newStr.str, other.str);

	countOfCreatedStrings++;
	return newStr;
}
String String::operator+(const char* str)
{
	String newStr;

	newStr.length = strlen(this->str) + strlen(str);
	newStr.str = new char[newStr.length + 1];

	strcpy(newStr.str, this->str);
	strcat(newStr.str, str);

	countOfCreatedStrings++;
	return newStr;
}

String String::operator*(int n)
{
	String newStr;

	newStr.length = strlen(this->str);

	for (size_t i = 0; i < n; i++)
	{
		newStr = newStr + str;
	}

	return newStr;
}

String operator*(int n, String str)
{
	return str * n;
}

String String::operator+=(const String& other)
{
	return *this = *this + other;
}

bool String::operator<(const String& other)
{

	return (strcmp(this->str, other.str) > NULL) ? true : false;
}

bool String::operator>(const String& other)
{
	return (strcmp(this->str, other.str) < NULL) ? true : false;
}

bool String::operator<=(const String& other)
{
	return (*this == other && *this > other) ? false : true;
}

bool String::operator>=(const String& other)
{
	return (*this == other && *this < other) ? false : true;
}

bool String::operator==(const String& other)
{
	return (strcmp(this->str, other.str) != NULL) ? true  : false;
}

bool String::operator!=(const String& other)
{
	return !(this->operator==(other));
}

char& String::operator [] (size_t index)
{
	return this->str[index];
}

std::ostream& operator<<(std::ostream& out, const String& str)
{
	out << str.str;
	return out;
}

std::istream& operator >> (std::istream& in, String& obj)
{
	char* inputData = nullptr;
	int counter = 0;
	char symbol;

	while (true)
	{
		if ((symbol = in.get()) != '\n')
		{
			inputData = (char*)realloc(inputData, ++counter);
			inputData[counter - 1] = symbol;
		}
		else
		{
			inputData = (char*)realloc(inputData, ++counter);
			inputData[counter - 1] = '\0';
			break;
		}
	}
	obj.length = counter;
	obj.str = new char[counter];
	for (size_t i = 0; i < counter; i++)
	{
		obj.str[i] = inputData[i];
	}

	free(inputData);
	return in;
}

void String::makeNewStr(const char* newStr)
{
	length = strlen(newStr);
	this->str = new char[length + 1];
	strcpy(this->str, newStr);
}

size_t String::Length()
{
	return length;
}

size_t String::GetCountOfCreatedStrings()
{
	return countOfCreatedStrings;
}
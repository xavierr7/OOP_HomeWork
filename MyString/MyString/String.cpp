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

String::String(String&& other)noexcept
{
	this->length = other.length;
	this->str = other.str;

	other.str = nullptr;
}

String::~String()
{
	delete this->str;
	--countOfCreatedStrings;
}

String::String(const String& other)
{
	makeNewStr(other.str);
};

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

String String::operator-(const String& other)
{
	if (*this == other)
	{
		return "";
	}
	String newStr = *this;
	char* p;
	char* tmp = new char[this->length];
	int i = 0;
	while ((p = strstr(newStr.str, other.str)) != NULL)
	{
		char* pStr = &newStr.str[i];
		for (; pStr < p; pStr++, ++i)
		{
			tmp[i] = *pStr;
		}
	
		pStr += other.length;
		tmp[newStr.length - other.length] = '\0';
		for (; pStr < &newStr.str[newStr.length]; pStr++, ++i)
		{
			tmp[i] = *pStr;
		}
		i = 0;
		newStr = tmp;
	}
	delete[] tmp;
	return newStr;
}
String String::operator -=(const String& other)
{
	return *this = *this - other;
}


String String::operator+=(const String& other)
{
	return *this = *this + other;
}

bool String::operator==(const String& other)
{
	return (strcmp(this->str, other.str) != NULL) ? false : true;
}

bool String::operator!=(const String& other)
{
	return !(* this == other);
}

bool String::operator<(const String& other)
{
	if (*this == other)
		return false;
	else if (strcmp(this->str, other.str) > NULL)
		return true;
	else
		return false;
}

bool String::operator>(const String& other)
{
	if (*this == other)
		return false;
	return !(*this < other);
}

bool String::operator<=(const String& other)
{
	if (*this == other)
		return true;
	else if (strcmp(this->str, other.str) > NULL)
		return true;
	else
		return false;
}

bool String::operator>=(const String& other)
{
	if (*this == other)
		return true;
	return !(*this <=other);
}

char& String::operator [] (size_t index)
{
	return this->str[index];
}

void String::operator()(const String& other)
{
	*this = other;
}

String::operator char* ()
{
	char* str = new char[this->length + 1];
	strcpy(str, this->str);
	return str;
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

#include "String.h"

size_t String::countOfCreatedStrings = 0;

//String::String()
//{
//	str = nullptr;
//	length = 0;
//}

String::String(int length)
{
	this->length = length;
	str = new char[length + 1];
	str[0] = '\0';
	++countOfCreatedStrings;
}

String::String(const char* str)
{
	length = strlen(str);
	this->str = new char[length+1];
	for (size_t i = 0; i < length; i++)
	{
		this->str[i] = str[i];
	}
	this->str[length] = '\0';
	++countOfCreatedStrings;
}

String::~String()
{
	delete[] this->str;
	--countOfCreatedStrings;
}

String::String(const String& other)
{
	length = strlen(other.str);
	this->str = new char[length + 1];
	for (size_t i = 0; i < length; i++)
	{
		this->str[i] = other.str[i];
	}

	this->str[length] = '\0';
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
		delete[]str;
	}

	length = strlen(other.str);
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

	newStr.length = strlen(this->str) + strlen(other.str);
	newStr.str = new char[newStr.length + 1];

	for (size_t i = 0, j = 0; i < newStr.length; i++)
	{
		if (i < strlen(this->str))
		{
			newStr.str[i] = this->str[i];
		}
		else
		{
			newStr.str[i] = other.str[j];
			++j;
		}
	}
	newStr.str[newStr.length] = '\0';
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

size_t String::Length()
{
	return length;
}

size_t String::GetCountOfCreatedStrings()
{
	return countOfCreatedStrings;
}

bool String::operator==(const String& other)
{
	if (this->length != other.length)
	{
		return false;
	}

	for (size_t i = 0; i < this->length; i++)
	{
		if (this->str[i] != other.str[i])
		{
			return false;
		}
	}
	return true;
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

void String::SetStr()
{
	String newStr;
	cout << "Input string\n";
	cin >> newStr;
	*this = newStr;
}

void String::SetStr(const char* str)
{
	length = strlen(str);
	for (size_t i = 0; i < length; i++)
	{
		this->str[i] = str[i];
	}
	this->str[length] = '\0';
}

void String::GetStr()
{
	cout << this->str << endl;
}

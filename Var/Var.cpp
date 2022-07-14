#include "Var.h"

void var::copy(const var& v)
{
	switch (v.type)
	{
	case _INT:
		value = new int;
		*((int*)value) = *((int*)v.value);
		break;
	case _DOUBLE:
		value = new double;
		*((double*)value) = *((double*)v.value);
		break;
	case _STRING:
		value = new char[strlen((char*)v.value) + 1];
		strcpy_s((char*)value, strlen((char*)v.value) + 1, (char*)v.value);
		break;
	default:
		value = nullptr;
		break;
	}
	type = v.type;
}

int var::str_to_int(const char* s)
{
	char buff[80];
	int count = 0;
	for (size_t i = 0; i < strlen(s); i++)
	{
		if (isdigit(s[i]))
		{
			buff[count++] = s[i];
		}

	}
	buff[count] = '\0';
	return atoi(buff);
}

var::var()
{
	value = nullptr;
	type = TYPE::_NULL;
}

var::var(int i)
{
	delete value;
	value = new int;
	*((int*)value) = i;
	type = TYPE::_INT;
}

var::var(double d)
{
	delete value;
	value = new double;
	*((double*)value) = d;
	type = TYPE::_DOUBLE;
}

var::var(const char* s)
{
	delete value;
	value = new char[strlen(s)+ 1];
	strcpy_s((char*)value, strlen(s) + 1, s);
	type = TYPE::_STRING;
}

var::var(const var& v)
{
	copy(v);
}

var& var::operator=(const var& v)
{
	if (this == &v)
		return *this;

	delete value;
	copy(v);
	return *this;
}

var var::operator+(const var& v)
{
	switch (type)
	{
	case _INT:
		switch (v.type)
		{
		case _INT: return var(*(int*)value + *(int*)v.value);
		case _DOUBLE: return var((int)(*(int*)value + *(double*)v.value));
		case _STRING: return var(*(int*)value + str_to_int((char*)v.value));
		}
		break;
	case _DOUBLE:
		break;
	case _STRING:
		break;
	default:
		*this = v;
		break;
	}
	return var();
}

std::ostream& operator<<(std::ostream& out, const var& str)
{
	switch (str.type)
	{
	case _INT:
		out << *((int*)str.value);
		break;
	case _DOUBLE:
		out << *((double*)str.value);
		break;
	case _STRING:
		out << *((char*)str.value);
		break;
	default:
		break;
	}
}

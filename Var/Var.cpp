#include "Var.h"
#include <sstream>

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

double var::str_to_double(const char* s)
{
	char buff[80];
	int count = 0;
	int tmp = 0;

	for (size_t i = 0; i < strlen(s); i++)
	{
		if (isdigit(s[i]) || s[i] == '.')
		{
			if (s[i] == '.')
			{
				tmp = i + 1;
				buff[count++] = s[i];
				break;
			}
			buff[count++] = s[i];
		}
	}
	for (size_t i = tmp; i < strlen(s); i++)
	{
		if (isdigit(s[i]))
		{
			buff[count++] = s[i];
		}
		else
		{
			break;
		}
	}
	buff[count] = '\0';
	return atof(buff);
}

var var::concat(const var& v)
{
	var tmp{ "" };
	size_t len = strlen((char*)value) + strlen((char*)v.value);
	tmp.value = new char[len + 1];
	strcpy((char*)tmp.value, (char*)value);
	strcat((char*)tmp.value, (char*)v.value);
	return tmp;
}

var::var()
{
	value = nullptr;
	type = TYPE::_NULL;
}

var::var(int i)
{
	value = new int;
	*((int*)value) = i;
	type = TYPE::_INT;
}

var::var(double d)
{
	value = new double;
	*((double*)value) = d;
	type = TYPE::_DOUBLE;
}

var::var(const char* s)
{
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
		case _INT:	  return var(*(int*)value + *(int*)v.value);
		case _DOUBLE: return var((int)(*(int*)value + *(double*)v.value));
		case _STRING: return var(*(int*)value + str_to_int((char*)v.value));
		}
		break;
	case _DOUBLE:
		switch (v.type)
		{
		case _INT:	  return var(*(double*)value + *(int*)v.value);
		case _DOUBLE: return var((*(double*)value + *(double*)v.value));
		case _STRING: return var(*(double*)value + str_to_double((char*)v.value));
		}
		break;
	case _STRING:
		switch (v.type)
		{
		case _INT:	  return (concat(std::to_string(*(int*)v.value).data()));
		case _DOUBLE: return (concat(std::to_string(*(double*)v.value).data()));
		case _STRING: return (concat(v));
		}
		break;
	default:
		*this = v;
		break;
	}
}

var var::operator+=(const var& v)
{
	return *this = *this + v;
}

std::ostream& operator<<(std::ostream& out, const var& var)
{
	switch (var.type)
	{
	case _INT:
		out << *((int*)var.value);
		break;
	case _DOUBLE:
		out << *((double*)var.value);
		break;
	case _STRING:
		out << (char*)var.value;
		break;
	default:
		break;
	}

	return out;
}
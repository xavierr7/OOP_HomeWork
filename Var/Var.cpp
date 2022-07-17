#include "Var.h"
#include "Functions.h"
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

var var::eraseSubStr(const var& v)
{
	if (strcmp((char*)value, (char*)v.value) == NULL)
	{
		return "";
	}
	var newStr = *this;
	size_t len = strlen((char*)value);
	char* p;
	char* tmp = new char[len + 1];
	int i = 0;
	while ((p = strstr((char*)newStr.value, (char*)v.value)) != NULL)
	{
		char* pStr = (char*)newStr.value;
		for (; pStr < p; pStr++, ++i)
		{
			tmp[i] = *pStr;
		}

		pStr += strlen((char*)v.value);
		tmp[strlen((char*)newStr.value) - strlen((char*)v.value)] = '\0';
		for (; pStr < (char*)newStr.value + strlen((char*)newStr.value); pStr++, ++i)
		{
			tmp[i] = *pStr;
		}
		i = 0;
		newStr = tmp;
	}
	delete[] tmp;
	return newStr;
}

var var::operatorMultiplication(const var& v)
{
	char buff[256];
	int count = 0;
	for (size_t i = 0; i < strlen((char*)value); i++)
	{
		if (findKeyForMultiplication((char*)v.value, strlen((char*)v.value), ((char*)value)[i]) != -1)
		{
			buff[count++] = ((char*)value)[i];
		}
	}
	buff[count] = '\0';
	return buff;
}

var var::operatorDivision(const var& v)
{
	char buff[256];
	int count = 0;
	for (size_t i = 0; i < strlen((char*)value); i++)
	{
		if (findKeyForDivision((char*)v.value, strlen((char*)v.value), ((char*)value)[i]) != -1)
		{
			buff[count++] = ((char*)value)[i];
		}
	}
	buff[count] = '\0';
	return buff;
}

bool var::operatorLess(const var& v)
{
	if (*this == v)
		return false;
	else if (strcmp((char*)value, (char*)v.value) < NULL)
		return true;
	else
		return false;
}

bool var::operatorEqual(const var& v)
{
	return (strcmp((char*)value, (char*)v.value) != NULL) ? false : true;
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

var var::operator-(const var& v)
{
	switch (type)
	{
	case _INT:
		switch (v.type)
		{
		case _INT:	  return var(*(int*)value - *(int*)v.value);
		case _DOUBLE: return var((int)(*(int*)value - *(double*)v.value));
		case _STRING: return var(*(int*)value - str_to_int((char*)v.value));
		}
		break;
	case _DOUBLE:
		switch (v.type)
		{
		case _INT:	  return var(*(double*)value - *(int*)v.value);
		case _DOUBLE: return var((*(double*)value - *(double*)v.value));
		case _STRING: return var(*(double*)value - str_to_double((char*)v.value));
		}
		break;
	case _STRING:
		switch (v.type)
		{
		case _INT:	  return (eraseSubStr(std::to_string(*(int*)v.value).data()));
		case _DOUBLE: return (eraseSubStr(std::to_string(*(double*)v.value).data()));
		case _STRING: return (eraseSubStr(v));
		}
		break;
	default:
		*this = v;
		break;
	}
}

var var::operator-=(const var& v)
{
	return *this = *this - v;
}

var var::operator*(const var& v)
{
	switch (type)
	{
	case _INT:
		switch (v.type)
		{
		case _INT:	  return var(*(int*)value * *(int*)v.value);
		case _DOUBLE: return var((int)(*(int*)value * *(double*)v.value));
		case _STRING:
			int tmp = str_to_int((char*)v.value);
			if (tmp <= 0)
				return var(*(int*)value * 1);
			else
				return var(*(int*)value * str_to_int((char*)v.value));
		}
		break;
	case _DOUBLE:
		switch (v.type)
		{
		case _INT:	  return var(*(double*)value * *(int*)v.value);
		case _DOUBLE: return var((*(double*)value * *(double*)v.value));
		case _STRING:
			double tmp = str_to_int((char*)v.value);
			if (tmp <= 0)
				return var(*(double*)value * 1);
			else
				return var(*(double*)value * str_to_double((char*)v.value));
		}
		break;
	case _STRING:
		switch (v.type)
		{
		case _INT:	  return (operatorMultiplication(std::to_string(*(int*)v.value).data()));
		case _DOUBLE: return (operatorMultiplication(std::to_string(*(double*)v.value).data()));
		case _STRING: return (operatorMultiplication(v));
		}
		break;
	default:
		*this = v;
		break;
	}
}

var var::operator*=(const var& v)
{
	return *this = *this * v;
}

var var::operator/(const var& v)
{
	switch (type)
	{
	case _INT:
		switch (v.type)
		{
		case _INT:	  return var(*(int*)value / *(int*)v.value);
		case _DOUBLE: return var((int)(*(int*)value / *(double*)v.value));
		case _STRING:
			int tmp = str_to_int((char*)v.value);
			if (tmp <= 0)
				return var(*(int*)value / 1);
			else
				return var(*(int*)value / str_to_int((char*)v.value));
		}
		break;
	case _DOUBLE:
		switch (v.type)
		{
		case _INT:	  return var(*(double*)value / *(int*)v.value);
		case _DOUBLE: return var((*(double*)value / *(double*)v.value));
		case _STRING:
			double tmp = str_to_int((char*)v.value);
			if (tmp <= 0)
				return var(*(double*)value / 1);
			else
				return var(*(double*)value / str_to_double((char*)v.value));
		}
		break;
	case _STRING:
		switch (v.type)
		{
		case _INT:	  return (operatorDivision(std::to_string(*(int*)v.value).data()));
		case _DOUBLE: return (operatorDivision(std::to_string(*(double*)v.value).data()));
		case _STRING: return (operatorDivision(v));
		}
		break;
	default:
		*this = v;
		break;
	}
}

var var::operator/=(const var& v)
{
	return *this = *this / v;
}

bool var::operator<(const var& v)
{
	switch (type)
	{
	case _INT:
		switch (v.type)
		{
		case _INT:	  return (*(int*)value < *(int*)v.value) ? true : false;
		case _DOUBLE: return ((*(int*)value < *(double*)v.value)) ? true : false;
		case _STRING: return (*(int*)value < str_to_int((char*)v.value)) ? true : false;
		}
		break;
	case _DOUBLE:
		switch (v.type)
		{
		case _INT:	  return (*(double*)value < *(int*)v.value) ? true : false;
		case _DOUBLE: return ((*(double*)value < *(double*)v.value)) ? true : false;
		case _STRING: return (*(double*)value < str_to_double((char*)v.value)) ? true : false;
		}
		break;
	case _STRING:
		switch (v.type)
		{
		case _INT:	  return (operatorLess(std::to_string(*(int*)v.value).data()));
		case _DOUBLE: return (operatorLess(std::to_string(*(double*)v.value).data()));
		case _STRING: return (operatorLess(v));
		}
		break;
	default:
		*this = v;
		break;
	}
}

bool var::operator>(const var& v)
{
	if (*this == v)
		return false;
	return !(*this < v);
}

bool var::operator<=(const var& v)
{
	if (*this == v)
		return true;
	else if (*this < v)
		return true;
	else
		return false;
}

bool var::operator>=(const var& v)
{
	if (*this == v)
		return true;
	else if (*this > v)
		return true;
	else
		return false;
}

bool var::operator==(const var& v)
{
	switch (type)
	{
	case _INT:
		switch (v.type)
		{
		case _INT:	  return (*(int*)value == *(int*)v.value) ? true : false;
		case _DOUBLE: return ((int)(*(int*)value == *(double*)v.value)) ? true : false;
		case _STRING: return (*(int*)value == str_to_int((char*)v.value)) ? true : false;
		}
		break;
	case _DOUBLE:
		switch (v.type)
		{
		case _INT:	  return (*(double*)value == *(int*)v.value) ? true : false;
		case _DOUBLE: return ((*(double*)value == *(double*)v.value)) ? true : false;
		case _STRING: return (*(double*)value == str_to_double((char*)v.value)) ? true : false;
		}
		break;
	case _STRING:
		switch (v.type)
		{
		case _INT:	  return (operatorEqual(std::to_string(*(int*)v.value).data()));
		case _DOUBLE: return (operatorEqual(std::to_string(*(double*)v.value).data()));
		case _STRING: return (operatorEqual(v));
		}
		break;
	default:
		*this = v;
		break;
	}
}

bool var::operator!=(const var& v)
{
	return !(*this == v);
}

char& var::operator[](size_t index)
{
	return ((char*)value)[index];
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
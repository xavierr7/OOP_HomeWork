#pragma once

template<class T>
bool asc(T a, T b)
{
	return a > b;
}

template<class T>
bool desc(T a, T b)
{
	return a < b;
}

template<class T>
bool evenFirst(T a, T b)
{
	if (a % 2 == 1 && b % 2 == 0)
	{
		return false;
	}
	if (a % 2 == 0 && b % 2 == 1)
	{
		return true;
	}
	return asc(a, b);
}



#pragma once

template<class T>
int findKeyForMultiplication(T* arr, int size, T key)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == key)
			return i;
	}
	return -1;
}

template<class T>
int findKeyForDivision(T* arr, int size, T key)
{
	int i = 0;
	for (; i < size; i++)
	{
		if (arr[i] == key)
			return -1;
	}
	return i;
}
#pragma once
#include<iostream>
#include <windows.h>

using namespace std;


template<class T>
void addElemArray(T*& arr, int& size, T elem)
{
	T* temp = new T[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}
	temp[size] = elem;
	size++;
	delete[] arr;
	arr = temp;
}

template<class T>
void delElemArray(T*& arr, int& size, int pos)
{
	T* temp = new T[size - 1];
	for (size_t i = 0; i < pos; i++)
	{
		temp[i] = arr[i];
	}
	for (size_t i = pos + 1; i < size; i++)
	{
		temp[i - 1] = arr[i];
	}
	size--;
	delete[] arr;
	arr = temp;
}


enum HorizontalAlignment
{
	Center, Left, Right
};

enum ConsoleColor
{
	Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6, LightGray = 7, DarkGray = 8,
	LightBlue = 9, LightGreen = 10, LightCyan = 11, LightRed = 12, LightMagenta = 13, Yellow = 14, White = 15
};

void SetColor(int text, int background);

void gotoxy(int x, int y);
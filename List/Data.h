#pragma once

template<class T>
class Data
{
public:
	T value;
	Data* next = nullptr;
	Data* prev = nullptr;
};

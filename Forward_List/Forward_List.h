#pragma once
#include <iostream>
#include<initializer_list>
#include<cassert>
#include"Data.h"

using namespace std;

template<class T>
class Forward_List
{
	Data<T>* first = nullptr;
	Data<T>* last  = nullptr;
	size_t   size  = 0;

public:
	 Forward_List() {}
	 Forward_List(initializer_list<T> list);
	~Forward_List();
	 Forward_List(const Forward_List<T>& list);

	void push_back(const T& value);
	void push_front(const T& value);
	void insert(const T& value, size_t ind);

	void pop_back();
	void pop_front();
	void remove(size_t ind);

	T& front() const;
	T& back() const;
	T& at(size_t ind) const;

	Forward_List<T>& operator =  (const Forward_List<T>& list);
	Forward_List<T>  operator *  (const Forward_List<T>& list);
	Forward_List<T>  operator +  (const Forward_List<T>& list);
	void             operator += (const Forward_List<T>& list);

	bool operator ==  (const Forward_List<T>& list)const;
	bool operator !=  (const Forward_List<T>& list)const;

	T& operator[] (size_t ind)const;

	bool   isEmpty()const;
	size_t length()const;
	void   clear();
	void   print();
	void   reverse();
	void   sort(bool(*method)(T a, T b));
};

template<class T>
Forward_List<T>::Forward_List(initializer_list<T> list)
{
	for (T l : list)
	{
		this->push_back(l);
	}
}

template<class T>
Forward_List<T>::~Forward_List()
{
	this->clear();
}

template<class T>
Forward_List<T>::Forward_List(const Forward_List<T>& list)
{
	Data<T>* pos = list.first;
	while (pos)
	{
		this->push_back(pos->value);
		pos = pos->next;
	}
}

template<class T>
void Forward_List<T>::push_back(const T& value)
{
	if (size == 0)
	{
		last = new Data<T>;
		last->value = value;
		first = last;
	}
	else
	{
		last->next = new Data<T>;
		last->next->value = value;
		last = last->next;
	}
	++size;
}

template<class T>
void Forward_List<T>::push_front(const T& value)
{
	if (size == 0)
	{
		first = new Data<T>;
		first->value = value;
		last = first;
	}
	else
	{
		Data<T>* temp = new Data<T>;
		temp->value = value;
		temp->next = first;
		first = temp;
	}
	++size;
}

template<class T>
void Forward_List<T>::insert(const T& value, size_t ind)
{
	assert(ind >= 0 && ind <= size);
	if (ind == 0)
	{
		this->push_front(value);
	}
	else if (ind == size)
	{
		this->push_back(value);
	}
	else
	{
		Data<T>* pos = first;
		for (size_t i = 0; i < ind - 1; ++i)
		{
			pos = pos->next;
		}
		Data<T>* temp = new Data<T>;
		temp->value = value;
		temp->next = pos->next;
		pos->next = temp;
		++size;
	}
}

template<class T>
void Forward_List<T>::pop_back()
{
	assert(size > 0);
	Data<T>* pos = first;
	for (size_t i = 0; i < size - 2; ++i)
	{
		pos = pos->next;
	}
	delete last;
	last = pos;
	--size;
	if (size == 0)
	{
		last = first = nullptr;
	}
	else
	{
		last->next = nullptr;
	}
}

template<class T>
void Forward_List<T>::pop_front()
{
	assert(size > 0);
	Data<T>* temp = first;
	first = first->next;
	delete temp;
	--size;
	if (size == 0)
	{
		last = nullptr;
	}
}

template<class T>
void Forward_List<T>::remove(size_t ind)
{
	assert(ind >= 0 && ind < size);
	if (ind == 0)
	{
		this->pop_front();
	}
	else if (ind == size - 1)
	{
		this->pop_back();
	}
	else
	{
		Data<T>* pos = first;
		for (size_t i = 0; i < ind - 1; ++i)
		{
			pos = pos->next;
		}
		Data<T>* temp = pos->next;
		pos->next = pos->next->next;
		delete temp;
		--size;
	}
}

template<class T>
T& Forward_List<T>::front() const
{
	assert(size > 0);
	return first->value;
}

template<class T>
T& Forward_List<T>::back() const
{
	assert(size > 0);
	return last->value;
}

template<class T>
T& Forward_List<T>::at(size_t ind) const
{
	assert(ind >= 0 && ind < size);
	Data<T>* pos = first;
	for (size_t i = 0; i < ind; ++i)
	{
		pos = pos->next;
	}
	return pos->value;
}

template<class T>
Forward_List<T>& Forward_List<T>::operator=(const Forward_List<T>& list)
{
	if (this == &list)
		return *this;
	if (size > 0)
		this->clear();

	Data<T>* pos = list.first;
	while (pos)
	{
		this->push_back(pos->value);
		pos = pos->next;
	}
	return *this;
}

template<class T>
Forward_List<T> Forward_List<T>::operator*(const Forward_List<T>& list)
{
	Data<T>* posThis = this->first;
	Data<T>* posList = list.first;

	Forward_List<T> temp;
	Data<T>* posTemp = temp.first;


	while (posThis)
	{
		while (posList)
		{
			if (posThis->value == posList->value)
			{
				bool flag = false;
				while (posTemp)
				{
					if (posThis->value == posTemp->value)
					{
						flag = true;
						break;
					}
					posTemp = posTemp->next;
				}
				posTemp = temp.first;

				if (flag)
					break;
				else
				temp.push_back(posThis->value);

				break;
			}
			posList = posList->next;
		}
		posList = list.first;
		posThis = posThis->next;
	}

	return temp;
}

template<class T>
Forward_List<T> Forward_List<T>::operator+(const Forward_List<T>& list)
{
	Forward_List<T> temp(*this);
	Data<T>* pos = list.first;
	while (pos)
	{
		temp.push_back(pos->value);
		pos = pos->next;
	}
	return temp;
}

template<class T>
void Forward_List<T>::operator+=(const Forward_List<T>& list)
{
	*this = *this + list;
}

template<class T>
bool Forward_List<T>::operator==(const Forward_List<T>& list) const
{
	if (this->size != list.size)
		return false;
	else
	{
		Data<T>* posThis = this->first;
		Data<T>* posList = list.first;
		while (posThis)
		{
			if (posThis->value != posList->value)
			{
				return false;
			}
			else
			{
				posThis = posThis->next;
				posList = posList->next;
			}
		}
		return true;
	}
}

template<class T>
bool Forward_List<T>::operator!=(const Forward_List<T>& list) const
{
	return !(*this == list);
}

template<class T>
T& Forward_List<T>::operator[](size_t ind) const
{
	assert(ind >= 0 && ind < size);
	return this->at(ind);
}

template<class T>
bool Forward_List<T>::isEmpty() const
{
	return size == 0;
}

template<class T>
size_t Forward_List<T>::length() const
{
	return size;
}

template<class T>
void Forward_List<T>::clear()
{
	Data<T>* pos = first;
	while (pos)
	{
		first = first->next;
		delete pos;
		pos = first;
	}
	last = nullptr;
	size = 0;
}

template<class T>
void Forward_List<T>::print()
{
	Data<T>* pos = first;
	while (pos)
	{
		cout << pos->value << " ";
		pos = pos->next;
	}
	cout << endl;
}

template<class T>
void Forward_List<T>::reverse()
{
	Data<T>* posFromBegin = first;
	Data<T>* posFromEnd = first;
	for (size_t i = 0; i < size / 2; ++i)
	{
		for (size_t j = 1; j < size - i; ++j)
		{
			posFromEnd = posFromEnd->next;
		}
		swap(posFromBegin->value, posFromEnd->value);
		posFromBegin = posFromBegin->next;
		posFromEnd = first;
	}
}

template<class T>
void Forward_List<T>::sort(bool(*method)(T a, T b))
{
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size - 1 - i; j++)
		{
			if (method(this->operator[](j), this->operator[](j + 1)))
			{
				swap(this->operator[](j), this->operator[](j + 1));
			}
		}
	}
}
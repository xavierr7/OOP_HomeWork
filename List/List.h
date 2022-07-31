#pragma once
#include <iostream>
#include "Data.h"
#include<initializer_list>
#include<cassert>
#include "Functions.h"

using namespace std;

template<class T>
class List
{
	Data<T>* first = nullptr;
	Data<T>* last = nullptr;
	size_t   size = 0;

public:
	List() {}
	List(initializer_list<T> list);
	~List();
	List(const List<T>& list);

	void push_back(const T& value);
	void push_front(const T& value);
	void insert(const T& value, size_t ind);

	void pop_back();
	void pop_front();
	void remove(size_t ind);

	T& front() const;
	T& back() const;
	T& at(size_t ind) const;

	T& operator[](size_t ind) const;

	List<T>& operator =  (const List<T>& list);
	List<T>  operator *  (const List<T>& list);
	List<T>  operator +  (const List<T>& list);
	void     operator += (const List<T>& list);

	bool operator == (const List<T>& list) const;
	bool operator != (const List<T>& list) const;

	bool   isEmpty() const;
	size_t length() const;
	void   clear();
	void   print() const;

	void sort(bool(*method)(T a, T b));
	void reverse();
	void splice(List<T>& other, size_t ind, size_t count);
};

template<class T>
List<T>::List(initializer_list<T> list)
{
	for (T l : list)
	{
		this->push_back(l);
	}
}

template<class T>
List<T>::~List()
{
	this->clear();
}

template<class T>
List<T>::List(const List<T>& list)
{
	Data<T>* pos = list.first;
	while (pos)
	{
		this->push_back(pos->value);
		pos = pos->next;
	}
}

template<class T>
void List<T>::push_back(const T& value)
{
	if (size == 0)
	{
		first = new Data<T>;
		first->value = value;
		last = first;
	}
	else
	{
		last->next = new Data<T>;
		last->next->value = value;
		last->next->prev = last;
		last = last->next;
	}
	++size;
}

template<class T>
void List<T>::push_front(const T& value)
{
	if (size == 0)
	{
		first = new Data<T>;
		first->value = value;
		last = first;
	}
	else
	{
		first->prev = new Data<T>;
		first->prev->value = value;
		first->prev->next = first;
		first = first->prev;
	}
	++size;
}

template<class T>
void List<T>::insert(const T& value, size_t ind)
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
		Data<T>* pos;
		if (ind <= size / 2)
		{
			pos = first;
			for (size_t i = 0; i < ind - 1; i++)
			{
				pos = pos->next;
			}
		}
		else
		{
			pos = last;
			for (size_t i = 0; i < size - ind; i++)
			{
				pos = pos->prev;
			}
		}
		Data<T>* temp = new Data<T>;
		temp->value = value;
		temp->next = pos->next;
		temp->next->prev = temp;
		temp->prev = pos;
		pos->next = temp;
		++size;
	}
}

template<class T>
void List<T>::pop_back()
{
	assert(size > 0);

	if (size == 1)
	{
		delete first;
		first = last = nullptr;
	}
	else
	{
		last = last->prev;
		delete last->next;
		last->next = nullptr;
	}
	--size;
}

template<class T>
void List<T>::pop_front()
{
	assert(size > 0);

	if (size == 1)
	{
		delete first;
		first = last = nullptr;
	}
	else
	{
		first = first->next;
		delete first->prev;
		first->prev = nullptr;
	}
	--size;
}

template<class T>
void List<T>::remove(size_t ind)
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
		Data<T>* pos;
		if (ind <= size / 2)
		{
			pos = first;
			for (size_t i = 0; i < ind; i++)
			{
				pos = pos->next;
			}
		}
		else
		{
			pos = last;
			for (size_t i = 0; i < size - ind - 1; i++)
			{
				pos = pos->prev;
			}
		}
		pos->prev->next = pos->next;
		pos->next->prev = pos->prev;
		delete pos;
		--size;
	}
}

template<class T>
T& List<T>::front() const
{
	assert(size > 0);
	return first->value;
}

template<class T>
T& List<T>::back() const
{
	assert(size > 0);
	return last->value;
}

template<class T>
T& List<T>::at(size_t ind) const
{
	assert(ind >= 0 && ind < size);
	Data<T>* pos;
	if (ind < size / 2)
	{
		pos = first;
		for (size_t i = 0; i < ind; i++)
		{
			pos = pos->next;
		}
	}
	else
	{
		pos = last;
		for (size_t i = 0; i < size - ind - 1; i++)
		{
			pos = pos->prev;
		}
	}
	return pos->value;
}

template<class T>
List<T>& List<T>::operator=(const List<T>& list)
{
	if (this == &list)
		return *this;

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
List<T> List<T>::operator*(const List<T>& list)
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
List<T> List<T>::operator+(const List<T>& list)
{
	List<T> temp(*this);
	Data<T>* pos = list.first;
	while (pos)
	{
		temp.push_back(pos->value);
		pos = pos->next;
	}
	return temp;
}

template<class T>
void List<T>::operator+=(const List<T>& list)
{
	*this = *this + list;
}

template<class T>
bool List<T>::operator==(const List<T>& list) const
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
bool List<T>::operator!=(const List<T>& list) const
{
	return !(*this == list);
}

template<class T>
T& List<T>::operator[](size_t ind) const
{
	assert(ind >= 0 && ind < size);
	return this->at(ind);
}

template<class T>
bool List<T>::isEmpty() const
{
	return false;
}

template<class T>
size_t List<T>::length() const
{
	return size;
}

template<class T>
void List<T>::clear()
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
void List<T>::print() const
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
void List<T>::reverse()
{
	Data<T>* pos_front = first;
	Data<T>* pos_back = last;
	for (size_t i = 0; i < size / 2; i++)
	{
		swap(pos_front->value, pos_back->value);
		pos_front = pos_front->next;
		pos_back = pos_back->prev;
	}
}

template<class T>
void List<T>::splice(List<T>& other, size_t ind, size_t count)
{
	if (ind >= 0 && ind < other.size && (count > 0 && count <= other.size))
	{
		if (other.size == 1)
		{
			last->next = other[ind];
			last->next->prev = last;
			last = last->next;
			last->next = nullptr;
			other.first = nullptr;
			other.last = nullptr;
		}

		if ((ind + count) > other.size - 1)
			return;

		last->next = other[ind];
		last->next->prev = last;
		last = other[ind + count];
		last->prev = other[(ind + count) - 1];
		last->next = nullptr;

		if (ind == 0 && count == other.size)
		{
			other.first->next = nullptr;
			other.first->prev = nullptr;
			other.first = nullptr;
			other.last->next = nullptr;
			other.last->prev = nullptr;
			other.last = nullptr;
			return;
		}

		if ((ind + count) == other.size - 1)
		{
			other.last->next = other[ind - 1];
			other.last->next->prev = last;
			other.last = last->next;
			other.last->next = nullptr;
			return;
		}
		
		if (ind == 0 && count < other.size - 1)
		{
			if (count + 1 == other.size - 1)
			{

			}
			else
			{

			}
		}
		
	}
}


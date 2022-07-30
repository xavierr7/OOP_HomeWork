#pragma once

#include "Functions.h"
#include"Data.h"
#include<initializer_list>
#include<cassert>

using namespace std;

template<class T>
class Queue
{
	Data<T>* first = nullptr;
	Data<T>* last = nullptr;
	size_t   size = 0;

public:
	Queue() {}
	Queue(initializer_list<T> init);
	~Queue();
	Queue(const Queue& q);
	Queue& operator = (const Queue& q);
	void enqueue(const T& value);
	void dequeue();
	T peek() const;
	size_t length() const;
	bool isEmpty() const;
	void clear();
	void print() const;
	void print(int x, int y) const;
	void ring();
};

template<class T>
Queue<T>::Queue(initializer_list<T> init)
{
	for (T i : init)
	{
		enqueue(i);
	}
}

template<class T>
Queue<T>::~Queue()
{
	clear();
}

template<class T>
Queue<T>::Queue(const Queue& q)
{
	Data<T>* temp = q.first;
	while (temp)
	{
		this->enqueue(temp->value);
		temp = temp->next;
	}
}

template<class T>
Queue<T>& Queue<T>::operator=(const Queue& q)
{
	if (this == &q)
		return *this;
	if (size > 0)
		this->clear();

	Data<T>* temp = q.first;
	while (temp)
	{
		this->enqueue(temp->value);
		temp = temp->next;
	}
	return *this;
}

template<class T>
void Queue<T>::enqueue(const T& value)
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
		last = last->next;
	}
	size++;
}

template<class T>
void Queue<T>::dequeue()
{
	if (size > 0)
	{
		Data<T>* temp = first;
		first = first->next;
		delete temp;
		size--;
		last = (size == 0) ? nullptr : last;
	}
}

template<class T>
T Queue<T>::peek() const
{
	assert(size > 0);
	return first->value;
}

template<class T>
size_t Queue<T>::length() const
{
	return size;
}

template<class T>
bool Queue<T>::isEmpty() const
{
	return size == 0;
}

template<class T>
void Queue<T>::clear()
{
	/*while (size)
		dequeue();*/

	Data<T>* temp = first;
	while (temp)
	{
		first = first->next;
		delete temp;
		temp = first;
	}
	last = nullptr;
	size = 0;
}

template<class T>
void Queue<T>::print() const
{
	Data<T>* temp = first;
	while (temp)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}

template<class T>
void Queue<T>::print(int x, int y) const
{
	int dy = y;
	Data<T>* temp = first;
	for (size_t i = 0; i < size; i++)
	{

		if (size <= 10)
		{
			gotoxy(x, dy++);
			cout << temp->value;
		}
		else
		{
			if (i < size - 10)
			{
				if (i == size - 10)
				{
					gotoxy(x, dy++);
					cout << "........^........" << endl;
				}
			}
			else
			{
				gotoxy(x, dy++);
				cout << temp->value;
			}
		}
		temp = temp->next;
	}
	cout << endl;
}

template<class T>
void Queue<T>::ring()
{
	/*enqueue(first->value);
	dequeue();*/

	if (size > 1)
	{
		Data<T>* temp = first;
		first = first->next;
		last->next = temp;
		last = temp;
		last->next = nullptr;
	}
}
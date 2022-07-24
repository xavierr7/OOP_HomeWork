#pragma once
#include <iostream>
#include<cassert>

using namespace std;

template<class T, size_t size>
class DynamicStack
{
	T* data = nullptr;
	int top = 0;

public:
	DynamicStack(){}
	~DynamicStack();
	DynamicStack(const DynamicStack& st);
	DynamicStack& operator = (const DynamicStack& st);
	bool push(const T& value);
	T peek() const;
	void pop();
	size_t length()const;
	bool isEmpty()const;
	bool isFull()const;
	void clear();
	void print()const;
};

template<class T, size_t size>
DynamicStack<T, size>::~DynamicStack()
{
	delete[]data;
}

template<class T, size_t size>
DynamicStack<T, size>::DynamicStack(const DynamicStack& st)
{
	top = st.top;
	data = new T [top];
	for (size_t i = 0; i < top; i++)
	{
		data[i] = st.data[i];
	}
}

template<class T, size_t size>
DynamicStack<T, size>& DynamicStack<T, size>::operator=(const DynamicStack& st)
{
	if (this == &st)
		return *this;
	if (data)
		delete[] data;

	top = st.top;
	data = new T[top];
	for (size_t i = 0; i < top; i++)
	{
		data[i] = st.data[i];
	}
	return *this;
}

template<class T, size_t size>
bool DynamicStack<T, size>::push(const T& value)
{
	if (top < size)
	{
		if (top == 0)
		{
			data = new T[++top];
			data[top - 1] = value;
		}
		else
		{
			DynamicStack<T, size> tmp(*this);
			delete[] data;
			data = new T[++top];
			for (size_t i = 0; i < tmp.top; i++)
			{
				data[i] = tmp.data[i];
			}
			data[top - 1] = value;
		}
		return true;
	}
	return false;
}

template<class T, size_t size>
T DynamicStack<T, size>::peek() const
{
	assert(top > 0);
	return data[top - 1];
}

template<class T, size_t size>
void DynamicStack<T, size>::pop()
{
	if (top > 0)
	{
		DynamicStack<T, size> tmp(*this);
		delete[] data;
		data = new T[--top];
		for (size_t i = 0; i < top; i++)
		{
			data[i] = tmp.data[i];
		}
	}
}

template<class T, size_t size>
inline size_t DynamicStack<T, size>::length() const
{
	return top;
}

template<class T, size_t size>
inline bool DynamicStack<T, size>::isEmpty() const
{
	return top == 0;
}

template<class T, size_t size>
inline bool DynamicStack<T, size>::isFull() const
{
	return top == size;
}

template<class T, size_t size>
inline void DynamicStack<T, size>::clear()
{
	delete[]data;
	data = nullptr;
	top = 0;
}

template<class T, size_t size>
inline void DynamicStack<T, size>::print() const
{
	for (size_t i = 0; i < top; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}


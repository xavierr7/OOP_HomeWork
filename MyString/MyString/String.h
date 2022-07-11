#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class String
{
	char* str;
	size_t length;
	static size_t countOfCreatedStrings;

	void makeNewStr(const char*);

public:
	String();
	String(const char* str);

	~String();

	String(const String& other);
	String(String&& other); 

	String& operator = (const String& other);
	String operator +(const String& other);
	String operator +(const char* str);// насправді в ньому сенсу ніби як немає, бо якщо додати до об'єкту классу звичайний рядок, то компілятор сприйме цей рядок як об'єкт цього класу
									   // і під час виконання дії потрапить у перевантажений оператор "+" об'єкту з обє'ктом. Тому я думаю що усі інші оператори немає 
									   // сенсу робити в такому вигляді(але якщо потрібно я звісно можу зробити, просто це буде суцільний копіпаст, там нічим не відрізняється реалізація, зайвий код)
	String operator *(int number);
	String operator +=(const String& other);
	bool operator == (const String& other);
	bool operator != (const String& other);
	bool operator > (const String& other);
	bool operator < (const String& other);
	bool operator<=(const String& other);
	bool operator >= (const String& other);
	char& operator [] (size_t index);
	friend std::ostream& operator << (std::ostream& out, const String& str);
	friend std::istream& operator >> (std::istream& out, String& str);

	size_t Length();
	static size_t GetCountOfCreatedStrings();

};

String operator*(int n, String str);
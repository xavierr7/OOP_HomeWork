#pragma once
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class String
{
	char* str;
	size_t length;
	static size_t countOfCreatedStrings;
public:
	// Конструктори
	//String(); // Конструтор по дефолту який ініціалізує рядок як - nullptr, а розмір як - 0
	String() : String(80) {}// *
	explicit String(int length);// * це для завдання яке в домашньому, але потім заміню на те, що робив для власного користування. Не думаю, що при звичній роботі, потрібно по дефолту створювати строки розміром 80 символів
	String(const char* str);
	~String();
	String(const String& other); // конструктор копіювання
	String(String&& other); // конструктор переносу для оптимізації
	// Перевантажені  оператори
	String& operator = (const String& other);
	String operator +(const String& other);
	String operator *(int number);
	bool operator == (const String& other);
	bool operator != (const String& other);
	char& operator [] (size_t index);
	friend std::ostream& operator << (std::ostream& out, const String& str);
	friend std::istream& operator >> (std::istream& out, String& str);
	//Методи
	size_t Length();
	static size_t GetCountOfCreatedStrings();
	void SetStr();
	void SetStr(const char* str);
	void GetStr();
};

String operator*(int n, String str);


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
	// ������������
	//String(); // ���������� �� ������� ���� �������� ����� �� - nullptr, � ����� �� - 0
	String() : String(80) {}// *
	explicit String(int length);// * �� ��� �������� ��� � ����������, ��� ���� ����� �� ��, �� ����� ��� �������� ������������. �� �����, �� ��� ������ �����, ������� �� ������� ���������� ������ ������� 80 �������
	String(const char* str);
	~String();
	String(const String& other); // ����������� ���������
	String(String&& other); // ����������� �������� ��� ����������
	// ������������  ���������
	String& operator = (const String& other);
	String operator +(const String& other);
	String operator *(int number);
	bool operator == (const String& other);
	bool operator != (const String& other);
	char& operator [] (size_t index);
	friend std::ostream& operator << (std::ostream& out, const String& str);
	friend std::istream& operator >> (std::istream& out, String& str);
	//������
	size_t Length();
	static size_t GetCountOfCreatedStrings();
	void SetStr();
	void SetStr(const char* str);
	void GetStr();
};

String operator*(int n, String str);


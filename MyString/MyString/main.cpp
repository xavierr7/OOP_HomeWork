#include <iostream>
#include "String.h"
using namespace std;

int main()
{

	String str1("Hello");
	String str2("World");


	String result;
	result = str1 + str2;
	
	result.Print();

	return 0;
}
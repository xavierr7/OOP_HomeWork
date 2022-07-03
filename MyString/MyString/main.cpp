#include "String.h"


int main()
{

	String str1 = "Hello";
	String str2("World");


	String result = str1 + str2;
	
	
	cout << result << endl << endl;

	String tmp;

	cin >> tmp;

	cout << (tmp = tmp + str1 + str2);

	return 0;
}
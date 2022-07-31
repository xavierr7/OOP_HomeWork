#include "Forward_List.h"


int main()
{
	Forward_List<int> l1 = {1,2,3,4,5};
	Forward_List<int> l2 = {5,5,6,7,8,9,10};

	Forward_List<int> l3 = l1 + l2;
	l3.print();
	cout << endl;

	l1 += l2;
	l1.print();
	cout << endl;

	cout << (l1 == l2) << endl;
	cout << (l1 != l2) << endl;

	l1.reverse();
	l1.print();
	cout << endl;

	Forward_List<int> l4;
	l4 = l1 * l2;
	l4.print();

	return 0;
}
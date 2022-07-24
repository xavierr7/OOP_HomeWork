#include "DynamicStack.h"

int main()
{

	DynamicStack<int, 5> st;


	st.print();
	st.push(10);
	st.push(5);
	st.push(20);
	st.print();
	cout << st.peek() << endl;
	st.pop();
	st.print();
	st.push(50);
	st.push(50);
	st.push(50);
	st.push(50);
	st.push(50);
	st.push(50);
	st.print();

	DynamicStack<int, 5> st1(st);

	st1.print();

	return 0;
}


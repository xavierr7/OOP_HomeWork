#include <string>
#include "../DynamicStack/DynamicStack.h"

int main()
{
	DynamicStack<char, 1024> stack;

	string str = "({x-y-z} * [x + 2y] - (z + 4x));";
	string incorrectStr;

	for (size_t i = 0; str[i] != ';'; ++i)
	{
		char tmp;
		if (str[i] == ')' || str[i] == ']' || str[i] == '}')
		{
			tmp = str[i];

			if (tmp == ')')
				--tmp;
			else
				tmp -= 2;

			if (stack.peek() == tmp)
				stack.pop();
			else
				break;
		}
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
			stack.push(str[i]);

		incorrectStr += str[i];
	}

	if (!stack.isEmpty())
		cout << "Your string is incorrect: " << incorrectStr << endl;
	else
		cout << "Your string is correct!\n";

	return 0;
}
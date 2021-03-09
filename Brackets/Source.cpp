#include <iostream>
#include <string>
#include <vector>


void Stack()
{

	std::string pro;
	while(std::cin >> pro)
	{
		int flag = 0, top = 0;
		int depth = 0;
		int l = pro.size();
		std::vector <char> arr(l);
		for (int i = 0; i < l; i++)
		{
			if ((pro[i] == '[') || (pro[i] == '('))
			{
				depth++;
			}
			else
			{
				depth--;
			}

			if ((pro[i] == '(') || (pro[i] == '['))
			{
				arr[top++] = pro[i];
			}

			if ((pro[i] == ')') && (arr[top - 1] == '(') && (top >= 0))
			{
				top--;
			}
			else if ((pro[i] == ')') && (arr[top - 1] != '('))
			{
				flag++;
			}

			if ((pro[i] == ']') && (arr[top - 1] == '[') && (top >= 0))
			{
				top--;
			}
			else if ((pro[i] == ']') && (arr[top - 1] != '['))
			{
				flag++;
			}
		}
		if ((flag == 0) && (depth == 0))
		{
			std::cout << "TRUE " << std::endl;
		}
		else
		{
			std::cout << "FALSE " << std::endl;
		}
	}
}

int main()
{
		Stack();
}
#include <fstream>
#include <string>
#include <iostream>
using namespace std;


void Stack()
{
	string pro;
	while(cin >> pro)
	{
		int flag = 0, top = 0;
		int depth = 0;
		int l = pro.size();
		char *arr = new char[l];
		for (int i = 0; i < l; i++)
		{
			if ((pro[i] == '[') || (pro[i] == '(') || (pro[i] == '{'))
			{
				depth++;
				arr[top++] = pro[i];
			}
			else
			{
				depth--;
			}

			if (((pro[i] == ')') && (arr[top - 1] == '(') ||
				 (pro[i] == ']') && (arr[top - 1] == '[') || 
				 (pro[i] == '}') && (arr[top - 1] == '{'))&& 
				 (top >= 0))
			{
				top--;
			}
			else if (((pro[i] == ')') && (arr[top - 1] != '(')) ||
					((pro[i] == ']') && (arr[top - 1] != '[')) ||
					((pro[i] == '}') && (arr[top - 1] != '{')))
			{
				flag++;
			}

			
		}
		if ((flag == 0) && (depth == 0))
		{
			cout << "TRUE " << endl;
		}
		else
		{
			cout << "FALSE " << endl;
		}
	}
}

int main()
{
		Stack();
}
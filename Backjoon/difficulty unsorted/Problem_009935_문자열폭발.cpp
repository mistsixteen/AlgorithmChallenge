//Backjoon Problem No.9935
//https://www.acmicpc.net/problem/9935
//Mist16, 2022-04-06

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	string base, target;
	stack<char> cStack;
	stack<int> iStack;
	cin >> base >> target;
	int targetSize = target.size();

	for (char c : base)
	{
		if (cStack.empty())
		{
			if (c == target[0])
			{
				iStack.push(1);
			}
			else
				iStack.push(0);
			cStack.push(c);
		}
		else
		{
			int idx = iStack.top();
			if (c == target[idx])
			{
				iStack.push(idx + 1);
				cStack.push(c);
			}
			else if (c == target[0])
			{
				iStack.push(1);
				cStack.push(c);
			}
			else
			{
				iStack.push(0);
				cStack.push(c);
			}
		}

		if (iStack.top() == targetSize)
		{
			for (int i = 0; i < targetSize; i++)
			{
				iStack.pop();
				cStack.pop();
			}
		}
		
	}

	if (cStack.size() == 0)
	{
		cout << "FRULA";
		return 0;
	}

	char* result = new char[cStack.size() + 1];
	int idx = cStack.size() - 1;
	result[cStack.size()] = 0x00;

	while (!cStack.empty())
	{
		char c = cStack.top();
		result[idx] = c;
		idx--;
		cStack.pop();
	}

	cout << result;

	delete[] result;

	return 0;
}
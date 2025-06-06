//Backjoon Problem No.10773
//https://www.acmicpc.net/problem/10773
//Mist16, 2022-03-23
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int numTestCase = 0;
	int temp;
	unsigned long long result = 0;
	stack<int> jStack;

	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> numTestCase;

	for (int i = 0; i < numTestCase; i++)
	{
		cin >> temp;
		if (temp == 0)
		{
			jStack.pop();
		}
		else
		{
			jStack.push(temp);
		}
	}

	while (!jStack.empty())
	{
		temp = jStack.top();
		result += temp;
		jStack.pop();
	}

	cout << result;

	return 0;
}

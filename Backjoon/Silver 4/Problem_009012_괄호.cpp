//Backjoon Problem No.9012
//https://www.acmicpc.net/problem/9012
//Mist16, 2022-03-23
#include <iostream>
#include <string>
#include <stack>

using namespace std;


bool run(string testCase)
{
	int caseLevel = 1;
	stack<int> cases;

	for (char c : testCase)
	{
		if (c == '(')
		{
			cases.push(caseLevel++);
		}
		if (c == ')')
		{
			if (cases.empty())
				return false;
			caseLevel--;
			if (cases.top() != caseLevel)
				return false;			
			cases.pop();
		}
	}
	if (cases.empty())
		return true;
	return false;
}

int main()
{
	int numTestCase = 0;
	string tCase;
	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> numTestCase;

	for (int i = 0; i < numTestCase; i++)
	{
		cin >> tCase;
		if (run(tCase))
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}

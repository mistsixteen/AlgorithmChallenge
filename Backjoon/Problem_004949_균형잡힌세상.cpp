//Backjoon Problem No.4949
//https://www.acmicpc.net/problem/4949
//Mist16, 2022-03-23
#include <iostream>
#include <string>
#include <stack>

using namespace std;


bool run(string testCase)
{
	int minicaseLevel = 1;
	int bigcaseLevel = 1;
	stack<int> cases;

	for (char c : testCase)
	{
		if (c == '(')
		{
			cases.push(minicaseLevel + 100);
			minicaseLevel++;
		}
		if (c == ')')
		{
			if (cases.empty())
				return false;
			minicaseLevel--;
			if (cases.top() != (minicaseLevel + 100))
				return false;			
			cases.pop();
		}
		if (c == '[')
		{
			cases.push(bigcaseLevel + 200);
			bigcaseLevel++;
		}
		if (c == ']')
		{
			if (cases.empty())
				return false;
			bigcaseLevel--;
			if (cases.top() != (bigcaseLevel + 200))
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
	string tCase;
	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	while(true)
	{
		getline(cin, tCase);
		if (tCase.size() == 1 && tCase[0] == '.')
			break;
		if (run(tCase))
			cout << "yes\n";
		else
			cout << "no\n";
	}

	return 0;
}

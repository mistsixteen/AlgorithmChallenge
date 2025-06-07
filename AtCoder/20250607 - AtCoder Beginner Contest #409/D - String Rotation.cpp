//AtCoder Beginner Contest 409
//Task. D
//Mist16, 2025-06-07

#include <iostream>
#include <list>
#include <algorithm>
#include <vector>

using namespace std;

void run();
string GetSortedSubString(string str, int start, int end);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		run();
	}

	return 0;
}

void run()
{
	int n;
	string str;

	cin >> n;
	cin >> str;

	int targetA = -1;
	int targetB = -1;

	if (n == 1)
	{
		cout << str << endl;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (str[i] > str[i+1])
		{
			targetA = i;
			targetB = i+1;
			break;
		}
	}

	if (targetA == -1)
	{
		targetA = n - 2;
		targetB = n - 1;
	}

	for (int targetC = targetB; targetC < n; targetC++)
	{
		if(str[targetA] >= str[targetC])
		{
			targetB = targetC;
		}
		else
		{
			break;
		}
	}

	string resultString = str.substr(0, targetA)
		.append(str.substr(targetA+1, targetB - targetA))
		.append(str.substr(targetA, 1));

	if (n == targetB)
	{
		cout << resultString << endl;
	}
	else
	{
		cout << resultString.append(str.substr(targetB + 1)) << endl;
	}
	
}

string GetSortedSubString(string str, int start, int end)
{
	string a = str.substr(start + 1, end - start);

	a.append(str.substr(start, 1));

	return a;
}
//Backjoon Problem No.10828
//https://www.acmicpc.net/problem/10828
//Mist16, 2022-03-23
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	int numTestCase = 0;
	stack<int> q;
	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> numTestCase;

	for (int i = 0; i < numTestCase; i++)
	{
		string order;
		int iorder;
		cin >> order;
		if (order.compare("push") == 0)
		{
			cin >> iorder;
			q.push(iorder);
		}
		else if (order.compare("pop") == 0)
		{
			if (q.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << q.top() << endl;
				q.pop();
			}
		}
		else if (order.compare("size") == 0)
		{
			cout << q.size() << endl;
		}
		else if (order.compare("empty") == 0)
		{
			if (q.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (order.compare("top") == 0)
		{
			if (q.empty())
				cout << "-1\n";
			else
				cout << q.top() << endl;
		}
	}

	return 0;
}

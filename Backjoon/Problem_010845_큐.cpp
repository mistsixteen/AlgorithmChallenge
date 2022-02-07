//Backjoon Problem No.10845
//https://www.acmicpc.net/problem/10845
//Mist16, 2022-02-08
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
	int numTestCase = 0;
	queue<int> q;
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
				cout << q.front() << endl;
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
		else if (order.compare("front") == 0)
		{
			if (q.empty())
				cout << "-1\n";
			else
				cout << q.front() << endl;
		}
		else if (order.compare("back") == 0)
		{
			if (q.empty())
				cout << "-1\n";
			else
				cout << q.back() << endl;
		}

	}

	return 0;
}

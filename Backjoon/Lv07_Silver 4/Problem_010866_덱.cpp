//Backjoon Problem No.10866
//https://www.acmicpc.net/problem/10866
//Mist16, 2022-04-04
#include <iostream>
#include <list>
#include <string>

using namespace std;

int main()
{
	int numTestCase = 0;
	list<int> Deque;
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
		if (order.compare("push_front") == 0)
		{
			cin >> iorder;
			Deque.push_front(iorder);
		}
		else if (order.compare("push_back") == 0)
		{
			cin >> iorder;
			Deque.push_back(iorder);
		}
		else if (order.compare("pop_front") == 0)
		{
			if (Deque.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << Deque.front() << "\n";
				Deque.pop_front();
			}
		}
		else if (order.compare("pop_back") == 0)
		{
			if (Deque.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << Deque.back() << "\n";
				Deque.pop_back();
			}
		}
		else if (order.compare("size") == 0)
		{
			cout << Deque.size() << "\n";
		}
		else if (order.compare("empty") == 0)
		{
			if (Deque.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (order.compare("front") == 0)
		{
			if (Deque.empty())
				cout << "-1\n";
			else
				cout << Deque.front() << "\n";
		}
		else if (order.compare("back") == 0)
		{
			if (Deque.empty())
				cout << "-1\n";
			else
				cout << Deque.back() << "\n";
		}

	}

	return 0;
}

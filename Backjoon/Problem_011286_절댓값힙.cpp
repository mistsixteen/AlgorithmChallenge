//Backjoon Problem No.11286
//https://www.acmicpc.net/problem/11286
//Mist16, 2022-04-02

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct cmp
{
	bool operator()(int a, int b)
	{
		int c = a;
		int d = b;
		if (c < 0)
			c = c * -1;
		if (d < 0)
			d = d * -1;
		if (c == d)
			return a > b;
		else
			return c > d;
	}
};

int main()
{
	int N, temp;

	priority_queue<int, vector<int>, cmp> pq;

	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		if (temp == 0)
		{
			if (pq.empty())
				cout << "0\n";
			else
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else
			pq.push(temp);
	}

	return 0;
}
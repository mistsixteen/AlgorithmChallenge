//Backjoon Problem No.1927
//https://www.acmicpc.net/problem/1927
//Mist16, 2022-04-02

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct cmp
{
	bool operator()(unsigned long long a, unsigned long long b)
	{
		return a > b;
	}
};

int main()
{
	int N;
	unsigned long long temp;

	priority_queue<unsigned long long, vector<unsigned long long>, cmp> pq;

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
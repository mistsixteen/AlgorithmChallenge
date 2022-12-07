//Backjoon Problem No.11866
//https://www.acmicpc.net/problem/11866
//Mist16, 2022-04-03

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int N, K;
	int idx = 1;
	queue<int> yQueue;

	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		yQueue.push(i);
	}
	
	cout << "<";

	while (yQueue.size() > 1)
	{
		int top = yQueue.front();
		yQueue.pop();

		if (idx == K)
		{
			cout << top << ", ";
			idx = 1;
		}
		else
		{
			yQueue.push(top);
			idx++;
		}
	}

	cout << yQueue.front() << ">";

	return 0;
}
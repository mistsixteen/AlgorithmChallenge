//Backjoon Problem No.2164
//https://www.acmicpc.net/problem/2164
//Mist16, 2022-04-01

#include <iostream>
#include <queue>
using namespace std;


int main()
{
	int N;

	queue<int> cardQ;

	cin >> N;

	bool Flag = true;


	for (int i = 1; i <= N; i++)
	{
		cardQ.push(i);
	}

	while (cardQ.size() > 1)
	{
		if (Flag)
		{
			cardQ.pop();
		}
		else
		{
			int temp = cardQ.front();
			cardQ.pop();
			cardQ.push(temp);
		}
		Flag = !Flag;
	}

	cout << cardQ.front();

	return 0;
}
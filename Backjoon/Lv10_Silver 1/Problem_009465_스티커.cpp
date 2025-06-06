//Backjoon Problem No.9465
//https://www.acmicpc.net/problem/9465
//Mist16, 2022-03-01
#include <iostream>
#include <memory.h>
using namespace std;

unsigned int stickerMap[100000][2];
unsigned int maxPoint[100000][3];

int testCases = 0;
int N = 0;

void run()
{
	maxPoint[0][0] = stickerMap[0][0];
	maxPoint[0][1] = stickerMap[0][1];
	maxPoint[0][2] = 0;

	for (int i = 1; i < N; i++)
	{
		//up
		if (maxPoint[i-1][1] > maxPoint[i-1][2])
		{
			maxPoint[i][0] = maxPoint[i - 1][1] + stickerMap[i][0];
		}
		else
			maxPoint[i][0] = maxPoint[i - 1][2] + stickerMap[i][0];
		//down
		if (maxPoint[i - 1][0] > maxPoint[i - 1][2])
		{
			maxPoint[i][1] = maxPoint[i - 1][0] + stickerMap[i][1];
		}
		else
			maxPoint[i][1] = maxPoint[i - 1][2] + stickerMap[i][1];
		//none
		if (maxPoint[i - 1][0] > maxPoint[i - 1][1])
			maxPoint[i][2] = maxPoint[i - 1][0];
		else
			maxPoint[i][2] = maxPoint[i - 1][1];
	}

}

int main()
{
	int numb, temp;
	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> testCases;

	for (int i = 0; i < testCases; i++)
	{
		unsigned int tempMaxValue = 0;
		//input
		cin >> N;
		for (int j = 0; j < N; j++)
		{
			cin >> stickerMap[j][0];
		}
		for (int j = 0; j < N; j++)
		{
			cin >> stickerMap[j][1];
		}
		//run
		run();

		for(int j = 0; j < 3; j++)
		{
			if (tempMaxValue < maxPoint[N-1][j])
				tempMaxValue = maxPoint[N-1][j];
		}
		cout << tempMaxValue << "\n";
	}
	return 0;
}
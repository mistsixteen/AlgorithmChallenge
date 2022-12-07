//Backjoon Problem No.2579
//https://www.acmicpc.net/problem/2579
//Mist16, 2022-04-19

#include <iostream>

using namespace std;

int score[301] = { 0, };
int maxScore[303][2] = { 0, };
int N;

int main()
{
	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;


	for (int i = 1; i <= N; i++)
	{
		cin >> score[i];
	}
	maxScore[1][0] = score[1];

	for (int i = 2; i <= N; i++)
	{
		maxScore[i][1] = maxScore[i - 1][0] + score[i];
		if (maxScore[i - 2][1] > maxScore[i - 2][0])
			maxScore[i][0] = maxScore[i - 2][1] + score[i];
		else
			maxScore[i][0] = maxScore[i - 2][0] + score[i];
	}

	if(maxScore[N][0] > maxScore[N][1])
		cout << maxScore[N][0];
	else
		cout << maxScore[N][1];
	
	return 0;
}
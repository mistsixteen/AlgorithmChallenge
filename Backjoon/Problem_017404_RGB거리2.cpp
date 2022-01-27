//Backjoon Problem No.17404
//https://www.acmicpc.net/problem/17404
//Mist16, 2022-01-27
#include <iostream>

using namespace std;

static const int maxSize = 1000;

int rgbLength[maxSize][3];

int N = 0;

int checkrgbLength(int startingPoint)
{
	int tempL[maxSize][3] = { 0, };
	int min = maxSize * maxSize + 1;
	for (int i = 0; i < 3; i++)
		tempL[0][i] = maxSize + 1;
	tempL[0][startingPoint] = rgbLength[0][startingPoint];

	for (int i = 1; i < N; i++)
	{
		//0 > from 1/2;
		if (tempL[i - 1][1] > tempL[i - 1][2])
			tempL[i][0] = rgbLength[i][0] + tempL[i - 1][2];
		else
			tempL[i][0] = rgbLength[i][0] + tempL[i - 1][1];
		//1
		if (tempL[i - 1][0] > tempL[i - 1][2])
			tempL[i][1] = rgbLength[i][1] + tempL[i - 1][2];
		else
			tempL[i][1] = rgbLength[i][1] + tempL[i - 1][0];
		//2
		if (tempL[i - 1][1] > tempL[i - 1][0])
			tempL[i][2] = rgbLength[i][2] + tempL[i - 1][0];
		else
			tempL[i][2] = rgbLength[i][2] + tempL[i - 1][1];
	}
	tempL[N - 1][startingPoint] = maxSize * maxSize + 1;
	for (int i = 0; i < 3; i++)
	{
		if (min > tempL[N - 1][i])
			min = tempL[N - 1][i];
	}
	return min;
}

int check()
{
	int min = maxSize * maxSize + 1;
	int temp;
	for(int i = 0; i < 3; i++)
	{
		temp = checkrgbLength(i);
		if (temp < min)
			min = temp;
	}
	return min;

}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> rgbLength[i][j];
		}
	}
	cout << check();
}
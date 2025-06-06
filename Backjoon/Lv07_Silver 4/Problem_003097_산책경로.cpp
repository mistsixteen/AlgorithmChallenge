//Backjoon Problem No.3097
//https://www.acmicpc.net/problem/3097
//Mist16, 2022-04-27

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	int N;
	int totalA = 0, totalB = 0;
	int tempA, tempB, temp;
	int coord[30][2];
	int minValue = 2000000001;
	double result;
	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> coord[i][0] >> coord[i][1];
		totalA += coord[i][0];
		totalB += coord[i][1];
	}

	for (int i = 0; i < N; i++)
	{
		tempA = totalA - coord[i][0];
		tempB = totalB - coord[i][1];
		temp = tempA * tempA + tempB * tempB;
		if (minValue > temp)
		{
			minValue = temp;
		}
	}
	result = sqrt(minValue);
	cout << totalA << " " << totalB << "\n";
	cout << fixed << setprecision(2) << result;

	return 0;
}
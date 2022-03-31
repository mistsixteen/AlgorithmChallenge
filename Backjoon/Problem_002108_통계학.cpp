//Backjoon Problem No.2108
//https://www.acmicpc.net/problem/2108
//Mist16, 2022-03-31

#include <iostream>

using namespace std;

static int Counting_Revise = 4000;

unsigned int counting[8001] = { 0, };

int main()
{
	int N;
	int middlePos, middleValue, currentIdx = 0;
	int averageValue;
	float fAverage;
	int MostValue, mostAmt = 0;
	int minValue = 8000, maxValue = 0;
	long total = 0;

	bool isSecond = false;

	int temp;

	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	middlePos = (N / 2) + 1;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		counting[temp + Counting_Revise]++;
		total += temp;
	}

	for (int i = 0; i < 8001; i++)
	{
		if (counting[i] != 0)
		{
			if (minValue > i)
				minValue = i;
			if (maxValue < i)
				maxValue = i;
			if (mostAmt < counting[i])
			{
				isSecond = false;
				mostAmt = counting[i];
				MostValue = i;
			}
			else if (mostAmt == counting[i] && isSecond == false)
			{
				isSecond = true;
				MostValue = i;
			}

			if (currentIdx < middlePos && currentIdx + counting[i] >= middlePos)
			{
				middleValue = i;
			}
			currentIdx += counting[i];
		}
	}
	averageValue = total / N;
	fAverage = total / (float)N;

	float gap = fAverage - averageValue;

	if (gap < 0 && gap <= -0.5)
		averageValue--;
	if (gap > 0 && gap >= 0.5)
		averageValue++;

	cout << averageValue << "\n" << middleValue - Counting_Revise << "\n" << MostValue - Counting_Revise << "\n" << ((maxValue - Counting_Revise) - (minValue - Counting_Revise));


	return 0;
}
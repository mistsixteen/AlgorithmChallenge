//Backjoon Problem No.1007
//https://www.acmicpc.net/problem/1007
//Mist16, 2022-01-24
#include <iostream>
#include <limits>
#include <math.h>

using namespace std;

class VectorMatching
{
private:
	int N;
	int pos[20][2];
	long long totalX;
	long long totalY;
	unsigned long long MinValue;
public:
	VectorMatching()
	{
		N = 0;
		MinValue = 0xffffffffffffffff;
		totalX = 0;
		totalY = 0;
	}

	void input()
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> pos[i][0] >> pos[i][1];
			totalX += pos[i][0];
			totalY += pos[i][1];
		}
	}

	void Run()
	{
		pick(N / 2, 0, 0, 0);
		long double temp = sqrtl(MinValue);
		cout.precision(16);
		cout << temp << endl;
	}

	void pick(int left, int currentIdx, long long vectorX, long long vectorY)
	{
		if (left == 0)
		{
			long long X = totalX - vectorX - vectorX;
			long long Y = totalY - vectorY - vectorY;
			unsigned long long temp = (X * X) + (Y * Y);
			if (temp < MinValue)
			{
				MinValue = temp;
			}
			return;
		}
		if (currentIdx >= N)
			return;
		pick(left, currentIdx + 1, vectorX, vectorY);
		pick(left - 1, currentIdx + 1, vectorX + pos[currentIdx][0], vectorY + pos[currentIdx][1]);
	}

};

int main()
{
	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testCases;

	//input n, pipemap;
	cin >> testCases;
	for (int i = 0; i < testCases; i++)
	{
		VectorMatching vMatch;
		vMatch.input();
		vMatch.Run();
	}
	return 0;
}
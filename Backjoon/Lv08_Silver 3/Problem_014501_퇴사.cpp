//Backjoon Problem No.14501
//https://www.acmicpc.net/problem/14501
//Mist16, 2022-03-11

#include <iostream>
using namespace std;

static const int MAX_DAYS = 15;

int t[MAX_DAYS] = { 0, }, p[MAX_DAYS] = { 0, };
int N = 0;

int maxP[MAX_DAYS + 1] = { 0, };

void run(int cDay, int cPrice)
{
	if (cDay > N)
		return;
	if (cPrice < maxP[cDay])
		return;
	maxP[cDay] = cPrice;

	if (cDay == N)
		return;

	run(cDay + 1, cPrice);
	run(cDay + t[cDay], cPrice + p[cDay]);

}

int main()
{

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> t[i] >> p[i];
	}

	run(0, 0);

	cout << maxP[N];
	return 0;
}
//Backjoon Problem No.1500
//https://www.acmicpc.net/problem/1500
//Mist16, 2022-03-07

#include <iostream>

using namespace std;

unsigned long long maxValueArray[101][20] = { 0, };

unsigned long long findMaxValue(int left, int leftidx)
{
	unsigned long long maxValue = 0;
	if (maxValueArray[left][leftidx] != 0)
		return maxValueArray[left][leftidx];
	if (left == leftidx)
	{
		maxValueArray[left][leftidx] = 1;
		return 1;
	}
	if (leftidx == 1)
	{
		maxValueArray[left][leftidx] = left;
		return left;
	}
	for (int i = 1; i < left - leftidx + 1; i++)
	{
		unsigned long long temp = i * findMaxValue(left - i, leftidx - 1);
		if (temp > maxValue)
			maxValue = temp;
	}
	maxValueArray[left][leftidx] = maxValue;
	return maxValue;
}


int main()
{
	int s, k;
	cin >> s >> k;

	cout << findMaxValue(s, k);

	return 0;
}
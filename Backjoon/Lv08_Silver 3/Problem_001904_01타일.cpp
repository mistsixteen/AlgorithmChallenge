//Backjoon Problem No.1904
//https://www.acmicpc.net/problem/1904
//Mist16, 2022-04-16

#include <iostream>

using namespace std;

int memoArray[1000000] = { 0, };

int run(int i)
{
	if (i < 0)
		return 0;
	if (memoArray[i] != 0)
		return memoArray[i];
	else
	{
		int temp = run(i - 1) + run(i - 2);
		temp = temp % 15746;
		memoArray[i] = temp;
		return memoArray[i];
	}

}

int main()
{
	int N;
	memoArray[0] = 1;
	memoArray[1] = 1;

	cin >> N;

	cout << run(N);

	return 0;
}
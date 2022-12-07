//Backjoon Problem No.11399
//https://www.acmicpc.net/problem/11399
//Mist16, 2022-03-24

#include <iostream>
#include <set>

using namespace std;

int main()
{
	multiset<unsigned int> timeSet;
	int N;
	unsigned int totaltime = 0;
	unsigned int currenttime = 0;

	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		unsigned int temp = 0;
		cin >> temp;
		timeSet.insert(temp);
	}

	for (auto i : timeSet)
	{
		currenttime += i;
		totaltime += currenttime;
	}

	cout << totaltime;

}
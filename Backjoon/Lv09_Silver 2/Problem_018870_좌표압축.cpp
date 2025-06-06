//Backjoon Problem No.18870
//https://www.acmicpc.net/problem/18870
//Mist16, 2022-04-20

#include <iostream>
#include <map>

using namespace std;

multimap<int, int> inputMap;



int main()
{
	int N, temp, idx;
	int zippedArr[1000002] = { 0, };
	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//input
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		inputMap.insert(pair<int, int>(temp, i));
	}
	//zip coord
	idx = 0;
	temp = inputMap.begin()->first;
	for (auto a : inputMap)
	{
		if (a.first != temp)
		{
			temp = a.first;
			idx++;
		}
		zippedArr[a.second] = idx;
	}
	//output
	for (int i = 0; i < N; i++)
	{
		cout << zippedArr[i] << " ";
	}

	return 0;
}
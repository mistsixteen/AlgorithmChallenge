//Backjoon Problem No.10816
//https://www.acmicpc.net/problem/10816
//Mist16, 2022-04-01

#include <iostream>
#include <map>

using namespace std;

int main()
{
	int N, temp;
	map<int, int> cards;

	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		cards[temp]++;
	}

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		cout << cards[temp] << " ";
	}

	return 0;
}
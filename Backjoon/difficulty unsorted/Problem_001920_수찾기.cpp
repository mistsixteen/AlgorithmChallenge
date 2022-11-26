//Backjoon Problem No.1920
//https://www.acmicpc.net/problem/1920
//Mist16, 2022-02-10
#include <iostream>
#include <set>

using namespace std;

set<long long> iSet;
int N, M;

int main()
{
	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		long long temp;
		cin >> temp;
		if (iSet.find(temp) == iSet.end())
		{
			iSet.insert(temp);
		}

	}
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		long long temp;
		cin >> temp;
		if (iSet.find(temp) == iSet.end())
		{
			cout << "0\n";
		}
		else
			cout << "1\n";
			
	}

	return 0;
}
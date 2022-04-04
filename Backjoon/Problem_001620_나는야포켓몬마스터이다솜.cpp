//Backjoon Problem No.1620
//https://www.acmicpc.net/problem/1620
//Mist16, 2022-04-04
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main()
{
	int N, M;
	string temp;

	vector<string> findByNumber;
	map<string, int> findByName;
	
	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		cin >> temp;
		findByNumber.push_back(temp);
		findByName.insert(pair<string, int>(temp, i));
	}
	for (int i = 1; i <= M; i++)
	{
		cin >> temp;
		if (temp[0] >= '0' && temp[0] <= '9')
		{
			int tempi = atoi(temp.c_str());
			cout << findByNumber[tempi - 1] << "\n";
		}
		else
		{
			auto iter = findByName.find(temp);
			if (iter != findByName.end())
			{
				cout << iter->second << "\n";
			}
		}
	}
	return 0;
}
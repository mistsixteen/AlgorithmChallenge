//Backjoon Problem No.10814
//https://www.acmicpc.net/problem/10814
//Mist16, 2022-03-30

#include <iostream>
#include <list>
#include <string>

using namespace std;


int main()
{
	int N, age;
	string name;
	list<string> ageList[201];

	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> age >> name;
		ageList[age].push_back(name);
	}

	for (int i = 0; i < 201; i++)
	{
		for (string s : ageList[i])
		{
			cout << i << " " << s << "\n";
		}
	}

	return 0;
}
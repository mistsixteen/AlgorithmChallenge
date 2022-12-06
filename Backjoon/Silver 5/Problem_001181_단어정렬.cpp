//Backjoon Problem No.1181
//https://www.acmicpc.net/problem/1181
//Mist16, 2022-04-01

#include <iostream>
#include <string>
#include <set>
using namespace std;

bool Comp(string a, string b)
{
	if (a.size() != b.size())
	{
		return a.size() < b.size();
	}
	else
		return a < b;
}


int main()
{
	int N;
	string temp;
	set<string, decltype(Comp)*> stringSet(Comp);
	
	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		stringSet.insert(temp);
	}

	for (string s : stringSet)
	{
		cout << s << "\n";
	}

	return 0;
}
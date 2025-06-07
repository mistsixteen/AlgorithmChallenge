//Codeforces Round #767 Div.2
//Problem A
//https://codeforces.com/contest/1629/problem/A
//Mist16, 2022-01-23
#include <iostream>
#include <map>

using namespace std;

class DownMoreRam
{
private:
	int N;
	int currentRam;
	multimap<int, int> ePrograms;
public:
	DownMoreRam()
	{
		N = 0;
		currentRam = 0;
	}
	void input()
	{
		int tempRam[100];
		int tempPrice[100];
		cin >> N >> currentRam;
		for(int i = 0; i < N; i++)
		{
			cin >> tempPrice[i];
		}
		for(int i = 0; i < N; i++)
		{
			cin >> tempRam[i];
		}
		for(int i = 0; i < N; i++)
		{
			ePrograms.insert(pair<int, int>(tempPrice[i], tempRam[i]));
		}
	}
	int Run()
	{
		for (auto iter : ePrograms)
		{
			if (iter.first <= currentRam)
				currentRam += iter.second;
			else
				break;
		}
		return currentRam;
	}
};

int t = 0;

int main()
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		DownMoreRam dRam;
		dRam.input();
		cout << dRam.Run() << endl;
	}
	return 0;
}
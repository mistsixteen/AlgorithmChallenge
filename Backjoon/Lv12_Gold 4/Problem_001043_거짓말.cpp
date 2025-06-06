//Backjoon Problem No.1043
//https://www.acmicpc.net/problem/1043
//Mist16, 2022-03-01
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int M = 0, N = 0;

int isAffected[51] = { 0, };

vector<set<int>> vParty;
vector<int> vAffected;

int main()
{
	int numb, temp;
	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> numb;
	//진실을 아는 사람
	for (int i = 0; i < numb; i++)
	{
		cin >> temp;
		vAffected.push_back(temp);
		isAffected[temp] = 1;
	}
	//파티 입력
	for (int i = 0; i < M; i++)
	{
		set<int> cParty;

		cin >> numb;
		for (int j = 0; j < numb; j++)
		{
			cin >> temp;
			cParty.insert(temp);
		}
		vParty.push_back(cParty);
	}

	while (!vAffected.empty() && !vParty.empty())
	{
		int aPerson = vAffected.back();

		vAffected.pop_back();

		for (auto iter = vParty.begin(); iter != vParty.end(); iter)
		{
			if (iter->find(aPerson) != iter->end())
			{
				for (int i : *iter)
				{
					if (isAffected[i] == 0)
					{
						isAffected[i] = 1;
						vAffected.push_back(i);
					}
				}
				iter = vParty.erase(iter);
			}
			else
				iter++;
		}

	}
	cout << vParty.size();
	return 0;
}
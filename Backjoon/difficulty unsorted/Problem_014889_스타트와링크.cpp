//Backjoon Problem No.14889
//https://www.acmicpc.net/problem/14889
//Mist16, 2022-03-21
#include <iostream>
#include <list>

static const int INF = 99999999;

using namespace std;

int linkStatus[20][20] = { 0, };
int N;

int leastPowerGap = INF;

void run(list<int> teamA, list<int> teamB, int teamAPower, int teamBPower, int idx)
{
	if (idx == N)
	{
		int gap = teamAPower - teamBPower;
		if (gap < 0)
			gap = gap * -1;
		if (gap < leastPowerGap)
		{
			leastPowerGap = gap;
		}
		return;
	}

	if (teamA.size() < N / 2)
	{
		int nextTeamAPower = teamAPower;
		for (int i : teamA)
		{
			nextTeamAPower += linkStatus[idx][i];
		}
		teamA.push_back(idx);
		run(teamA, teamB, nextTeamAPower, teamBPower, idx+1);
		teamA.pop_back();
	}

	if (teamB.size() < N / 2)
	{
		int nextTeamBPower = teamBPower;
		for (int i : teamB)
		{
			nextTeamBPower += linkStatus[idx][i];
		}
		teamB.push_back(idx);
		run(teamA, teamB, teamAPower, nextTeamBPower, idx + 1);
	}

}

int main()
{
	int temp;
	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	list<int> blank;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> temp;
			linkStatus[i][j] += temp;
			linkStatus[j][i] += temp;

		}
	}

	run(blank, blank, 0, 0, 0);

	cout << leastPowerGap << endl;

	return 0;
}
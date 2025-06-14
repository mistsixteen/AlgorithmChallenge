#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

set<int> visited[3001];
int monster[3001][2];
int maxKills = 0;

int N;

void run(int idx, int h, int m)
{
	//visited
	int hash = h * 10000 + m;
	auto set = visited[idx];

	if (set.find(hash) != set.end())
	{
		return;
	}

	set.insert(hash);

	if (maxKills < idx)
	{
		maxKills = idx;
	}

	if (maxKills == N)
	{
		return;
	}

	if (monster[idx][0] <= h)
	{
		run(idx + 1, h - monster[idx][0], m);
	}

	if (monster[idx][1] <= m)
	{
		run(idx + 1, h, m - monster[idx][1]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int H, M;

	cin >> N >> H >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> monster[i][0] >> monster[i][1];
	}

	run(0, H, M);

	cout << maxKills;

	return 0;
}
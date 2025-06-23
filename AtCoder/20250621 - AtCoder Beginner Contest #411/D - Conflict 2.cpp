#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

char strings[1250000];

int iidx[200001];
int parent[200001];
int pc[200001];

int server;

void pr(int idx)
{
	if (idx == 0)
	{
		return;
	}
	pr(parent[idx]);

	cout << strings + iidx[idx];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, q;
	int t, p;

	int idx = 0;
	int sidx = 1;

	cin >> n >> q;

	for (int i = 0; i < q; i++)
	{
		cin >> t >> p;

		if (t == 1)
		{
			pc[p] = server;
		}
		else if (t == 2)
		{
			string str;
			cin >> str;
			memcpy(strings + idx, str.c_str(), str.size());
			iidx[sidx] = idx;
			parent[sidx] = pc[p];
			pc[p] = sidx;
			idx += str.size() + 1;
			sidx++;
		}
		else if (t == 3)
		{
			server = pc[p];
		}
	}	

	pr(server);

	return 0;
}
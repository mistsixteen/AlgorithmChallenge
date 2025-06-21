//Backjoon Problem No.1717
//https://www.acmicpc.net/problem/1717
//Mist16, 2025-06-21

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int parent[1000001];
int r[1000001];

int Find_parent(int i)
{
	if (i == parent[i])
	{
		return i;
	}

	int pp = Find_parent(parent[i]);

	if (pp != parent[i])
	{
		parent[i] = pp;
	}
	return pp;
}

void UnionSet(int a, int b)
{
	int pa = Find_parent(a);
	int pb = Find_parent(b);

	if (r[pa] >= r[pb])
	{
		parent[pb] = pa;
		r[pa]++;
	}
	else
	{
		parent[pa] = pb;
		r[pb]++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;

	cin >> n >> m;

	int a, b, c;

	for (int i = 0; i <= n; i++)
	{
		parent[i] = i;
		r[i] = 0;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;

		if (a == 0)
		{
			UnionSet(b, c);
		}
		else
		{
			if(Find_parent(b) == Find_parent(c))
			{
				cout << "YES\n";
			}
			else
			{
				cout << "NO\n";
			}
		}
	}

	return 0;
}
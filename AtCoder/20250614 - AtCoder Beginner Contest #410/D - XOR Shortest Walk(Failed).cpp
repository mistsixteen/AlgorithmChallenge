#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int* minLength;
vector<pair<int, int>>* path;

void Visit(int pos, int value)
{
	if (minLength[pos] != -1 && minLength[pos] < value)
	{
		return;
	}

	minLength[pos] = value;

	for (auto element : path[pos])
	{
		Visit(element.first, value ^ element.second);
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N >> M;

	minLength = new int[N+1];
	path = new vector<pair<int, int>>[N+1];

	minLength[1] = 0;
	for (int i = 2; i <= N; i++)
	{
		minLength[i] = -1;
	}

	for (int i = 0; i < M; i++)
	{
		int start, end, length;
		cin >> start >> end >> length;

		path[start].push_back(pair<int, int>(end, length));
	}

	for (auto element : path[1])
	{
		Visit(element.first, element.second);
	}

	cout << minLength[N];


	return 0;
}
//Backjoon Problem No.16139
//https://www.acmicpc.net/problem/16139
//Mist16, 2022-04-18

#include <iostream>

using namespace std;

int totalArray[200001][26] = { 0, };
int main()
{
	string s;
	int N;
	char c;
	int a, r;
	int idx = 0;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;

	for (char c : s)
	{
		for (int i = 0; i < 26; i++)
			totalArray[idx + 1][i] = totalArray[idx][i];
		totalArray[idx + 1][(int)c - 'a']++;
		idx++;
	}

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> c >> a >> r;
		cout << totalArray[r+1][(int)c - 'a'] - totalArray[a][(int)c - 'a'] << "\n";
	}

	return 0;
}
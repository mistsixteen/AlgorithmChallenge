//Backjoon Problem No.1932
//https://www.acmicpc.net/problem/1932
//Mist16, 2022-01-27
#include <iostream>

using namespace std;

int iSize[500][500];
int Level = 0;

void check(int lvl)
{
	if (lvl <= 0)
		return;
	for (int i = 0; i < lvl; i++)
	{
		if (iSize[lvl][i] > iSize[lvl][i + 1])
			iSize[lvl - 1][i] += iSize[lvl][i];
		else
			iSize[lvl - 1][i] += iSize[lvl][i + 1];
	}
}


int main()
{
	cin >> Level;
	for (int i = 0; i < Level; i++)
	{
		for (int j = 0; j < i+1; j++)
		{
			cin >> iSize[i][j];
		}
	}
	for (int i = Level - 1; i > 0; i--)
	{
		check(i);
	}
	cout << iSize[0][0];
}
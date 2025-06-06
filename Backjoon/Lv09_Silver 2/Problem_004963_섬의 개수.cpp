//Backjoon Problem No.4963
//https://www.acmicpc.net/problem/4963
//Mist16, 2022-12-28

#include <iostream>

using namespace std;

int w, h;
char arr[50][50];

void checkIsland(int y, int x)
{
	if (y < 0 || y >= h || x < 0 || x >= w)
		return;
	if (arr[y][x] == '0')
		return;
	arr[y][x] = '0';

	checkIsland(y - 1, x - 1);
	checkIsland(y - 1, x);
	checkIsland(y - 1, x + 1);
	checkIsland(y, x - 1);
	checkIsland(y, x + 1);
	checkIsland(y + 1, x - 1);
	checkIsland(y + 1, x);
	checkIsland(y + 1, x + 1);
}
int main()
{
	while (true)
	{
		int land = 0;
		cin >> w >> h;
		if (w == 0 && h == 0)
			return 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (arr[i][j] == '1')
				{
					land++;
					checkIsland(i, j);
				}
			}
		}
		cout << land << endl;
	}
	return 0;
}

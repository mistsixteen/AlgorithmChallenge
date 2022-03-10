//Backjoon Problem No.10250
//https://www.acmicpc.net/problem/10250
//Mist16, 2022-03-10

#include <iostream>
using namespace std;


int main()
{
	int testCase;
	int H, W, N;

	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		int height = 0, width = 1;
		cin >> H >> W >> N;

		while (N > H)
		{
			width++;
			N = N - H;
		}
		height = N;
		
		cout << height;
		cout.width(2);
		cout.fill('0');
			cout << width << "\n";
	}

	return 0;
}
//Backjoon Problem No.1244
//https://www.acmicpc.net/problem/1244
//Mist16, 2022-04-24

#include <iostream>

using namespace std;


int main()
{
	int n, cases;
	int a, b;
	int flags[101] = { 0, };

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> flags[i];
	}
	cin >> cases;
	for (int i = 1; i <= cases; i++)
	{
		cin >> a >> b;
		if (a == 1) //남학생
		{
			for (int i = b; i <= n; i += b)
			{
				flags[i] = !flags[i];
			}
		}
		else
		{
			int posA = b - 1;
			int posB = b + 1;
			flags[b] = !flags[b];
			while (posA > 0 && posB <= n)
			{
				if (flags[posA] == flags[posB])
				{
					flags[posA] = !flags[posA];
					flags[posB] = !flags[posB];
				}
				else
					break;
				posA--;
				posB++;
			}
		}
	}
	//output;
	for (int i = 1; i <= n; i++)
	{
		cout << flags[i] << " ";
		if(i % 20 == 0)
			cout << endl;
	}
	return 0;
}
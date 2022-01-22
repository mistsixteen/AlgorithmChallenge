//Codeforces Round #767 Div.2
//Problem C
//https://codeforces.com/contest/1629/problem/C
//Mist16, 2022-01-23
#include <iostream>
#include <list>

using namespace std;

class MexArray
{
private:
	int* origArray;
	int* maxArray;
	int* mexArray;
	int N;
	int size;
public:
	void initialize()
	{
		origArray = new int[200002];
		maxArray = new int[200002];
		mexArray = new int[200002];
		size = 0;
		N = 0;
	}
	void del()
	{
		delete[] origArray;
		delete[] maxArray;
		delete[] mexArray;

	}
	void input()
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> origArray[i];
		}
	}
	void Run()
	{
		int start = 0;
		int end = N;

		for (int i = 0; i < 200001; i++)
			mexArray[i] = 0;

		while (start != end)
		{
			int currentMex = -1;
			int nextPosition = start + 1;
			int maxValue = 0;
			for (int i = start; i < N; i++)
			{

				if (mexArray[origArray[i]] <= 0)
				{
					mexArray[origArray[i]] = i+1;
				}
				if (maxValue < origArray[i])
					maxValue = origArray[i];
			}


			for (int i = 0; i < maxValue+2; i++)
			{
				if (mexArray[i] <= 0)
				{
					break;
				}
				else
				{
					currentMex = i;
					if(mexArray[i] > nextPosition)
						nextPosition = mexArray[i];
				}
					
			}

			maxArray[size] = currentMex + 1;
			size++;
			start = nextPosition;

			for (int i = 0; i < maxValue+2; i++)
				mexArray[i] = 0;


		}
	}
	void Output()
	{
		cout << size << endl;
		for (int i = 0; i < size; i++)
		{
			cout << maxArray[i] << " ";
		}
		cout << endl;
	}
};

int t = 0;

int main()
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		MexArray ma;
		ma.initialize();
		ma.input();
		ma.Run();
		ma.Output();
		ma.del();
	}
	return 0;
}
//Backjoon Problem No.1086
//https://www.acmicpc.net/problem/1086
//Mist16, 2022-01-28
//풀이실패, 추후재도전

#include <iostream>
#include <time.h>

using namespace std;

struct Node
{
	int currentMod;
	int currentDigit;

	Node()
	{
		currentMod = 0;
		currentDigit = 0;
	}
};

int N, K;

unsigned char temp[15][51];
Node node[15];

int modCheck[1000];

void getDigitNode(int i)
{
	int idx = 0;
	Node n;
	while (temp[i][idx] != 0x00 && idx <= 50)
	{
		n.currentMod = n.currentMod * 10 + (int)(temp[i][idx] - '0');
		if (n.currentMod > K)
		{
			n.currentMod = n.currentMod % K;
		}
		n.currentDigit++;
		idx++;
	}
	node[i] = n;
}

int getmod(int i)
{
	if (modCheck[i] == -1)
	{
		int a, b;
		a = i / 2;
		b = i - a;
		modCheck[i] = getmod(a) + getmod(b);
		return modCheck[i];
	}
	else
		return modCheck[i];
}


unsigned int getNextMod(int i, unsigned int totalMod, unsigned int totalDigit)
{
	unsigned int temp = node[i].currentMod;

	temp = temp * getmod(totalDigit);

	while (temp > K)
	{
		temp = temp % K;
	}

	return totalMod + temp;
}

unsigned long long run(int turn, unsigned int bitmask, unsigned int totalDigit, unsigned int totalMod)
{
	unsigned long long total = 0;
	int tempDigit, tempMod;
	if (turn == N)
	{
		if (totalMod == 0)
			return 1;
		if (totalMod % K == 0)
			return 1;
		else
			return 0;
	}
		

	for (int i = 0; i < N; i++)
	{
		if (((bitmask >> i) & 1) == 0)
		{
			total += run(turn + 1, (bitmask | (1 << i)), totalDigit + node[i].currentDigit, getNextMod(i, totalMod, totalDigit));
		}
	}
	return total;
}

void init()
{
	for (int i = 0; i < 51 * 15; i++)
	{
		modCheck[i] = -1;
	}
	modCheck[1] = 10 & K;
	modCheck[0] = 0;
}


int main()
{
	unsigned long long avali = 0;
	unsigned long long total = 1;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> temp[i];
	}
	cin >> K;
	init();


	clock_t start, end;

	start = clock();

	for (int i = 0; i < N; i++)
	{
		getDigitNode(i);
	}
	avali = run(0, 0, 0, 0);
	if (avali == 0)
	{
		cout << "0/1";
	}
	else
	{
		for (int i = 2; i <= N; i++)
		{
			if (avali % i == 0)
				avali = avali / i;
			else
				total = total * i;
		}
		for (int i = 2; i <= N; i++)
		{
			while (avali >= i && total >= i && avali & i == 0 && total & i == 0)
			{
				avali = avali / i;
				total = total / i;
			}
		}
		cout << avali << "/" << total;
	}

	end = clock();

	cout << endl << (double)(end - start);
	
	return 0;
}
//Backjoon Problem No.14939
//https://www.acmicpc.net/problem/14939
//Mist16, 2022-02-06
#include <iostream>

using namespace std;

int minimunLight = -1;

struct lightBoard
{
	unsigned int n[10] = { 0, };
};

lightBoard lboard;

void runLines(lightBoard lBoard, int LightsOn)
{
	for (int line = 1; line < 10; line++)
	{
		for (int i = 0; i < 10; i++)
		{
			if ((lBoard.n[line-1] & (1 << i)) != 0)
			{
				if (i > 0)
					lBoard.n[line] = lBoard.n[line] ^ (1 << i - 1);
				lBoard.n[line] = lBoard.n[line] ^ (1 << i);
				if(line < 9)
				lBoard.n[line+1] = lBoard.n[line+1] ^ (1 << i);
				if (i < 9)
					lBoard.n[line] = lBoard.n[line] ^ (1 << i + 1);
				LightsOn++;
			}
		}
		if (minimunLight != -1 && minimunLight < LightsOn)
		{
			return;
		}
	}
	
	if (lBoard.n[9] == 0)
	{
		if (minimunLight == -1)
		{
			minimunLight = LightsOn;
		}
		else if (minimunLight != -1 && minimunLight > LightsOn)
		{
			minimunLight = LightsOn;
		}
	}

}


void runFirstLine(int idx, unsigned int currentBoard)
{
	if (idx == 10)
	{
		lightBoard tboard = lboard;
		int LightsOn = 0;
		for (int i = 0; i < 10; i++)
		{
			if ((currentBoard & (1 << i)) != 0)
			{
				LightsOn++;
				if (i > 0)
					tboard.n[0] = tboard.n[0] ^ (1 << i - 1);
				tboard.n[0] = tboard.n[0] ^ (1 << i);
				tboard.n[1] = tboard.n[1] ^ (1 << i);
				if (i < 9)
					tboard.n[0] = tboard.n[0] ^ (1 << i + 1);
			}
		}
		runLines(tboard, LightsOn);
		return;
	}
	runFirstLine(idx + 1, currentBoard);

	unsigned int temp = currentBoard;
	if(idx > 0)
		temp = temp ^ (1 << idx - 1);
	temp = temp ^ (1 << idx);
	if(idx < 9)
		temp = temp ^ (1 << idx + 1);
	runFirstLine(idx + 1, temp);

}

int main()
{
	char temp;
	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cin >> temp;
			if (temp == 'O')
			{
				lboard.n[i] = lboard.n[i] | (1 << j);
			}
		}
	}

	runFirstLine(0, 0);

	cout << minimunLight;

	return 0;
}
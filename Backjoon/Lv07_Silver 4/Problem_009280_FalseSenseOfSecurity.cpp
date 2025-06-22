//Backjoon Problem No.9280
//https://www.acmicpc.net/problem/9280
//Mist16, 2025-06-22

#include <iostream>
#include <string>

using namespace std;

char morse[5000];
int dice[1000];

char dict[30][4];
int dictLeng[30] = {2, 4, 4, 3, 1, 4, 3, 4, 2, 4, 3, 4, 2, 2, 3, 4, 4, 3, 3, 1, 3, 4, 3, 4, 4, 4, 4, 4, 4, 4};

int cIdx = 0;
int iIdx = 0;

void Initialize()
{
	for (int i = 0; i < 45; i++)
	{
		dict[i][0] = 0;
		dict[i][1] = 0;
		dict[i][2] = 0;
		dict[i][3] = 0;
	}

	//A-Z
	dict[0][1] = 1;
	dict[1][0] = 1;
	dict[2][0] = 1;
	dict[2][2] = 1;
	dict[3][0] = 1;
	dict[5][2] = 1;
	dict[6][0] = 1;
	dict[6][1] = 1;

	dict[9][1] = 1;
	dict[9][2] = 1;
	dict[9][3] = 1;
	dict[10][0] = 1;
	dict[10][2] = 1;
	dict[11][1] = 1;
	dict[12][0] = 1;
	dict[12][1] = 1;
	dict[13][0] = 1;

	dict[14][0] = 1;
	dict[14][1] = 1;
	dict[14][2] = 1;
	dict[15][1] = 1;
	dict[15][2] = 1;
	dict[16][0] = 1;
	dict[16][1] = 1;
	dict[16][3] = 1;
	dict[17][1] = 1;
	dict[19][0] = 1;
	dict[20][2] = 1;

	dict[21][3] = 1;
	dict[22][1] = 1;
	dict[22][2] = 1;

	dict[23][0] = 1;
	dict[23][3] = 1;
	dict[24][0] = 1;
	dict[24][2] = 1;
	dict[24][3] = 1;
	dict[25][0] = 1;
	dict[25][1] = 1;

	dict[26][2] = 1;
	dict[26][3] = 1;
	dict[27][1] = 1;
	dict[27][3] = 1;
	dict[28][0] = 1;
	dict[28][1] = 1;
	dict[28][2] = 1;
	dict[29][0] = 1;
	dict[29][1] = 1;
	dict[29][2] = 1;
	dict[29][3] = 1;
}

int CharToIdx(char c)
{
	switch (c)
	{
	case '_':
		return 26;
		break;
	case ',':
		return 27;
		break;
	case '.':
		return 28;
		break;
	case '?':
		return 29;
		break;
	default:
		return (int)c - 65;
	}
}

char IdxToChar(int i)
{
	switch (i)
	{
	case 26:
		return '_';
		break;
	case 27:
		return ',';
		break;
	case 28:
		return '.';
		break;
	case 29:
		return '?';
		break;
	default:
		return (char)(i + 65);
	}
}

void Input(string s)
{
	cIdx = 0;
	iIdx = 0;

	for(char c : s)
	{
		int i = CharToIdx(c);
		if (i < 0 || i > 29)
		{
			break;
		}
		
		dice[iIdx] = dictLeng[i];
		
		for (int j = 0; j < dice[iIdx]; j++)
		{
			morse[cIdx + j] = dict[i][j];
		}
		cIdx = cIdx + dice[iIdx];
		iIdx++;
	}
}

void Output()
{
	int outputIdx = 0;

	for (int i = iIdx - 1; i >= 0; i--)
	{
		int size = dice[i];
		int result = -1;

		for (int target = 0; target < 30; target++)
		{
			if (dictLeng[target] != size)
			{
				continue;
			}

			bool isCurrect = true;
			for (int j = 0; j < size; j++)
			{
				if (morse[outputIdx + j] != dict[target][j])
				{
					isCurrect = false;
				}
			}
			if (isCurrect)
			{
				result = target;
				break;
			}
		}
		cout << IdxToChar(result);
		outputIdx += size;
	}

	cout << endl;
}



int main()
{
	string line;
	Initialize();

	while (getline(cin, line)) {
		if (line.size() == 0)
			break;
		Input(line);
		Output();
	}

	return 0;
}
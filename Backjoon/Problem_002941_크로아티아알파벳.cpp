//Backjoon Problem No.2941
//https://www.acmicpc.net/problem/2941
//Mist16, 2022-03-15

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;

	cin >> input;
	int crtNum = 0;

	for (int i = 0; i < input.size(); i++)
	{
		switch (input[i])
		{
		case 'c':
			if (i + 1 < input.size() && (input[i + 1] == '=' || input[i + 1] == '-'))
			{
				crtNum++;
				i++;
			}
			else
				crtNum++;
			break;
		case 'd':
			if (i + 1 < input.size() && input[i + 1] == '-')
			{
				crtNum++;
				i++;
			}
			else if (i + 2 < input.size() && input[i + 1] == 'z' && input[i + 2] == '=')
			{
				crtNum++;
				i = i + 2;
			}
			else
				crtNum++;
			break;
		case 'l':
			if (i + 1 < input.size() && input[i + 1] == 'j')
			{
				crtNum++;
				i++;
			}
			else
				crtNum++;
			break;
		case 'n':
			if (i + 1 < input.size() && input[i + 1] == 'j')
			{
				crtNum++;
				i++;
			}
			else
				crtNum++;
			break;
		case 's':
			if (i + 1 < input.size() && input[i + 1] == '=')
			{
				crtNum++;
				i++;
			}
			else
				crtNum++;
			break;
		case 'z':
			if (i + 1 < input.size() && input[i + 1] == '=')
			{
				crtNum++;
				i++;
			}
			else
				crtNum++;
			break;
		default:
			crtNum++;
		}

	}

	cout << crtNum;



	return 0;
}
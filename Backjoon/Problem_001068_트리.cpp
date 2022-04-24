//Backjoon Problem No.1068
//https://www.acmicpc.net/problem/1068
//Mist16, 2022-04-24

#include <iostream>
#include <vector>
using namespace std;

int n;
int leafNode = 0;
int headNode = 0;
int delNode = -2;
vector<int> treeV[50];

int getNode(int target)
{
	if (treeV[target].empty())
		return 1;
	else
	{
		int count = 0;
		for (int a : treeV[target])
		{
			count += getNode(a);
		}
		return count;
	}
}

int main()
{
	int temp;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		if (temp == -1)
			headNode = i;
		else
		{
			treeV[temp].push_back(i);
		}
	}
	cin >> delNode;
	for (int i = 0; i < n; i++)
	{
		for (auto iter = treeV[i].begin(); iter != treeV[i].end(); iter++)
		{
			if (*iter == delNode)
			{
				treeV[i].erase(iter);
				break;
			}
		}
	}

	if (delNode == headNode)
		cout << 0;
	else
		cout << getNode(headNode);

	return 0;
}
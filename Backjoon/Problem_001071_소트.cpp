//Backjoon Problem No.1071
//https://www.acmicpc.net/problem/1071
//Mist16, 2022-01-24
#include <iostream>
#include <list>

using namespace std;

int Arr[1001] = { 0, };
list<int> li;

//cout << li.front() << " " << li.back();
void printall(int target)
{
	for (int i = 0; i < Arr[target]; i++)
	{
		cout << target << " ";
	}
}

void greedy(int last)
{
	int temp;
	if (li.empty())
	{
		return;
	}
	if (li.size() == 1)
	{
		printall(li.front());
		return;
	}
	if (li.front() != last + 1)
	{
		if ((li.front()) + 1 == li.back())
		{
			//last -> front
			printall(li.back());
			printall(li.front());
			return;
		}
		else
		{
			//front all
			temp = li.front();
			printall(li.front());
			li.pop_front();
			greedy(temp);
		}
	}
	else
	{
		list<int>::iterator iter;
		iter = li.begin();
		iter++;
		temp = *iter;
		//2번째꺼
		cout << temp << " ";
		Arr[temp]--;
		if(Arr[temp] == 0)
		{
			li.remove(temp);
		}
		greedy(temp);	
	}
	return;
}

void run()
{
	int low = 0;
	int high = 0;
	for (int i = 0; i < 1001; i++)
	{
		if (Arr[i] != 0)
		{
			if (low == 0)
				low = i;
			high = i;
			li.push_back(i);
		}
	}
	greedy(-2);
}

int main()
{
	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, temp;

	//input n, pipemap;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		Arr[temp]++;
	}
	run();

	return 0;
}
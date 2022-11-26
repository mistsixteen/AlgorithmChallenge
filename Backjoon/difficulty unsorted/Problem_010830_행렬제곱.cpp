//Backjoon Problem No.10830
//https://www.acmicpc.net/problem/10830
//Mist16, 2022-02-05
#include <iostream>
#include <map>

using namespace std;

unsigned int N = 0;
unsigned long long B = 0;

struct matrix
{
	unsigned int mat[5][5];

	matrix()
	{
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				mat[i][j] = 0;
	}
};

map<unsigned long long, matrix> dices;

matrix matrixMulti(const matrix& a, const matrix& b)
{
	matrix temp;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			unsigned int tempv = 0;
			for (int k = 0; k < N; k++)
			{
				tempv = tempv + (a.mat[i][k] * b.mat[k][j]);
			}
			tempv = tempv % 1000;
			temp.mat[i][j] = tempv;

		}
	}
	return temp;
}

matrix getNSquare(unsigned long long n)
{
	auto iter = dices.find(n);

	if (iter == dices.end())
	{
		unsigned long long a, b;
		a = n / 2;
		b = n - a;
		matrix tempmat;
		tempmat = matrixMulti(getNSquare(a), getNSquare(b));
		dices.insert(pair <unsigned long long, matrix>(n, tempmat));
		return tempmat;

	}
	return iter->second;
}

void run()
{
	matrix result = getNSquare(B);
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << result.mat[i][j] % 1000 << " ";
		}
		cout << endl;
	}
	return;
}

int main()
{
	//입출력 속도 증가
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	matrix temp;
	
	cin >> N >> B;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> temp.mat[i][j];
		}
	}

	dices.clear();
	dices.insert(pair <unsigned long long, matrix>(1, temp));

	run();

	return 0;
}
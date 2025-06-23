#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	string str;

	cin >> str >> n;

	if (n <= str.length())
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
	
	return 0;
}
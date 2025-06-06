//Backjoon Problem No.1202
//Mist16, 2022-01-21

#include <iostream>
#include <list>
#include <set>
using namespace std;

struct Jewel
{
	int weight;
	int price;
	Jewel(int wei, int pri) : weight(wei), price(pri) {}

	//���Ľ� price �������� ��Ʈ�ǵ��� ����
	bool operator<(const Jewel s) const
	{
		return this->price > s.price;
	}
};

list<Jewel> jewels;
multiset<int> Bags;

int N, K;

int main()
{
	int tempWeight, tempValue;
	long long int totalPrice = 0;
	//����� �ӵ� ����
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> tempWeight >> tempValue;
		jewels.push_back(Jewel(tempWeight, tempValue));
	}
	for (int i = 0; i < K; i++)
	{
		cin >> tempWeight;
		Bags.insert(tempWeight);
	}
	jewels.sort();

	//���� ��� ��������, �� �� �ִ� ���� ���� ������ ���
	for (auto iter1 = jewels.begin(); iter1 != jewels.end(); iter1++)
	{
		auto iter2 = Bags.lower_bound(iter1->weight);
		if (iter2 != Bags.end())
		{
			totalPrice += iter1->price;
			Bags.erase(iter2);
			//��� ������ ����Ұ�� ����
			if (Bags.size() == 0)
			{
				cout << totalPrice;
				return 0;
			}
		}
	}
	cout << totalPrice;
	return 0;
}
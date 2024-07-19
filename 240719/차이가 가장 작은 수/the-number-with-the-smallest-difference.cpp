#include <iostream>
#include <set>
using namespace std;

int m, n;
set <int> s;

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		s.insert(a);
	}

	set<int>::iterator iter;
	set<int>::iterator iter2;

	iter = s.begin();
	iter2 = s.begin();
	int prev = *iter;
	int minimum = 987654321;
	while (iter != s.end()&&iter2!=s.end())
	{
		int gap = *iter - *iter2;

		if (gap >= m && gap < minimum)
		{
			minimum = gap;
			iter2++;
		}
		else if (gap < m)
			iter++;
		else if (gap >= minimum)
			iter2++;
	}

	cout << minimum;

	return 0;
}
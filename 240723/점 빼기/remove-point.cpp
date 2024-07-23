#include <iostream>
#include <set>
using namespace std;

int m, n;
set<pair<int, int>> s;


int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		s.insert(make_pair(x, y));
	}

	for (int i = 0; i < m; i++)
	{
		int k;
		cin >> k;

		if (s.upper_bound(make_pair(k, -1)) == s.end())
			cout << "-1 -1" << '\n';
		else
		{
			pair<int, int> target = *s.upper_bound(make_pair(k, -1));
			int x, y;
			x = target.first;
			y = target.second;

			cout << x << ' ' << y << '\n';
			s.erase(make_pair(x, y));
		}
	}



	return 0;
}
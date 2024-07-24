#include <iostream>
#include <set>
#include <string>
using namespace std;

int m, n;
set<pair<int, int>> s;//난이도,문제 번호

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;

		s.insert(make_pair(b, a));
	}

	cin >> m;


	for (int i = 0; i < m; i++)
	{
		string str;
		int x, y;
		cin >> str;
		if (str == "ad")
		{
			cin >> x >> y;
			s.insert(make_pair(y, x));
		}
		else if (str == "sv")
		{
			cin >> x >> y;
			s.erase(make_pair(y, x));
		}
		else
		{
			cin >> x;
			if (x == 1)
				cout << s.rbegin()->second<<'\n';
			else
				cout << s.begin()->second<<'\n';
		}
	}

	return 0;
}
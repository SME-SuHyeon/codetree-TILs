#include <iostream>
#include <vector>
#include <set>
using namespace std;

set<pair<int, int>> s;
int n, m;

int main()
{
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		s.insert(make_pair(a, b));
	}

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		pair<int, int> tmp;
		if (s.lower_bound(make_pair(a, b)) == s.end())
			cout << "-1 -1\n";
		else
		{
			tmp = *s.lower_bound(make_pair(a, b));
			cout << tmp.first << ' ' << tmp.second << '\n';
		}
	}



	return 0;
}
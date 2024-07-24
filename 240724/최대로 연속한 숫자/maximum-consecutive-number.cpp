#include <iostream>
#include <set>
#include <string>
#include <tuple>
using namespace std;

int m, n;

set<int> dot;
set<int>::iterator iter;
set<tuple<int, int, int>> s;

int main()
{
	cin >> n >> m;

	dot.insert(n + 1);
	dot.insert(-1);

	s.insert(make_tuple(-(n + 1), -1, n + 1));

	for (int i = 0; i < m; i++)
	{
		int a,b,c;
		cin >> b;

		dot.insert(b);

		iter = dot.find(b);

		iter--;
		a = *iter;
		iter++;
		iter++;
		c = *iter;

		s.erase(make_tuple(-(c - a - 1), a, c));

		s.insert(make_tuple(-(b - a - 1), a, b));
		s.insert(make_tuple(-(c - b - 1), b, c));

		int best_length;
		tie(best_length, ignore, ignore) = *s.begin();
		cout << -best_length << '\n';
	}

	return 0;
}
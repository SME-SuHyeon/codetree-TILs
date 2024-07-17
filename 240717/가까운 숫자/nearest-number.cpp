#include <iostream>
#include <vector>
#include <set>
using namespace std;

set <int> s;
int m, n;
int a, b;

int main()
{
	cin >> n;
	
	s.insert(0);

	set <int>::iterator iter;

	int ans = 1000000001;

	for (int i = 0; i < n; i++)
	{
		a = b = -987654321;
		cin >> m;
		s.insert(m);

		iter = s.upper_bound(m);
		if (iter != s.end())
			a = *iter;
		iter--;
		iter--;

		b = *iter;

		int dis1 = abs(a - m);
		int dis2 = abs(b - m);

		if (dis1 < ans)
			ans = dis1;
		if (dis2 < ans)
			ans = dis2;

		cout << ans << '\n';
	}

	return 0;
}
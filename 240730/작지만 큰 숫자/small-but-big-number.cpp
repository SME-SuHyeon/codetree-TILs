#include <iostream>
#include <set>
#include <string>
#include <tuple>
using namespace std;

set<int> s;
int m, n;

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		s.insert(x);
	}

	set<int>::iterator iter;

	for (int i = 0; i < m; i++)
	{
		int x;
		cin >> x;

		iter = s.upper_bound(x);
		
		if (iter == s.begin())
			cout << "-1\n";
		else
		{
			iter--;
			cout << *iter << '\n';
			s.erase(*iter);
		}

	}

	return 0;
}
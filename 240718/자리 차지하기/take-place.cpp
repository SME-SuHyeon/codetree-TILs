#include <iostream>
#include <set>
using namespace std;

int m, n;
set <int> s;
int ans = 0;

int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
		s.insert(-i - 1);


	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;

		if (s.lower_bound(-a) != s.end())
		{
			s.erase(-a);
			ans++;
		}

	}
	cout << ans;


	return 0;
}
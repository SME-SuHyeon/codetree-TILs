#include<iostream>
#include<set>
using namespace std;

set<int> s;
int m, n;

int main()
{
	int a;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		s.insert(a);
	}

	for (int i = 0; i < m; i++)
	{
		cin >> a;
		if (s.lower_bound(a) == s.end())
			cout << "-1\n";
		else
			cout << *s.lower_bound(a) << '\n';
	}

	return 0;
}
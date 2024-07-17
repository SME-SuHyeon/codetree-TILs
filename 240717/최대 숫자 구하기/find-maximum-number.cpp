#include <iostream>
#include <vector>
#include <set>
using namespace std;

set <int> s;
int m, n;

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
		s.insert(i);

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;

		s.erase(a);

		cout << *s.rbegin()<<'\n';
	}


	return 0;
}
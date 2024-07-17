#include <iostream>
#include <vector>
#include <set>
using namespace std;

set <int> s;
int m, n;

int main()
{
	cin >> n >> m;


	int a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		s.insert(a);
	}

	set <int>::iterator iter;

	iter = s.end();

	for (int i = 0; i < m; i++)
	{
		iter--;
		cout << *iter << ' ';
	}

	return 0;
}
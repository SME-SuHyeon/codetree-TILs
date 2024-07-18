#include <iostream>
#include <set>
using namespace std;

int m, n;
set <int> s;
int ans = 0;

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
		s.insert(-i);

	int a, b;
	set<int>::iterator iter;


	for (int i = 0; i < n; i++)
	{
		cin >> a;

		//for (iter = s.begin(); iter != s.end(); iter++)
		//{
		//	cout << *iter << ' ';
		//}
		//cout << '\n';

		if (s.lower_bound(-a) != s.end())
		{
			b = *s.lower_bound(-a);
			s.erase(b);
			ans++;
		}
		else
			break;

		
	}

	//for (iter = s.begin(); iter != s.end(); iter++)
	//{
	//	cout << *iter << ' ';
	//}
	//cout << '\n';

	cout << ans;


	return 0;
}
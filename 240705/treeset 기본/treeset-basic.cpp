#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <set>
using namespace std;

set <int> s;
int n,a;
string str;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> str;

		if (str == "add")
		{
			cin >> a;
			s.insert(a);
		}
		else if (str == "remove")
		{
			cin >> a;
			s.erase(a);
		}
		else if (str == "find")
		{
			cin >> a;
			if (s.find(a) == s.end())
				cout << "false"<<'\n';
			else
				cout << "true" << '\n';
		}
		else if (str == "lower_bound")
		{
			cin >> a;
			if (s.lower_bound(a) == s.end())
				cout << "None" << '\n';
			else
				cout << *s.lower_bound(a) << '\n';
		}
		else if (str == "upper_bound")
		{
			cin >> a;
			if (s.upper_bound(a) == s.end())
				cout << "None" << '\n';
			else
				cout << *s.upper_bound(a) << '\n';
		}
		else if (str == "largest")
		{
			if (s.rbegin() != s.rend())
			{
				cout << *s.rbegin() << '\n';
			}
			else
				cout << "None" << '\n';
		}
		else if (str == "smallest")
		{
			if (s.begin() != s.end())
				cout << *s.begin() << '\n';
			else
				cout << "None" << '\n';
		}
	}


	return 0;
}
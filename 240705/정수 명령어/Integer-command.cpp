#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <set>
using namespace std;

set <int> s;
int test_case, k, n;
char command;

int main()
{
	cin >> test_case;
	for (int t = 0; t < test_case; t++)
	{
		cin >> k;
		s.clear();
		for (int d = 0; d < k; d++)
		{
			cin >> command >> n;
			if (command == 'I')
				s.insert(n);
			else if (command == 'D')
			{
				if (n == 1)
				{
					if (s.rbegin() != s.rend())
						s.erase(*s.rbegin());
				}
				else if (n == -1)
				{
					if (s.begin() != s.end())
					{
						s.erase(*s.begin());
					}
				}
			}
		}
		if (s.end() == s.begin())
			cout << "EMPTY\n";
		else
			cout << *s.rbegin() << ' ' << *s.begin() << '\n';
	}


	

	return 0;
}
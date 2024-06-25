#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;


map <int, int> m;
map<int, int> ::iterator iter;
string str;
int n,v,k;

int main()
{
	cin >> n;


	for (int i = 0; i < n; i++)
	{
		cin >> str;

		if (str == "add")
		{
			cin >> k >> v;
			m[k] = v;
		}
		else if (str == "remove")
		{
			cin >> k;
			m.erase(k);
		}
		else if (str == "find")
		{
			cin >> k;
			if (m.find(k) == m.end())
				cout << "None" << '\n';
			else
				cout << m[k] << '\n';
		}
		else if (str == "print_list")
		{
			if (m.size() == 0)
				cout << "None" << '\n';
			else
			{
				for (iter = m.begin(); iter != m.end(); iter++)
				{
					cout << iter->second << ' ';
				}
				cout << '\n';
			}
		}



	}

	return 0;
}
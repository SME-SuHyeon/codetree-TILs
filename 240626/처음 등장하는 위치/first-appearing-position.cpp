#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

map<int, int> m;
int n;

int main()
{
	cin >> n;
	int tmp;
	for (int i = 1; i <= n; i++)
	{
		cin >> tmp;

		if (m.find(tmp) == m.end())
			m[tmp] = i;
	}

	map<int, int>::iterator iter;

	for (iter = m.begin(); iter != m.end(); iter++)
		cout << iter->first << ' ' << iter->second << '\n';

	return 0;
}
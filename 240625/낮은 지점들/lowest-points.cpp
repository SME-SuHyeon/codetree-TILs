#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n;
unordered_map <int, int> m;

int main()
{
	cin >> n;
	int x, y;

	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;

		if (m.find(x) == m.end())
		{
			m[x] = y;
		}
		else
		{
			if (m[x] > y)
				m[x] = y;
		}

	}
	long long int ans = 0;

	unordered_map<int, int>::iterator iter;

	for (iter = m.begin(); iter != m.end(); iter++)
	{
		ans += (long long int)iter->second;
	}

	cout << ans;

	return 0;
}
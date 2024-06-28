#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

unordered_set<string> s;
int m, n;
int ans;
string a[505], b[505];

int cmp_str(int z, int y, int x)
{

	string str;
	for (int i = 0; i < n; i++)
	{
		str = a[i][z] + a[i][y] + a[i][x];
		s.insert(str);
	}

	for (int i = 0; i < n; i++)
	{
		str = b[i][z] + b[i][y] + b[i][x];
		if (s.find(str) != s.end())
			return 0;
	}


	return 1;
}

int main()
{
	cin >> n >> m;

	for(int i=0;i<n;i++)
		cin >> a[i];

	for(int i=0;i<n;i++)
		cin >> b[i];

	for (int z = 0; z < m-2; z++)
	{
		for (int y = z + 1; y < m - 1; y++)
		{
			for (int x = y + 1; x < m; x++)
			{
				ans += cmp_str(z, y, x);
				s.clear();
			}
		}
	}

	cout << ans;

	return 0;
}
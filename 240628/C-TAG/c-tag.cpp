#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

unordered_set<string> s;
int m, n;
int ans,cnt;
string a[505], b[505];

int cmp_str(int z, int y, int x)
{

	string str;
	for (int i = 0; i < n; i++)
	{
		s.insert(a[i].substr(x, 1) + a[i].substr(y, 1) + a[i].substr(z, 1));
	}
	//cout << "=====================" << ++cnt<<'\n';

	for (int i = 0; i < n; i++)
	{
		if (s.find(b[i].substr(x, 1) + b[i].substr(y, 1) + b[i].substr(z, 1)) != s.end())
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
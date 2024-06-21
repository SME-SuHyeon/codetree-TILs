#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

unordered_map<int, int> hash_map[1005];
int n;
int cnt[1005],ans;

int main()
{
	cin >> n;
	
	string str;

	for (int i = 0; i < n; i++)
	{
		cnt[i] = 1;

		cin >> str;
		for (int s = 0; s < str.length(); s++)
			hash_map[i][str[s] - 'a']++;
	}

	unordered_map<int, int>::iterator iter;
	int mode;
	for (int x = 0; x < n-1; x++)
	{
		for (int y = x + 1; y < n; y++)
		{
			mode = 0;
			for (iter = hash_map[x].begin(); iter != hash_map[x].end(); iter++)
			{
				if (iter->second != hash_map[y][iter->first])
					mode = 1;
			}

			if (mode == 0)//같은거라면
			{
				cnt[y] += cnt[x];

				ans = max(ans, cnt[y]);

				x++;
				y = x + 1;
			}
		}
	}

	cout << ans;



	return 0;
}
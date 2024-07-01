#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

unordered_set<int> group[250005];
unordered_set<int>::iterator iter;
vector<int> invited_group[100005];
int n, g;

int queue[250005],top,bottom;
int ans;

void enque(int a)
{
	queue[top++] = a;
}
int deque()
{
	return queue[bottom++];
}

void invite(int a)
{
	for (int i = 0; i < invited_group[a].size(); i++)
	{
		int cur_group = invited_group[a][i];
		group[cur_group].erase(a);
		if (group[cur_group].size() == 1)
		{
			for (iter = group[cur_group].begin(); iter != group[cur_group].end(); iter++)
			{
				enque(*iter);
				ans++;
				//cout << "NOW: " << *iter << '\n';
			}
		}
	}
}

int main()
{
	cin >> n >> g;
	int a,b;

	for (int i = 1; i <= g; i++)
	{
		cin >> a;
		for (int k = 0; k < a; k++)
		{
			cin >> b;
			group[i].insert(b);
			invited_group[b].push_back(i);
		}
	}

	invite(1);

	while (top != bottom)
		invite(deque());

	cout << ++ans;

	return 0;
}
#include <iostream>
#include <set>
#include <string>
#include <tuple>
#include <queue>
using namespace std;

priority_queue <pair<int, int>> pq;
priority_queue <pair<int, int>> waiting;

int n;
int garden_time[10005];
int waited_time[10005];

int cur_time = 0;

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int a, t;
		cin >> a >> t;
		
		garden_time[i] = t;
		pq.push(make_pair(-a, -i));
	}

	pair<int, int> top,tmp;

	while (pq.empty() == false)
	{
		top = pq.top();

		if (waiting.empty() == true||(cur_time>=-top.first))
		{
			tmp.first = top.second;
			tmp.second = top.first;

			waiting.push(tmp);
			pq.pop();

			cur_time = max(cur_time, -top.first);
		}
		else
		{
			tmp = waiting.top();
			waiting.pop();

			waited_time[-tmp.first] = cur_time - (-tmp.second);

			cur_time += garden_time[-tmp.first];
		}
	}

	int maximum = 0;
	for (int i = 1; i <= n; i++)
	{
		if (maximum < waited_time[i])
			maximum = waited_time[i];
	}

	cout << maximum;


	return 0;
}
#include <iostream>
#include <set>
#include <string>
#include <tuple>
#include <queue>
using namespace std;


priority_queue <pair<int, int>> pq;

int n, m;


int main()
{

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;

		pq.push(make_pair(-x - y, -x));
	}

	for (int i = 0; i < m; i++)
	{
		pair<int, int> p;
		p = pq.top();
		pq.pop();

		p.first -= 4;
		p.second -= 2;

		pq.push(p);
	}

	pair<int, int> ans;
	ans = pq.top();

	int a, b;
	a = ans.first;
	b = ans.second;

	cout << -b << ' ' << -a + b;
	
	return 0;
}
#include <iostream>
#include <set>
#include <string>
#include <tuple>
#include <queue>
using namespace std;

priority_queue<int> pq;
int n,m;

int main()
{
	cin >> n>>m;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		pq.push(x);
	}
	

	for (int i = 0; i < m; i++)
	{
		int tmp = pq.top();
		pq.pop();
		tmp--;
		pq.push(tmp);
	}

	cout << pq.top();

	return 0;
}
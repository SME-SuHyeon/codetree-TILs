#include <iostream>
#include <set>
#include <string>
#include <tuple>
#include <queue>
using namespace std;


priority_queue <int> pq;
int n;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		pq.push(x);
	}

	while (pq.size() > 1)
	{
		int a, b;
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop();

		if (a - b != 0)
			pq.push(a - b);
	}

	if (pq.empty() == true)
		cout << "-1";
	else
		cout << pq.top();
	
	
	return 0;
}
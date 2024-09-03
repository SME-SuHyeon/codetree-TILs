#include <iostream>
#include <set>
#include <string>
#include <tuple>
#include <queue>
using namespace std;

priority_queue<int> pq;
int n;
int a, b, c;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;

		pq.push(-x);

		if (pq.size() < 3)
			cout << "-1\n";
		else
		{
			a = -pq.top();
			pq.pop();
			b = -pq.top();
			pq.pop();
			c = -pq.top();
			pq.pop();

			cout << a * b * c << "\n";

			pq.push(-a);
			pq.push(-b);
			pq.push(-c);
		}
	}

	return 0;
}
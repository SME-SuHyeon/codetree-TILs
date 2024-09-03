#include <iostream>
#include <set>
#include <string>
#include <tuple>
#include <queue>
using namespace std;

priority_queue<long long int> pq;
int n;
long long int a, b, c;
long long int ans;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;

		pq.push(-x);

		if (i < 2)
			cout << "-1\n";
		else
		{
			a = -pq.top();
			pq.pop();
			b = -pq.top();
			pq.pop();
			c = -pq.top();
			pq.pop();

			ans = a * b * c;
			cout << ans << "\n";

			pq.push(-a);
			pq.push(-b);
			pq.push(-c);
		}
	}

	return 0;
}
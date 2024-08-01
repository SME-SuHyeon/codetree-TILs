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
		if (x == 0)
		{
			if (pq.empty() == true)
				cout << "0\n";
			else
			{
				cout << -pq.top() << '\n';
				pq.pop();
			}
		}
		else
			pq.push(-x);
	}


	return 0;
}
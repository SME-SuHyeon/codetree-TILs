#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue <pair<int, int>> pq;
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
			if (pq.empty() == false)
			{
				cout << -pq.top().second << '\n';
				pq.pop();
			}
			else
				cout << "0\n";
		}
		else
		{
			pq.push(make_pair(-abs(x), -x));

		}

	}


	return 0;
}
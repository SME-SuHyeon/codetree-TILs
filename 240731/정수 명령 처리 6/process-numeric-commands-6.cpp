#include <iostream>
#include <set>
#include <string>
#include <tuple>
#include <queue>
using namespace std;

priority_queue<int> pq;
int n;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		int x;
		cin >> str;

		if (str == "push")
		{
			cin >> x;
			pq.push(x);
		}
		else if (str == "pop")
		{
			cout << pq.top() << '\n';
			pq.pop();
		}
		else if (str == "size")
		{
			cout << pq.size() << '\n';
		}
		else if (str == "empty")
		{
			if (pq.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (str == "top")
		{
			cout << pq.top() << '\n';
		}

		
	}


	return 0;
}
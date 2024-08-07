#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> big, small;

int n;
int t;



int main()
{
	cin >> t;

	for (int test = 0; test < t; test++)
	{
		cin >> n;
		int element,middle;
		cin >> element;

		middle = element;

		cout << middle << ' ';

		for (int i = 0; i < n-1; i++)
		{
			cin >> element;
			if (element >= middle)
				big.push(-element);
			else if (element < middle)
				small.push(element);
			
			if (i % 2 == 1)
			{
				if (big.size() > small.size())
				{
					small.push(middle);
					middle = -big.top();
					big.pop();
				}
				else if (big.size() < small.size())
				{
					big.push(-middle);
					middle = small.top();
					small.pop();
				}


				cout << middle << ' ';
			}

		}

		while (big.size() != 0)
			big.pop();

		while (small.size() != 0)
			small.pop();

		cout << '\n';
	}


	return 0;
}
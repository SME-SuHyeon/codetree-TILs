#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

unordered_set<int> s;
int a, b;

int main()
{
	cin >> a >> b;
	int element;
	for (int i = 0; i < a; i++)
	{
		cin >> element;

		s.insert(element);
	}

	for (int i = 0; i < b; i++)
	{
		cin >> element;

		if (s.find(element) == s.end())
			s.insert(element);
		else
			s.erase(element);
	}

	cout << s.size();

	return 0;
}
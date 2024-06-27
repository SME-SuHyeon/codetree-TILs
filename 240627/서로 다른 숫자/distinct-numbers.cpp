#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

unordered_set<int> s;
int n;


int main()
{
	
	cin >> n;
	int a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		s.insert(a);
	}

	cout << s.size();

	return 0;
}
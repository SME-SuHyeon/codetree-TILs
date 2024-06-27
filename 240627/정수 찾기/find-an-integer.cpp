#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

unordered_set<int> s;
int n,m;


int main()
{
	cin >> n;
	int a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		s.insert(a);
	}
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> a;
		if (s.find(a) != s.end())//있으면
			cout << "1\n";
		else
			cout << "0\n";
	}
	
	return 0;
}
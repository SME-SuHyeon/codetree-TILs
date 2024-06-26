#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

map<string, int> m;
int n;

double ratio = 100;

int main()
{
	cin >> n;
	string str;
	for (int i = 0; i < n; i++)
	{
		cin >> str;

		m[str]++;
	}

	map<string, int>::iterator iter;

	for (iter = m.begin(); iter != m.end(); iter++)
	{
		cout << iter->first << ' ';
		printf("%.4f\n", (double)iter->second * 100 / n);
	}

	return 0;
}
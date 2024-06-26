#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_set>
using namespace std;

unordered_set<int> s;
int n,v;

int main()
{
	cin >> n;
	string str;
	for (int i = 0; i < n; i++)
	{
		cin >> str >> v;


		if (str == "find")
		{
			if (s.find(v) == s.end())
				cout << "false\n";
			else
				cout << "true\n";
		}
		else if (str == "add")
			s.insert(v);
		else if (str == "remove")
			s.erase(v);


	}


	return 0;
}
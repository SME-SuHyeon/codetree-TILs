#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string str;
unordered_map <int, int> m;


int main()
{
	cin >> str;

	int len = str.length();

	for (int i = 0; i < len; i++)
	{
		m[str[i] - 'a']++;
	}


	for (int i = 0; i < len; i++)
	{
		if (m[str[i]- 'a'] == 1)
		{
			cout << str[i];
			return 0;
		}
	}

	cout << "None";


	return 0;
}
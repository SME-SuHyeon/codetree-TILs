#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_set>
using namespace std;

int arr1[100005], arr2[100005];
int m, n,a;

unordered_set<int> s1;
unordered_set<int> s2;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		arr1[i] = a;
		s1.insert(arr1[i]);
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a;
		arr2[i] = a;
		s2.insert(arr2[i]);
	}
	
	for (int i = 0; i < m; i++)
	{
		if (s1.find(arr2[i]) == s1.end())
			cout << "0 ";
		else
			cout << "1 ";
	}




	return 0;
}
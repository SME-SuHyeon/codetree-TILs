#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

unordered_set<int> s[100005];
int n, k;
int a[100005], b[100005];
int arr[100005];


void swap(int A, int B)
{
	int tmp = arr[A];
	arr[A] = arr[B];
	arr[B] = tmp;
}

int main()
{
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		arr[i] = i;
		s[i].insert(arr[i]);
	}
	for (int i = 0; i < k; i++)
		cin >> a[i] >> b[i];

	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < k; i++)
		{
			swap(a[i], b[i]);

			s[arr[a[i]]].insert(a[i]);
			s[arr[b[i]]].insert(b[i]);
		}
	}

	for (int i = 1; i <= n; i++)
		cout << s[i].size() << '\n';



	return 0;
}
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

unordered_set<int> s;
int n;
int arr[1005];


int main()
{
	cin >> n;

	long long int ans = 0;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	for (int i = n; i >= 1; i--)
	{
		ans += arr[n - i] * i;
	}

	cout << ans;


	return 0;
}
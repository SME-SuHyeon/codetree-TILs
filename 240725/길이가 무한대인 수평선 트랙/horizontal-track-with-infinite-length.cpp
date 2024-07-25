#include <iostream>
#include <set>
#include <string>
#include <tuple>
using namespace std;

set<pair<long long int,long long int>> s;
long long int n, t;

int main()
{
	cin >> n >> t;

	for (int i = 0; i < n; i++)
	{
		long long int start, velocity;

		cin >> start >> velocity;

		s.insert(make_pair(start, velocity));
	}

	set<pair<long long int, long long int>>::iterator iter1;
	set<pair<long long int, long long int>>::iterator iter2;
	iter1 = s.end();
	iter2 = s.end();
	iter1--;
	iter1--;
	iter2--;

	long long int v1, v2, s1, s2;
	long long int s1_arrive, s2_arrive;

	for (int i = 0; i < n - 1; i++)
	{
		s1 = iter1->first;
		v1 = iter1->second;
		s2 = iter2->first;
		v2 = iter2->second;

		s1_arrive = s1 + (v1 * t);
		s2_arrive = s2 + (v2 * t);

		if (s1_arrive >= s2_arrive)//만났을 때
		{
			iter1--;
			s.erase(make_pair(s1,v1));
		}
		else//못 만났을 때
		{
			iter1--;
			iter2--;
		}
	}

	cout << s.size();

	return 0;
}
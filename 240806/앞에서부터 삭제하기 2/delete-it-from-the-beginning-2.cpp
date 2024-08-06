#include <iostream>
#include <queue>
using namespace std;

int arr[100005];
int sum,n;
priority_queue<int> pq;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	pq.push(-arr[n - 1]);
	sum += arr[n - 1];

	double cnt = 1;
	double avg = -999999;

	for (int i = n - 2; i >= 0; i--)
	{
		pq.push(-arr[i]);
		sum += arr[i];

		int minimum = pq.top();

		sum += minimum;

		double tmp_avg;
		tmp_avg = sum / cnt;

		if (tmp_avg >= avg)
			avg = tmp_avg;

		cnt++;
		sum -= minimum;
	}

	printf("%.2f", avg);


	return 0;
}
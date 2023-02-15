#include <cmath>
#include <algorithm>

using namespace std;

long long arr[1000001];

long long solution(int k, int d)
{
	long long answer = 0;
	long long d2 = (long long)d * d;

	for (long long i = 0; i <= d; ++i)
		arr[i] = i * i;

	for (long long i = 0; i <= d; i += k)
	{
		long long* r = lower_bound(arr, arr + d + 1, (d2 - i * i));

		if (r != arr + d + 1)
		{
			if (*r != d2 - i * i && 0 != d2 - i * i)
				--r;
			answer += sqrt(*r) / k + 1;
		}
	}

	return answer;
}
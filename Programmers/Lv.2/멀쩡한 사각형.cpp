#include <algorithm>
using namespace std;

int getGCD(int a, int b)
{
	if (b == 0)
		return a;
	return getGCD(b, a % b);
}

long long solution(int w, int h) {
    long long answer = 1;
	int gcd = getGCD(max(w, h), min(w, h));
	
	return (long long)w * h - (w / gcd + h / gcd - 1) * gcd;
}
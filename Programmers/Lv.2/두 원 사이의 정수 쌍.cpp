#include <cmath>

using namespace std;

double getY(long long x, long long r)
{
    double res = sqrt(r*r - x*x);
    
    if (isnan(res)) 
        return 0;
    return res;
}

long long solution(int r1, int r2) {
    long long answer = 0;
    
    for (int i=1; i<=r2; ++i)
        answer += floor(getY(i, r2)) - ceil(getY(i, r1)) + 1;
    return answer * 4;
}
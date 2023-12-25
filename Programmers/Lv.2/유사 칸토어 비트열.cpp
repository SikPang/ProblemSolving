#include <string>
#include <vector>

using namespace std;

int solution(int n, long long l, long long r) {
    int answer = 0;
    
    --l;
    --r;
    while (l <= r)
    {
        long long idx = l;
        bool isZero = false;
        
        while (idx / 5 > 0)
        {
            if (idx / 5 == 2 || idx % 5 == 2)
            {
                isZero = true;
                break;
            }
            idx /= 5;
        }
        if (!isZero && l % 5 != 2)
            ++answer;
        ++l;
    }
    return answer;
}
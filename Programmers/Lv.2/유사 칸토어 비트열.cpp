#include <string>
#include <vector>

using namespace std;

int solution(int n, long long l, long long r) {
    int answer = 0;
    
    while (l-1 <= r-1)
    {
        long long idx = l-1;
        bool isZero = false;
        
        while (idx > 0)
        {
            if (idx / 5 == 2 || idx % 5 == 2)
            {
                isZero = true;
                break;
            }
            idx /= 5;
        }
        if (!isZero)
            ++answer;
        ++l;
    }
    return answer;
}
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int getLastDivisor(int num)
{
    if (num == 1)
        return 0;
    
    int min = sqrt(num);
    int cur = -1;
    
    for (int i=2; i<=min; ++i)
    {
        if (num % i == 0)
        {
            if (num/i <= 10000000)
                return num/i;
            cur = i;
        }
    }
    
    if (cur == -1)
        return 1;
    return cur;
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer(end-begin+1);
    
    for (int i=0; i<answer.size(); ++i)
        answer[i] = getLastDivisor(begin+i);  
    
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long left = 1;
    long long right = *max_element(times.begin(), times.end()) * (long long)n;
    long long answer = right;
    
    while (left <= right){
        long long mid = (right + left) / 2;
        long long confirmCount = 0;
        
        for (int i=0; i<times.size(); ++i){
            confirmCount += mid / times[i];
        }
        
        if (confirmCount >= n){
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return answer;
}
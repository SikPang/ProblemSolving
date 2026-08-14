#include <string>
#include <vector>
#include <limits.h>
#include <iostream>

using namespace std;

bool CanSolve(vector<int>& diffs, vector<int>& times, long long limit, int level){
    long long time = 0;

    for (int i=0; i<diffs.size(); ++i){
            int curDiff = diffs[i];

            if (curDiff <= level){
                time += times[i];
            } else {
                int retryTime = (i > 0 ? times[i-1] : 0) + times[i];
                time += retryTime * (curDiff - level) + times[i];
            }

            if (time > limit){
                return false;
            }
        }
    return true;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int left = 1;
    int right = INT_MIN;
    
    for (int i=0; i<diffs.size(); ++i){
        right = max(right, diffs[i]);
    }
    
    while (left < right){
        int level = (right + left) / 2;

        if (CanSolve(diffs, times, limit, level)){
            right = level;
        } else {
            left = level + 1;
        }
    }
    return left;
}
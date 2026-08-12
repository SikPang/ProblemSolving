#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> signals) {
    vector<int> curSignal(signals.size());
    vector<int> leftTime(signals.size());
    int maxTime = 1;
    
    // 초록불로 초기화
    for (int i=0; i<leftTime.size(); ++i){
        leftTime[i] = signals[i][0];
    }

    for (int i=0; i<signals.size(); ++i){
        maxTime *= signals[i][0] + signals[i][1] + signals[i][2];
    }

    for (int time=1; time<=maxTime; ++time){
        bool isBlackout = true;

        for (int i=0; i<signals.size(); ++i){ 
            if (leftTime[i] == 0){
                int nextSignal = (curSignal[i] + 1) % 3;
                curSignal[i] = nextSignal;
                leftTime[i] = signals[i][nextSignal];
            }
            --leftTime[i];
            
            if (curSignal[i] != 1){
                isBlackout = false;
            }
        }
        
        if (isBlackout) return time;
    }
    return -1;
}
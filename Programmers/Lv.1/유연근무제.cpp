#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    for (int i=0; i<schedules.size(); ++i){
        int target_hour = schedules[i] / 100.0f;
        int target_minute = schedules[i] % 100;
        int cur_day = startday - 1;
        bool late = false;

        for (int j=0; j<timelogs[i].size(); ++j){
            if (cur_day < 5){
                int cur_hour = timelogs[i][j] / 100.0f;
                int cur_minute = timelogs[i][j] % 100;
                int hour_diff = cur_hour - target_hour;
                int minute_diff = cur_minute - target_minute;

                if (hour_diff * 60 + minute_diff > 10){
                    late = true;
                    break;
                }
            }
            cur_day = (cur_day + 1) % 7;
        }
            
        if (!late){
            ++answer;
        }
    }
    
    return answer;
}
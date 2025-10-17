#include <string>
#include <vector>

using namespace std;

pair<int, int> videoLen;
pair<int, int> opStart;
pair<int, int> opEnd;
pair<int, int> startPoint = make_pair(0, 0);

pair<int, int> GetTimeFromString(string str){
    int minute = (str[0] - 48) * 10 + (str[1] - 48);
    int second = (str[3] - 48) * 10 + (str[4] - 48);
    return make_pair(minute, second);
}

string GetStringFromTime(pair<int, int>& time){
    string minute = to_string(time.first);
    string second = to_string(time.second);

    string ret = "";
    if (minute.size() == 1) ret += "0";
    ret += minute;
    ret += ":";
     if (second.size() == 1) ret += "0";
    ret += second;
    return ret;
}

int Compare(pair<int, int>& a, pair<int, int>& b){
    if (a.first == b.first && a.second == b.second) return 0;
    if (a.first > b.first || (a.first == b.first && a.second > b.second)) return -1;
    return 1;
}

void MoveTime(pair<int, int>& curTime, int moveSec){
    if (Compare(curTime, opStart) <= 0 && Compare(curTime, opEnd) > 0){
        curTime.first = opEnd.first;
        curTime.second = opEnd.second;
    }

    curTime.second += moveSec;

    if (curTime.second >= 60){
        ++curTime.first;
        curTime.second -= 60;
    } else if (curTime.second < 0){
        --curTime.first;
        curTime.second = 60 + curTime.second;
    }

    if (Compare(curTime, videoLen) < 0){
        curTime.first = videoLen.first;
        curTime.second = videoLen.second;
    } else if (Compare(curTime, startPoint) > 0){
        curTime.first = 0;
        curTime.second = 0;
    }
    
    if (Compare(curTime, opStart) <= 0 && Compare(curTime, opEnd) > 0){
        curTime.first = opEnd.first;
        curTime.second = opEnd.second;
    }
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    videoLen = GetTimeFromString(video_len);
    opStart = GetTimeFromString(op_start);
    opEnd = GetTimeFromString(op_end);
    
    pair<int, int> curTime = GetTimeFromString(pos);
    
    for (int i=0; i<commands.size(); ++i){
        MoveTime(curTime, commands[i] == "next" ? 10 : -10);
    }
    
    return GetStringFromTime(curTime);
}
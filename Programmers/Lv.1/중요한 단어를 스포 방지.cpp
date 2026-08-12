#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iostream>

using namespace std;

int solution(string message, vector<vector<int>> spoiler_ranges) {
    int answer = 0;
    unordered_map<string, pair<int, int>> wordMap;
    stringstream ss(message);
    string token;
    int startIdx = 0;

    while (getline(ss, token, ' ')) {
        pair<int, int>& wordInfo = wordMap[token];
        int endIdx = token.size() - 1 + startIdx;

        for (int i=0; i<spoiler_ranges.size(); ++i){
            if ((endIdx <= spoiler_ranges[i][1] && endIdx >= spoiler_ranges[i][0] )
                || (endIdx > spoiler_ranges[i][1] && startIdx <= spoiler_ranges[i][1])) {
                ++wordInfo.second;
                break;
            }
        }
        ++wordInfo.first;
        startIdx = endIdx + 2;
    }
    
    for (auto iter = wordMap.begin(); iter != wordMap.end(); ++iter){
        if (iter->second.second > 0 && iter->second.first == iter->second.second){
            ++answer;
        }
    }
                
    return answer;
}
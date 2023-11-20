#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    unordered_map<char, int> expireTime;
    int todayYear = stoi(today.substr(0, 4));
    int todayMonth = stoi(today.substr(5, 2));
    string todayDay = today.substr(8, 2);
    
    for (int i=0; i<terms.size(); ++i)
        expireTime[terms[i][0]] = stoi(terms[i].substr(2, terms[i].size()-2));
    
    for (int i=0; i<privacies.size(); ++i)
    {
        int curMonth = stoi(privacies[i].substr(5, 2)) + expireTime[privacies[i][11]];       
        int gap = curMonth / 12;
        curMonth = curMonth % 12;
        if (curMonth == 0)
        {
            curMonth = 12;
            --gap;
        }
        int curYear = stoi(privacies[i].substr(0, 4)) + gap;
        
        if ((todayYear > curYear)
            || (todayYear == curYear && todayMonth > curMonth)
            || (todayYear == curYear && todayMonth == curMonth && todayDay >= privacies[i].substr(8, 2)))
            answer.push_back(i+1);
    }
    return answer;
}
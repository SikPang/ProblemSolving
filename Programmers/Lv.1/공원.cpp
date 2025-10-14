#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool IsValid(vector<vector<string>> park, int y, int x, int length){
    for (int j = y; j < y + length; ++j){
        for (int k = x; k < x + length; ++k){
            if (park[j][k] != "-1") return false;
        }
    }
    return true;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    sort(mats.rbegin(), mats.rend());
    
    for (int i = 0; i < mats.size(); ++i){
        int length = mats[i];
        if (length > park.size() || length > park[0].size()) continue;

        for (int j = 0; j <= park.size() - length; ++j){
            for (int k = 0; k <= park[0].size() - length; ++k){
                if (park[j][k] == "-1" && IsValid(park, j, k, length)){
                    return length;
                }
            }
        }
    }
    return -1;
}
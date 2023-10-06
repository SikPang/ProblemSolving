#include <string>
#include <vector>
#include <climits>
using namespace std;

int minFatigue = INT_MAX;

void dfs(vector<int>& pickedPicks, vector<int>& picks, vector<string>& minerals, int depth, int picksCount)
{
    // depth 하나마다 곡괭이 하나 챙기기
    if (depth == picksCount || depth == minerals.size() / 5 + 1)
    {
        int curPick = 0;
        int durability = 5;
        int fatigue = 0;
        
        for (int i=0; i<minerals.size(); ++i)
        {
            if (durability == 0)
            {
                ++curPick;
                durability = 5;
            }
            if (curPick == pickedPicks.size())
                break;
            
            if (pickedPicks[curPick] == 2 && minerals[i] == "diamond")
                fatigue += 25;
            else if ((pickedPicks[curPick] == 1 && minerals[i] == "diamond")
               || (pickedPicks[curPick] == 2 && minerals[i] == "iron"))
                fatigue += 5;
            else
                fatigue += 1;
            --durability;
        }
        if (minFatigue > fatigue)
            minFatigue = fatigue;
        return;
    }
    
    for (int i=0; i<3; ++i)
    {
        if (picks[i])
        {
            --picks[i];
            pickedPicks[depth] = i;
            dfs(pickedPicks, picks, minerals, depth+1, picksCount);
            ++picks[i];
        }
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    int picksCount = picks[0] + picks[1] + picks[2];
    vector<int> pickedPicks(picksCount);
    
    dfs(pickedPicks, picks, minerals, 0, picksCount);
    return minFatigue;
}
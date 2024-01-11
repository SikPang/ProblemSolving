#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

// 두 사람간의 주고받은 횟수
// 모든 친구들간의 주고받은 횟수

struct GiftInfo
{
    unordered_map<string, int> sendList;
    int recvCount;
    int sendCount;
    GiftInfo() : sendList(), recvCount(0), sendCount(0) {}
};

int solution(vector<string> friends, vector<string> gifts) {
    unordered_map<string, GiftInfo> info;
    int maxGifts = 0;
    
    for (int i=0; i<friends.size(); ++i)
    {
        unordered_map<string, int>& sendList = info[friends[i]].sendList;
        for (int j=0; j<friends.size(); ++j)
        {
            if (i == j) continue;
            sendList[friends[j]];
        }
    }
    
    for (int i=0; i<gifts.size(); ++i)
    {
        stringstream ss(gifts[i]);
        string sender, receiver;
        
        getline(ss, sender, ' ');
        getline(ss, receiver, ' ');
        GiftInfo& senderInfo = info[sender];
        ++senderInfo.sendList[receiver];
        ++senderInfo.sendCount;
        ++info[receiver].recvCount;
    }
    
    for (auto target=info.begin(); target!=info.end(); ++target)
    {
        int recvGifts = 0;
        
        for (auto fri=info.begin(); fri!=info.end(); ++fri)
        {
            if (target == fri
                || target->second.sendList[fri->first] < fri->second.sendList[target->first]) 
                continue;
            
            if ((target->second.sendList[fri->first] > fri->second.sendList[target->first])
               || (target->second.sendCount - target->second.recvCount
                    > fri->second.sendCount - fri->second.recvCount))
                ++recvGifts;
        }
        maxGifts = max(recvGifts, maxGifts);
    }
    return maxGifts;
}
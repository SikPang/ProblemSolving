#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(vector<int> players, int m, int k) {
    deque<int> aliveServer;
    int increaseCount = 0;

    for (int i=0; i<players.size(); ++i){
        int neededServer = players[i] / m;
        if (neededServer > aliveServer.size()){
            int gap = neededServer - aliveServer.size();
            for (int i=0; i<gap; ++i){
                aliveServer.push_back(k);
            }
            increaseCount += gap;
        }

        for (int i=0; i<aliveServer.size(); ++i){
            --aliveServer[i];
        }
        while (!aliveServer.empty() && aliveServer.front() == 0){
            aliveServer.pop_front();
        }
    }

    return increaseCount;
}
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> indexMap;
    
    for (int i=0; i<players.size(); ++i)
        indexMap.insert(make_pair(players[i], i));
    
    for (int i=0; i<callings.size(); ++i)
    {
        int index = indexMap[callings[i]];
        
        --(indexMap[players[index]]);
        ++(indexMap[players[index - 1]]);
        swap(players[index], players[index - 1]);
    }
    
    return players;
}
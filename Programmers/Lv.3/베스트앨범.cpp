#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Info
{
    vector<pair<int, int>> songs;
    int total;
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string, Info> infos;
    
    for (int i=0; i<genres.size(); ++i)
    {
        Info& curInfo = infos[genres[i]];
        curInfo.songs.push_back(make_pair(i, plays[i]));
        curInfo.total += plays[i];
    }
    
    vector<pair<string, Info>> sortedInfos(infos.begin(), infos.end());
    sort(sortedInfos.begin(), sortedInfos.end(), [](pair<string, Info>& a, pair<string, Info>& b){
        return a.second.total > b.second.total;
    });
    
    vector<int> answer;
    for (int i=0; i<sortedInfos.size(); ++i)
    {
        vector<pair<int, int>>& songs = sortedInfos[i].second.songs;
        sort(songs.begin(), songs.end(), [](pair<int, int>& a, pair<int, int>& b){
            if (a.second == b.second)
                return a.first < b.first;
            return a.second > b.second;
        });

        answer.push_back(songs[0].first);
        if (songs.size() > 1)
            answer.push_back(songs[1].first);
    }
    return answer;
}
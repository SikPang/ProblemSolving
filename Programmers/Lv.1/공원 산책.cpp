#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    pair<int, int> pos;
    
    for (int i=0; i<park.size(); ++i)
        for (int j=0; j<park[i].length(); ++j)
            if (park[i][j] == 'S')
                pos = pair<int, int>{i, j};
    
    const int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    for (int i=0; i<routes.size(); ++i)
    {
        int idx;
        int dest = routes[i][2] - '0';
        
        if (routes[i][0] == 'N')
            idx = 0;
        else if (routes[i][0] == 'E')
            idx = 1;
        else if (routes[i][0] == 'S')
            idx = 2;
        else if (routes[i][0] == 'W')
            idx = 3;
        
        int nextY = pos.first;
        int nextX = pos.second;
        
        while (dest > 0)
        {
            nextY += dir[idx][0];
            nextX += dir[idx][1];
            if (nextY < 0 || nextY >= park.size() ||
               nextX < 0 || nextX >= park[0].length() ||
               park[nextY][nextX] == 'X')
                break;
            --dest;
        }
        if (dest == 0)
            pos = pair<int, int>{nextY, nextX};
    }
    answer.push_back(pos.first);
    answer.push_back(pos.second);
    return answer;
}

#include <vector>
#include <math.h>
#include <algorithm>
#include <climits>

using namespace std;

int getDistance(int x1, int y1, int x2, int y2) {
    return pow(abs(x2-x1), 2) + pow(abs(y2-y1), 2);
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer(balls.size());

    for (int i=0; i<balls.size(); ++i)
    {
        int dist = INT_MAX;
        
        if (startX != balls[i][0] || startY > balls[i][1])  // Up
            dist = getDistance(startX, startY, balls[i][0], n+n-balls[i][1]);
        if (startX != balls[i][0] || startY < balls[i][1])  // Down
            dist = min(dist, getDistance(startX, startY, balls[i][0], -balls[i][1]));
        if (startY != balls[i][1] || startX < balls[i][0])  // Left
            dist = min(dist, getDistance(startX, startY, -balls[i][0], balls[i][1]));
        if (startY != balls[i][1] || startX > balls[i][0])  // Right
            dist = min(dist, getDistance(startX, startY, m+m-balls[i][0], balls[i][1]));
        
        answer[i] = dist;
    }
    return answer;
}
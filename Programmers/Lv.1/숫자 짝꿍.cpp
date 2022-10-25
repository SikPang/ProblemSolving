#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    vector<bool> isUsed(Y.size());
    int hasChar[128] = {};
   
    for (int i = 0; i < Y.size(); ++i)
        ++hasChar[Y[i]];

    for (int i = 0; i < X.size(); ++i)
    {
        if (hasChar[X[i]] > 0)
        {
            --hasChar[X[i]];
            answer += X[i];
        }
    }

    if (answer.size() == 0)
        return "-1";

    sort(answer.begin(), answer.end(), greater<>());
    
    if (answer[0] == '0')
        answer = "0";

    return answer;
}
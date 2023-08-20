#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<vector<int>> queries)
{
    vector<string> answer;

    for (int i = 0; i < queries.size(); ++i)
    {
        if (queries[i][0] == 1 && queries[i][1] == 1)
        {
            answer.push_back("Rr");
            continue;
        }
        int n = 1;
        for (int j = 0; j < queries[i][0] - 1; ++j)
            n *= 4;
        switch ((queries[i][1]-1) / (n / 4))
        {
        case 0:
            answer.push_back("RR");
            break;
        case 3:
            answer.push_back("rr");
            break;
        default:
            switch (queries[i][1] % 4)
            {
            case 1:
                answer.push_back("RR");
                break;
            case 0:
                answer.push_back("rr");
                break;
            default:
                answer.push_back("Rr");
                break;
            }
            break;
        }
    }

    return answer;
}
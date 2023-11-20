#define TRASH_SIZE 3

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        const char trash[TRASH_SIZE] = {'G', 'P', 'M'};
        int answer = 0;

        for (int i=0; i<TRASH_SIZE; ++i)
        {
            int curTime = 0;
            int tempTime = 0;

            for (int j=0; j<garbage.size(); ++j)
            {
                for (int k=0; k<garbage[j].size(); ++k)
                {
                    if (garbage[j][k] == trash[i])
                    {
                        curTime += tempTime;
                        tempTime = 0;
                        ++curTime;
                    }
                }
                if (j < travel.size())
                    tempTime += travel[j];
            }
            answer += curTime;
        }
        return answer;
    }
};
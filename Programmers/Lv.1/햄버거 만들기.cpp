#include <vector>
using namespace std;

int solution(vector<int> ingredient)
{
    int answer = 0;
    int size = ingredient.size();
    int count = 0;

    for (int i = 0; i < size; ++i)
    {
        if (ingredient[count] == 1 && count >= 3 && ingredient[count - 1] == 3 
        && ingredient[count - 2] == 2 && ingredient[count - 3] == 1)
        {
            for (int j=0; j<4; ++j)
                ingredient.erase(ingredient.begin()+count-3);
            ++answer;
            count -= 3;
        }
        ++count;
    }

    return answer;
}
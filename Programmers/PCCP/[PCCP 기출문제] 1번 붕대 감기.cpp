#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int curHealth = health;
    int curTime = 0;
    
    for (int i=0; i<attacks.size(); ++i)
    {
        int gap = attacks[i][0] - curTime - 1;
        int heal = gap * bandage[1];
        
        if (gap >= bandage[0])
            heal += gap / bandage[0] * bandage[2];
        
        curHealth += heal;
        if (curHealth > health)
            curHealth = health;

        curHealth -= attacks[i][1];
        if (curHealth <= 0)
            return -1;
        curTime = attacks[i][0];
    }
    
    return curHealth;
}

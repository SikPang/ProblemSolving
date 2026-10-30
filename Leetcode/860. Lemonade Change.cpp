class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        array<int, 21> billCounts;

        for (int i=0; i<bills.size(); ++i){
            if (bills[i] != 5 && billCounts[5] == 0) return false;

            // change는 15, 5, 0 만 나옴
            int change = bills[i] - 5;
            
            if (change == 15){
                if (billCounts[10] > 0){
                    --billCounts[10];
                    --billCounts[5];
                } else if (billCounts[5] >= 3){
                    billCounts[5] -= 3;
                } else {
                    return false;
                }
            } else {
                --billCounts[change];
            }

            ++billCounts[bills[i]];
        }
        return true;
    }
};
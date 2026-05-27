class Solution {
private:
    void AddFlowerCount(int& maxFlowers, int zeroCount, bool hasFirstPlace, bool hasLastPlace){
        zeroCount += hasFirstPlace ? 1 : 0;
        zeroCount += hasLastPlace ? 1 : 0;
        maxFlowers += (zeroCount - 1) / 2;
    }

public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int zeroCount = 0;
        int maxFlowers = 0;
        bool hasFirstPlace = false;
        bool hasLastPlace = false;

        for (int i=0; i<flowerbed.size(); ++i){
            if (flowerbed[i] == 0){
                ++zeroCount;
                if (i == 0) {
                    hasFirstPlace = true;
                }
                if (i == flowerbed.size()-1){
                    hasLastPlace = true;
                }
            } else {
                AddFlowerCount(maxFlowers, zeroCount, hasFirstPlace, hasLastPlace);

                zeroCount = 0;
                hasFirstPlace = false;
                hasLastPlace = false;
            }
        }
        AddFlowerCount(maxFlowers, zeroCount, hasFirstPlace, hasLastPlace);
        return n <= maxFlowers;
    }
};
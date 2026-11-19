class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int curNameIdx = 0;
        for (int i=0; i<typed.size(); ++i){
            if (curNameIdx == 0 && name[0] != typed[i]) return false;

            if (typed[i] == name[curNameIdx]){
                ++curNameIdx;
            } else if (i > 0 && typed[i] != typed[i-1]){
                return false;
            }
        }
        return curNameIdx == name.size();
    }
};
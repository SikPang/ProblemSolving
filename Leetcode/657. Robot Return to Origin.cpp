class Solution {
public:
    bool judgeCircle(string moves) {
        int uCount = 0;
        int dCount = 0;
        int lCount = 0;
        int rCount = 0;

        for (int i=0; i<moves.size(); ++i){
            switch(moves[i]){
                case 'U':
                    ++uCount;
                    break;
                case 'D':
                    ++dCount;
                    break;
                case 'L':
                    ++lCount;
                    break;
                case 'R':
                    ++rCount;
                    break;
            }
        }

        return uCount - dCount == 0 && lCount - rCount == 0;
    }
};
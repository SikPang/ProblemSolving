/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;

        while (left != right){
            if (right - left == 1){
                if (guess(left) == 0) return left;
                else return right;
            }

            int cur = ((long)right + left) / 2;
            int result = guess(cur);
            if (result == 1){
                left = cur + 1;
            } else if (result == -1){
                right = cur - 1;
            } else{
                return cur;
            }
        }
        return left;
    }
};
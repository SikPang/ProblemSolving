#include <string>
#include <algorithm>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        string backward_str = to_string(x);
        string forward_str(backward_str);
        reverse(forward_str.begin(), forward_str.end());

        return backward_str == forward_str;
    }
};
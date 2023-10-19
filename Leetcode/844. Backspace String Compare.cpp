class Solution {
private:
    void erase(string& str){
        for (int i=0; i<str.length(); ++i)
        {
            if (str[i] == '#' && i == 0)
            {
                str.erase(i, 1);
                i -= 1;
            }
            else if (str[i] == '#' && i > 0)
            {
                str.erase(i-1, 2);
                i -= 2;
            }
        }
    }

public:
    bool backspaceCompare(string s, string t) {
        erase(s);
        erase(t);
        
        if (s == t)
            return true;
        return false;
    }
};
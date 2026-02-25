class Solution {
public:
    int findLUSlength(string a, string b) {
        int aMaxLength = -1;
        for (int start=0; start<a.size(); ++start){
            for (int size=a.size(); size>=1; --size){
                string str = a.substr(start, size);
                if (b.find(str) == std::string::npos) {
                    aMaxLength = max(size, aMaxLength);
                    break;
                }
            }
            if (aMaxLength > -1) break;
        }

        for (int start=0; start<b.size(); ++start){
            for (int size=b.size(); size>=1; --size){
                string str = b.substr(start, size);
                if (a.find(str) == std::string::npos) {
                    return max(size, aMaxLength);
                }
            }
        }
        return aMaxLength;
    }
};
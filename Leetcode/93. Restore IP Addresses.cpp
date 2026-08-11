class Solution {
private:
    void restoreIpRecur(vector<string>& ret, string& s, vector<string>& buffer, int idx, int depth){
        if (depth == 4){
            if (idx == s.size()){
                ret.push_back(buffer[0] + "." + buffer[1] + "." + buffer[2] + "." + buffer[3]);
            }
            return;
        }

        for (int len=1; len<=3; ++len){
            string valid = GetValidString(s, idx, len);
            if (valid.size() != len) return;

            buffer[depth] = valid;
            restoreIpRecur(ret, s, buffer, idx+len, depth+1);
        }
    }

    string GetValidString(string& s, int start, int length){
        string str;
        int val = 0;

        if (s[start] == '0' && length > 1) return str;

        for (int i=start; i<s.size(); ++i){
            if (!isdigit(s[i])) throw false;
            if (length == str.size()) break;

            if (str.empty()) {
                str.push_back(s[i]);
                val = s[i] - '0';
            } else {
                int temp = val * 10 + s[i] - '0';
                if (temp > 255) break;

                str.push_back(s[i]);
                val = temp;
            }
        }
        return str;
    }

public:
    vector<string> restoreIpAddresses(string s) {
        if (s.size() > 12) return vector<string>();

        vector<string> ret;
        vector<string> buffer(4);

        try{
            restoreIpRecur(ret, s, buffer, 0, 0);
        } catch(bool){
            return vector<string>();
        }
        return ret;
    }
};
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> ans;

        for (int i=0; i<emails.size(); ++i){
            string str;
            bool isBeforeAt = true;
            bool triggeredPlus = false;

            for (int j=0; j<emails[i].size(); ++j){
                char cur = emails[i][j];
                if (isBeforeAt){
                    switch(cur){
                        case '@':
                            isBeforeAt = false;
                            str += cur;
                            break;
                        case '.':
                            break;
                        case '+':
                            triggeredPlus = true;
                            break;
                        default:
                            if (!triggeredPlus){
                                str += cur;
                            }
                            break;
                    }
                } else {
                    str += cur;
                }
            }
            ans.insert(str);
        }
        return ans.size();
    }
};
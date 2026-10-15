class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> answer;
        answer.push_back(words[0]);

        string lStr = words[0];
        sort(lStr.begin(), lStr.end());

        for (int right=1; right<words.size(); ++right){
            string rStr = words[right];
            sort(rStr.begin(), rStr.end());

            if (lStr != rStr){
                answer.push_back(words[right]);
                lStr = rStr;
            }
        }
        return answer;
    }
};
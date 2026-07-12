class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> dup;
        for (int i=0; i<arr.size(); ++i){
            dup.insert(arr[i]);
        }

        unordered_map<int, int> priorities;
        int i = 1;
        for (set<int>::iterator iter = dup.begin(); iter != dup.end(); ++iter, ++i){
            priorities.insert(make_pair(*iter, i));
        }

        vector<int> ret(arr.size());
        for (int i=0; i<arr.size(); ++i){
            ret[i] = priorities[arr[i]];
        }

        return ret;
    }
};
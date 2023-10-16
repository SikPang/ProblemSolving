class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> buf(rowIndex+1, 1);
        
        for (int i=2; i<=rowIndex; ++i)
            for (int j=i-1; j>0; --j)
                buf[j] += buf[j-1];
        return buf;
    }
};
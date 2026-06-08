class Solution {
private:
    void Sum(vector<vector<int>>& img, vector<vector<int>>& ret, int y, int x){
        long sum = 0;
        long count = 0;

        for (int i=-1; i<=1; ++i){
            for (int j=-1; j<=1; ++j){
                if (y + i < 0 || y + i >= ret.size()) continue;
                if (x + j < 0 || x + j >= ret[0].size()) continue;

                sum += img[y + i][x + j];
                ++count;
            }
        }
        ret[y][x] = sum / count;
    }

public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> ret(img.size(), vector<int>(img[0].size()));

        for (int i=0; i<ret.size(); ++i){
            for (int j=0; j<ret[0].size(); ++j){
                Sum(img, ret, i, j);
            }
        }
        return ret;
    }
};
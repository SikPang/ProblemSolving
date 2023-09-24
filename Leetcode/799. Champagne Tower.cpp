class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector< vector<double> > glasses(query_row + 2);
        for (int i=0; i<query_row + 2; ++i)
            glasses[i].resize(query_row + 2);
        
        glasses[0][0] = poured;
        for (int i=0; i<query_row + 1; ++i)
        {
            for (int j=0; j<i+1; ++j)
            {
                if (glasses[i][j] > 1)
                {
                    double remain = glasses[i][j] - 1;
                    glasses[i][j] = 1;
                    glasses[i+1][j] += remain / 2;
                    glasses[i+1][j+1] += remain / 2;
                }
            }
        }
        return glasses[query_row][query_glass];
    }
};
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int maxArea = 0;

        for (int i=0; i<points.size(); ++i){
            for (int j=i+1; j<points.size(); ++j){
                    for (int k=j+1; k<points.size(); ++k){
                        // |x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)| / 2
                        int area = abs(points[i][0] * (points[j][1] - points[k][1])
                        + points[j][0] * (points[k][1] - points[i][1])
                        + points[k][0] * (points[i][1] - points[j][1]));
                        maxArea = max(area, maxArea);
                    }
            }
        }
        return maxArea / 2.0;
    }
};
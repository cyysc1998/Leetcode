class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int num_points = points.size();
        std::sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        int count = 0, last = points[0][1];
        for (int i = 1; i < num_points; i ++) {
            if (points[i][0] <= last)
                count ++;
            else
                last = points[i][1];
        }
        return num_points - count;
    }
};

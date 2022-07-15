class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int num_intervals = intervals.size();
        int count = 0;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        int last = intervals[0][1];
        for (int i = 1; i < num_intervals; i ++) {
            if (intervals[i][0] < last)
                count ++;
            else
                last = intervals[i][1];
        }
        return count;
    }
};

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> left_max(n);
        vector<int> right_min(n);
        left_max[0] = nums[0];
        right_min[n - 1] = nums[n - 1];
        for (int i = 1; i < nums.size(); i ++)
            left_max[i] = max(left_max[i - 1], nums[i]);
        for (int i = n - 2; i >= 0; i --)
            right_min[i] = min(right_min[i + 1], nums[i]);

        int ans = -1;
        for (int i = 0; i < nums.size() - 1; i ++) {
            if (left_max[i] <= right_min[i + 1]) {
                ans = i + 1;
                break;
            }
        }
        return ans;
    }
};

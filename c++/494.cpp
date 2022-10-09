class Solution {
public:
    int ans = 0;
    int findTargetSumWays(vector<int>& nums, int target) {
        dfs(nums, 0, 0, target);
        return ans;
    }

    void dfs(vector<int>& num, int cur_id, int cur_sum, int target) {
        if (cur_id == num.size()) {
            if (cur_sum == target) 
                ans ++;
            return;
        } 
        dfs(num, cur_id + 1, cur_sum - num[cur_id], target);
        dfs(num, cur_id + 1, cur_sum + num[cur_id], target);
    }
};

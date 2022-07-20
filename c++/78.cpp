class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subsets;
        dfs(nums, 0, subsets);
        return ans;
    }
    void dfs(vector<int>& nums, int cur_idx, vector<int>& subsets) {
        ans.push_back(subsets);
        for (int i = cur_idx; i < nums.size(); i ++) {
            subsets.push_back(nums[i]);
            dfs(nums, i + 1, subsets);
            subsets.pop_back();
        }
    }
};

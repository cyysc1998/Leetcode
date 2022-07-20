class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> selected;
        dfs(candidates, selected, 0, 0, target);
        return ans;
    }

    void dfs(vector<int>& candidates, vector<int>& selected, int cur_idx, int sum, int target) {
        if (sum > target) return;
        if (sum == target) {
            ans.push_back(selected);
            return;
        }
        for (int i = cur_idx; i < candidates.size(); i ++) {
            selected.push_back(candidates[i]);
            sum += candidates[i];
            dfs(candidates, selected, i, sum, target);
            selected.pop_back();
            sum -= candidates[i];
        }
    }
};

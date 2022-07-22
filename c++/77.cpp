class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        dfs(n, k, cur, 0);
        return ans;
    }
    void dfs(int n, int k, vector<int>& cur, int cur_id) {
        if (cur_id > n) return;
        if (cur.size() == k) {
            ans.push_back(cur);
            return;
        }
        cur_id ++;
        cur.push_back(cur_id);
        dfs(n, k, cur, cur_id);
        cur.pop_back();
        dfs(n, k, cur, cur_id);
    }
};

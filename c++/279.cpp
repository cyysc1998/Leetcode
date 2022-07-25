/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
public:
    int ans;
    int numSquares(int n) {
        int N = sqrt(float(n));
        ans = n;
        dfs(n, N, 0, 0);
        return ans;
    }

    void dfs(int n, int cur_num, int sum, int step) {
        if (sum == n) ans = min(ans, step);
        if (sum > n || step >= ans) return;
        for (int i = cur_num; i >= 1; i --) {
            dfs(n, i, sum + i * i, step + 1);
        }
    }
};
// @lc code=end


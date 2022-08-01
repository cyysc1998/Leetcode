class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> st(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i ++) st[i][1] = st[i-1][1] + grid[i-1][0];
        for (int j = 1; j <= n; j ++) st[1][j] = st[1][j-1] + grid[0][j-1];
        for (int i = 2; i <= m; i ++) {
            for (int j = 2; j <= n; j ++)
                st[i][j] = min(st[i][j-1], st[i-1][j]) + grid[i-1][j-1];
        }
        return st[m][n];
    }
};

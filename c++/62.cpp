class Solution {
public:
    int uniquePaths(int m, int n) {
        long MOD = 2e9;
        int s = m + n - 2, t = m - 1;
        vector<vector<long> > tb(s + 1, vector<long>(t + 1, 1));
        for (int i = 1; i <= t; i ++) {
            for (int j = 1; j <= s; j ++) {
                if (i == j) tb[j][i] = 1;
                else tb[j][i] = (tb[j - 1][i - 1]  + tb[j - 1][i]) % MOD;
            }
        }
        return tb[s][t];
    }
};

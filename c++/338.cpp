class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> num_ones(n + 1, -1);
        num_ones[0] = 0;
        for (int i = 1; i <= n; i ++) {
            if (i % 2 == 0) num_ones[i] = num_ones[i / 2];
            else num_ones[i] = num_ones[i - 1] + 1;
        }
        return num_ones;
    }
};

class Solution {
public:

    int numTrees(int n) {
        vector<int> st(20, -1);
        int ans = num_tree(n, st);
        return ans;
    }

    int num_tree(int n, vector<int>& st) {
        if (st[n] != -1) return st[n];
        if (n == 0 || n == 1) return 1;
        int sum = 0;
        for (int i = 0; i < n; i ++) {
            int num_left = num_tree(i, st);
            int num_right = num_tree(n - i - 1, st);
            st[i] = num_left;
            st[n - i - 1] = num_right;
            sum += num_left * num_right;
        }
        return sum;
    }
};

class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        string s = "";
        dfs(s, n, n);
        return ans;
    }

    void dfs(string s, int num_left, int num_right) {
        if (num_left == 0 && num_right == 0) {
            ans.push_back(s);
            return;
        }
        if (num_left > num_right)
            return;
        if (num_left > 0) dfs(s + '(', num_left - 1, num_right);
        if (num_right > 0) dfs(s + ')', num_left, num_right - 1);
    }
};

class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i ++) {
            for (int j = 0; j <= 1; j ++) {
                int l = i, r = i + j;
                while (l >= 0 && r < s.length() && s[l] == s[r]) {
                    l --;
                    r ++;
                    ans ++;
                }
            }
        }
        return ans;
    }
};

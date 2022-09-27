class Solution {
public:
   
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (s.length() < p.length()) return ans;
        vector<int> s_count(26), p_count(26);
        for (int i = 0; i < p.length(); i ++) {
            s_count[s[i] - 'a'] ++;
            p_count[p[i] - 'a'] ++;
        }
        int pl = p.length();
        for (int i = 0; i < s.length() - p.length() + 1; i ++) {
            if (i != 0) {
                s_count[s[i + pl - 1] - 'a'] ++;
                s_count[s[i - 1] - 'a'] --;
            }
            if (s_count == p_count)
                ans.push_back(i);
        }
        return ans;
    }
};

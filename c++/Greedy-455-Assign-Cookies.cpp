class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count = 0;
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        
        for (int i = 0, j = 0; i < g.size() && j < s.size();) {
            if (s[j] >= g[i]) {
                i ++;
                j ++;
                count ++;
            }
            else
                j ++;
        }
        return count;
    }
};
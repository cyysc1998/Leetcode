class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> str_map;
        for (auto& str: strs) {
            string t = str;
            std::sort(t.begin(), t.end());
            str_map[t].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto p: str_map) {
            vector<string> cur_anagrams;
            for (auto& s: p.second)
                cur_anagrams.push_back(s);
            ans.push_back(cur_anagrams);
        }
        return ans;
    }
};

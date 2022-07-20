class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> st(s.length(), false);
        unordered_set<string> setDict;
        for (auto& word: wordDict)
            setDict.insert(word);
        st[0] = setDict.count(s.substr(0, 1)) != 0;
        for (int i = 1; i < s.length(); i ++) {
            for (int j = 0; j <= i; j ++) {
                string middlestr = s.substr(j, i - j + 1);
                if ((j == 0 || st[j - 1]) && setDict.count(middlestr) != 0) {
                    st[i] = true;
                    break;
                }
            }
        }
        return st[st.size() - 1];
    }
};

class Solution {
public:
    vector<string> ans;
    unordered_map<char, vector<char>> int2char;
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return {};
        // int2char['2'] = {'a', 'b', 'c'};
        // int2char['3'] = {'d', 'e', 'f'};
        // int2char['4'] = {'g', 'h', 'i'};
        // int2char['5'] = {'j', 'k', 'l'};
        // int2char['6'] = {'m', 'n', 'o'};
        // int2char['7'] = {'p', 'q', 'r', 's'};
        // int2char['8'] = {'t', 'u', 'v'};
        // int2char['9'] = {'w', 'x', 'y', 'z'};
        int i = 0, j = 2, t = 0;
        while (i < 26) {
            int2char['0' + j].push_back('a' + i);
            i ++;
            t ++;
            if (t == 3 && j != 7 && j != 9 || t == 4) {
                j ++;
                t = 0;
            }

        }
        dfs(digits, "", 0);
        return ans;
    }

    

    void dfs(string digits, string cur, int idx) {
        if (idx == digits.size()) {
            ans.push_back(cur);
            return;
        }
        for (auto c: int2char[digits[idx]]) {
            dfs(digits, cur + c, idx + 1);
        }
    }
};

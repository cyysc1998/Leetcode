/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        for (int i = 0; i < path.length(); i ++) {
            if (path[i] == '/')
                path[i] = ' ';
        }
        std::stringstream ss(path);
        std::vector<string> nodes;
        string node;
        while (ss >> node) {
            if (node == ".")
                continue;
            else if (node == ".." && nodes.size() > 0)
                    nodes.pop_back();
            else if (node != "..")
                nodes.push_back(node);
        }
        string ans;
        for (auto s: nodes)
            ans +=( "/" + s);
        if (ans == "") ans += "/";
        return ans;
    }
};
// @lc code=end

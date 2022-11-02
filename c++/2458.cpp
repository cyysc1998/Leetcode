/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    vector<int> nodes;
    unordered_map<int, int> depths;
    unordered_map<int, int> left_map;
    unordered_map<int, int> right_map;
    unordered_map<int, bool> is_match;
    void dfs(TreeNode* root, int depth) {
        if (root == nullptr) return;
        depths[root->val] = depth;
        nodes.push_back(root->val);
        if (root->left != nullptr) dfs(root->left, depth + 1);
        if (root->right != nullptr) dfs(root->right, depth + 1);
        nodes.push_back(root->val);
    }


    
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        dfs(root, 0);
        vector<int> left_max(2e5, 0);
        vector<int> right_max(2e5, 0);
        

        int n = nodes.size();
        left_max[0] = depths[nodes[0]];
        right_max[n - 1] = depths[nodes[n - 1]];
        for (int i = 1; i < nodes.size(); i ++) {
            left_max[i] = max(left_max[i - 1], depths[nodes[i]]);
        }
        for (int j = n - 2; j > 0; j --) {
            right_max[j] = max(right_max[j + 1], depths[nodes[j]]);
        }

        for (int i = 0; i < n; i ++) {
            if (is_match[nodes[i]]) right_map[nodes[i]] = i;
            else {
                left_map[nodes[i]] = i;
                is_match[nodes[i]] = true;
            }
        }

        vector<int> ans;
        for (auto query: queries) {
            int i = left_map[query];
            int j = right_map[query];
            ans.push_back(max(left_max[i - 1], right_max[j + 1]));
        }

        return ans;
    }
};

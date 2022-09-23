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
    void dfs(TreeNode* r, int& cur_sum) {
        if (r->right != nullptr) dfs(r->right, cur_sum);
        cur_sum += r->val;
        r->val = cur_sum;
        if (r->left != nullptr) dfs(r->left, cur_sum);
    }

    TreeNode* convertBST(TreeNode* root) {
        if (root == nullptr) return root;
        int sum = 0;
        dfs(root, sum);
        return root;
    }
};

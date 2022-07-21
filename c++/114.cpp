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
    void flatten(TreeNode* root) {
        flatten_subtree(root);
    }

    TreeNode* flatten_subtree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        if (root->right == nullptr && root->left == nullptr) return root;
        
        TreeNode* l_last_node = flatten_subtree(root->left);
        TreeNode* r_last_node = flatten_subtree(root->right);
        if (l_last_node != nullptr) {
            l_last_node->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        return r_last_node == nullptr ? l_last_node : r_last_node;
    }
};

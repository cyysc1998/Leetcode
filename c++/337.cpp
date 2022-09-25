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
    unordered_map<TreeNode*, int> p;
    int rob(TreeNode* root) {
        return maxSubTree(root);
    }

    int get(TreeNode* t) {
        if (p[t] == 0) p[t] = maxSubTree(t);
        return p[t];
    } 

    int maxSubTree(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) return root->val;
          
        int nonthief = get(root->left) + get(root->right);
        int thiefLeft = 0, thiefRight = 0;
        if (root->left != nullptr) thiefLeft = get(root->left->left) + get(root->left->right);
        if (root->right != nullptr) thiefRight = get(root->right->left) + get(root->right->right);
        int thief = root->val + thiefLeft + thiefRight;
        int ans = max(nonthief, thief);
        return ans;
    }
};

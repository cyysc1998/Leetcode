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
    unordered_map<int, int> indices;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i ++) indices[inorder[i]] = i;
        TreeNode* postorder = post_travel(preorder, inorder, 0, n - 1, 0, n - 1);
        return postorder;
    }

    TreeNode* post_travel(vector<int>& preorder, vector<int> inorder, int pl, int pr, int il, int ir) {
        TreeNode* root = new TreeNode(preorder[pl]);
        int iid = indices[root->val];
        if (il < iid) root->left = post_travel(preorder, inorder, pl + 1, pl + 1 + (iid - 1 - il), il, iid - 1);
        if (iid < ir) root->right = post_travel(preorder, inorder, pl + 1 + (iid - 1 - il) + 1, pr, iid + 1, ir);
        return root;
    }
};

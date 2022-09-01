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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        std::queue<TreeNode*> h; 
        if (root == nullptr) return ans;
        h.push(root);
        int num_cur_level = 1;
        vector<int> cur_level;
        while (!h.empty()) {
            TreeNode* head = h.front();
            h.pop();
            if (head->left != nullptr) h.push(head->left);
            if (head->right != nullptr) h.push(head->right);
            cur_level.push_back(head->val);
            num_cur_level --;
            
            if (num_cur_level == 0) {
                ans.push_back(cur_level);
                cur_level.clear();
                num_cur_level = h.size();
            }
        }
        return ans;
    }
};

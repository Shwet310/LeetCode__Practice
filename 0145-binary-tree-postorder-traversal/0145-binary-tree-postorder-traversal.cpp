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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> sol;
        postorder(root, sol);
        return sol;
    }
private:
    void postorder(TreeNode* root, vector<int>& sol) {
        if (!root)
            return;
        postorder(root->left, sol);
        postorder(root->right, sol);
        sol.push_back(root->val); 
    }
};
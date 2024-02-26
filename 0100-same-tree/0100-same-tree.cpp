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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)    return true;   // if both nodes are null, return true
        if(!p || !q)    return false;  // if one node is null either in p or q, return false
        
        //check if values of p and q are the same, then recursively check left and right subtrees
        return p->val==q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
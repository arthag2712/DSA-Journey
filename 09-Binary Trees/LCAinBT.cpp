/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/
// Recursive idea:
// Every call returns:
// 1. nullptr -> neither p nor q found in this subtree.
// 2. p/q     -> exactly one target found.
// 3. LCA     -> both targets found, answer already determined.
//
// Parent combines the left and right results.

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //your code goes here
        if(!root) return nullptr;
        if(root==p || root==q) return root;
        auto l = lowestCommonAncestor(root->left,p,q);
        auto r = lowestCommonAncestor(root->right,p,q);
        if(l && r) return root;
        if(!l) return r;
        if(!r) return l;
        return nullptr;
    }
};
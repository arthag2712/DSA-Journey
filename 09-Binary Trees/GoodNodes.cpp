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

// DFS (Top-down)
//
// maxSoFar = maximum value seen from the root to the parent.
//
// If current node >= maxSoFar, it is a good node.
// Update the maximum and pass it to the children.

class Solution {
public:
    void chkGoodNode(TreeNode* node, int maxSoFar, int& ans){
        if(!node) return;
        if(node->val >= maxSoFar) ans++;
        maxSoFar = max(maxSoFar,node->val);
        chkGoodNode(node->left,maxSoFar, ans);
        chkGoodNode(node->right,maxSoFar, ans);
    }

    int goodNodes(TreeNode* root) {
        int ans = 0;
        chkGoodNode(root,-200,ans);
        return ans;
    }
};

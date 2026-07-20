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
    void inorder(TreeNode* root, int& cnt, int& ans, int k){
        //left->access->right results in sorted as it is bst
        if(!root) return;
        inorder(root->left, cnt, ans, k);
        cnt++;
        if(cnt == k){
            ans = root->val;
            return;
        }
        inorder(root->right, cnt, ans, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        int cnt=0,ans=0;
        inorder(root,cnt,ans,k);
        return ans;
    }
};

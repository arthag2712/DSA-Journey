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

/*
IDEA IS TO ASSIGN A RANGE TO EVERY NODE, IF THE NODE LIES IN THAT RANGE, ITS VALID, THEN CONTINUE
*/
class Solution {
public:
    bool validate(TreeNode* root, long long mini, long long maxi){
        if(!root) return true;
        if(root->val <= mini || root->val >= maxi) return false;
        return validate(root->left,mini,root->val) && validate(root->right,root->val,maxi);
        //on going left, cap the max value and for the right, cap the min value
    }
    bool isValidBST(TreeNode* root) {
        return validate(root,LLONG_MIN,LLONG_MAX);
    }
};
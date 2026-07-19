/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
    /*
    Here we modify the height code such that if at any point the difference of lh & rh is greater than 1
    we return -1, else keep computing hght
    */
public:
    int hght(TreeNode* root){
        if(!root) return 0;
        int lh = hght(root->left);
        if(lh == -1) return -1;
        int rh = hght(root->right);
        if(rh == -1) return -1;
        if(abs(lh-rh)>1) return -1;
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode *root){
    	//your code goes here
        return hght(root) != -1;
    }
};
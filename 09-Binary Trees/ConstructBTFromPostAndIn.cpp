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
    int search(vector<int>& inorder, int left, int right, int target){
        for(int i=left;i<=right;i++){
            if(inorder[i]==target)
                return i;
        }
        return -1;
    }

    TreeNode* helper(vector<int>& postorder, vector<int>& inorder, int& postIdx, int left, int right) {
        if(left > right) return nullptr; //build null nodes
        TreeNode* root = new TreeNode(postorder[postIdx]); //current root that we are currently working with
        int inIdx = search(inorder,left,right,postorder[postIdx]); //search for root in inorder
        postIdx--;
        //build right subtree first here unlike PreAndIn
        root->right = helper(postorder,inorder,postIdx,inIdx+1,right); 
        //build left subtree
        root->left = helper(postorder,inorder,postIdx,left,inIdx-1); 
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIdx = inorder.size()-1;
        return helper(postorder, inorder, postIdx, 0, inorder.size()-1);
    }
};

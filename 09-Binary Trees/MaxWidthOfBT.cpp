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
POINTS TO KEEP IN MIND HERE:
usage of unsigned LL
USED CBT BASED INDEXING HERE FROM 0, WHICH SAYS LEFT NODE INDEX IS 2*i+1 AND RIGHT NODE INDEX IS 2*i+2 where i is the root index;
*/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root,0});
        int maxWid=0;
        while(!q.empty()){
            int sz = q.size();
            int st = q.front().second;
            int end = q.back().second;
            maxWid = max(maxWid, end-st+1);
            for(int i=0;i<sz;i++){
                auto node = q.front();
                q.pop();
                if((node.first)->left) q.push({(node.first)->left,2*(node.second)+1});
                if((node.first)->right) q.push({(node.first)->right,2*(node.second)+2});
            }
        }
        return maxWid;
    }
};
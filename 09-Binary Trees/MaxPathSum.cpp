class Solution {
public:
    int maxSum = INT_MIN;   // Stores the maximum path sum found anywhere in the tree.

    // Returns the maximum path sum that starts at 'root'
    // and can be extended upward to its parent.
    int dfs(TreeNode* root) {
        // Empty subtree contributes 0.
        if (!root) return 0;

        // Maximum extendable gain from left and right subtrees.
        int leftGain = dfs(root->left);
        int rightGain = dfs(root->right);

        // Gain to send to the parent.
        // We can choose only ONE child since a path cannot branch upward.
        // Ignore negative gains because they only decrease the path sum.
        int sendUp = root->val + max(0, max(leftGain, rightGain));

        // Best path whose highest node is the current node.
        // Here we are allowed to use BOTH children because
        // the path terminates at this node.
        int currentPath = max(0, leftGain) + root->val + max(0, rightGain);

        // Update the global maximum path sum.
        maxSum = max(maxSum, currentPath);

        // Return the best extendable path to the parent.
        return sendUp;
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};
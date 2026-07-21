    /**
    * Definition for a binary tree node.
    * struct TreeNode {
    *     int val;
    *     TreeNode *left;
    *     TreeNode *right;
    *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    * };
    */
 
    //IDEA IS TO STORE THE PRE-ORDER TRAVERSAL WITH NULL NODES AS WELL
    //BECAUSE PRE/POST TRAVERSAL WITH NULL NODES INCL ARE SUFFICIENT TO CONSTRUCT TREE
    class Codec {
    public:
        string s="";
        // Encodes a tree to a single string.
        void dfs(TreeNode* root){
            //USE DELIMITER #
            if(!root){
                s+="N#";
                return;
            }
            s+=to_string(root->val)+"#";
            dfs(root->left);
            dfs(root->right);
        }
        string serialize(TreeNode* root) {
            dfs(root);
            return s;
        }

        // Decodes your encoded data to tree.
        TreeNode* build(string& data, int& idx){
            string temp = "";
            while(data[idx] != '#'){
                temp+=data[idx];
                idx++;
            } //READS STRING UNTIL # IS ENCOUNTERED
            idx++; //skips #
            if(temp == "N"){
                return nullptr;
            }
            TreeNode* root = new TreeNode(stoi(temp));
            root->left = build(data,idx);
            root->right = build(data,idx);
            return root;
        }

        TreeNode* deserialize(string data) {
            int idx = 0;
            return build(data,idx);
        }
    };

    // Your Codec object will be instantiated and called as such:
    // Codec ser, deser;
    // TreeNode* ans = deser.deserialize(ser.serialize(root));
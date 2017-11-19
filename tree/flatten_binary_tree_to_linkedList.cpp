class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        stack<TreeNode *> sta;
        sta.push(root);
        
        while(!sta.empty()){
            root = sta.top(); sta.pop();
            if(root->right) sta.push(root->right);
            if(root->left) sta.push(root->left);
            
            if(!sta.empty()) { root->right = sta.top(); root->left = NULL;}
            else break;
        }
        
    }
};
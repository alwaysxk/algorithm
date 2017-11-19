class Solution {
public:
    bool isBalanced(TreeNode* root) {
      	if(!root)
            return true;
        int m = getDepth(root->left);
        int n = getDepth(root->right);
        
        
        return abs(m - n)<=1 && isBalanced(root->left) && isBalanced(root->right);
    }
    
    int getDepth(TreeNode* root){
		if(!root)
            return 0;
        int m = getDepth(root->left);
        int n = getDepth(root->right);
        return m>n ? m+1 : n+1;
    }
};
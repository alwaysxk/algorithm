/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > res;
        if(root == NULL) return res;
        vector<int> tmp;
        t(root,res, sum, tmp);
        return res;
        
    }
    
    void t(TreeNode *root, vector<vector<int>> &res,int sum, vector<int> tmp){
        if(root == NULL) return;
        tmp.push_back(root->val);
        if(root->left == NULL && root->right == NULL && root->val == sum){res.push_back(tmp);return;}
        else if(root->left == NULL && root->right == NULL && root->val != sum){return;}
        t(root->left, res, sum-root->val, tmp);
        t(root->right, res, sum-root->val, tmp);
    }
};
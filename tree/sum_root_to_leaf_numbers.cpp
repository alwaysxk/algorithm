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
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        return t(root, "");
    }
    
    int t(TreeNode *root, string s){
        if(!root) return 0;
        s += (char)(root->val + '0');
        if(!root->left && !root->right) return stringToInt(s);
        return t(root->left, s) + t(root->right, s);
    }
    
    int stringToInt(string s){
        int sum = 0;
        for(int i = 0; i<s.size(); i++) sum = sum * 10 + (s[i] - '0');
        return sum;
    }
};
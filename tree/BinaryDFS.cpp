
 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 


void DepthFirstTravel(TreeNode *root){
	stack<TreeNode *> nodeStack;
	nodeStack.push_back(root);

	while(!nodeStack.empty()){
		TreeNode *rootTemp = nodeStack.top();
		//printf("%d"\n", rootTemp->val);
		printf("%d ", rootTemp->val);
		nodeStack.pop();

		if(rootTemp->right){
			nodeStack.push_back(rootTemp->right);
		}
		if(rootTemp->left){
			nodeStack.push_back(rootTemp->left);
		}
	} 

}
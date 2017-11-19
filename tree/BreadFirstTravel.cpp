  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 

 void BreadthFirstTravel(TreeNode *root){

 	queue<TreeNode *> nodeQueue;
 	nodeQueue.push(root);

 	while(!nodeQueue.empty()){
 		TreeNode *tempNode = nodeQueue.front();
 		cout << tempNode->val;
 		nodeQueue->pop();

 		if(tempNode->left){
 			nodeQueue->push(tempNode->left);
 		}
 		if(tempNode->right){
 			nodeQueue->push(tempNode->right);
 		}
 	}

 }
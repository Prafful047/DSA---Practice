 int sumHelper(TreeNode* root , TreeNode* parent){

        if(root==NULL){
            return 0;
        }

        if(root->left==NULL && root->right==NULL){
            if(parent != NULL && root== parent->left){
                return root->val;
            }
        }

        int leftSum = sumHelper(root->left , root);
        int rightSum = sumHelper(root->right , root);

        
        return leftSum + rightSum;
        
    }

    int sumOfLeftLeaves(TreeNode* root) {

        return sumHelper(root , NULL);

    }
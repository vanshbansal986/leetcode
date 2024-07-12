#include "binaryTreeMain.h"
#include<vector>
#include<stack>

bool hasPath(TreeNode *root1 , TreeNode *root2){
    if(root1->data == root2->data){
        return true;
    }
    if(root1 == NULL){
        return false;
    }

    return hasPath(root1->left , root2) || hasPath(root1->right , root2);

}

void helper(TreeNode *root , TreeNode* p, TreeNode* q , TreeNode *ans){
    if(root == NULL){
        return;
    }
    
    if(hasPath(root,p) && hasPath(root,q)){
        ans = root;
        
        helper(root->left , p , q, ans);
        helper(root->right , p , q, ans);
    }
    else{
        helper(root->left , p , q, ans);
        helper(root->right , p , q, ans);
    }
}



TreeNode* lowestCommonAncestor(TreeNode *root , TreeNode* p, TreeNode* q){
    TreeNode *ans;
    helper(root,p,q,ans);

    return ans;
    
}

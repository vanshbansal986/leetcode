#include "binaryTreeMain.h"
#include<vector>
#include<stack>

bool symmetric(TreeNode *root1 , TreeNode *root2){
    if(root1 != NULL && root2 != NULL){
        if(root1->data == root2->data){
            return symmetric(root1->left,root2->right) && symmetric(root1->right,root2->left);
        }
        else{
            return false;
        }
    }

    else if(root1 == NULL && root2 == NULL){
        return true;
    }
    else{
        return false;
    }
}

bool helper(TreeNode *root){
    if(root == NULL){
        return true;
    }

    return symmetric(root->left , root->right);
    
}

bool max_height(TreeNode *root){
    return helper(root);
    
}

#include "binaryTreeMain.h"
#include<vector>
#include<stack>

int depth(TreeNode *root){
    if(root == NULL){
        return 0;
    }

    int left_height = depth(root->left);
    int right_height = depth(root->right);

    int max_height = 1 + max(left_height,right_height);

    return max_height;
}

bool identical_trees(TreeNode *root1 , TreeNode *root2){

    if(root1 == NULL && root2 == NULL){
        return true;
    }

    if((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL)){
        return false;
    }

    if(root1->data != root2->data){
        return false;
    }

    
    return identical_trees(root1->left,root2->left) && identical_trees(root1->right,root2->right);

    
    

}

int max_height(TreeNode *root){
    return depth(root);
    
}

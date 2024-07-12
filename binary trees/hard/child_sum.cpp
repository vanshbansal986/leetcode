#include "binaryTreeMain.h"
#include<vector>
#include<stack>

bool helper(TreeNode *root){
    if(root == NULL){
        return true;
    }

    int left_sum = 0;
    int right_sum = 0;

    if(root->left != NULL){
        left_sum = root->left->data;
    }
    if(root->right != NULL){
        right_sum = root->right->data;
    }

    if(left_sum + right_sum == root->data || (root->left == NULL && root->right == NULL)){
        return helper(root->left) && helper(root->right);
    }
    else{
        return false;
    }
}

int childSum(TreeNode *root){
    return helper(root);
}
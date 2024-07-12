#include "binaryTreeMain.h"
#include<vector>
#include<stack>

void helper(TreeNode* root , int input , int &ceil){
    if(root == NULL){
        return;
    }

    if(input == root->data){
        ceil = root->data;
        return;
    }
    if((input - root->data) < (input - ceil) && (input - root->data) > 0){
        ceil = root->data;   
    }

    if(input < root->data){
        return helper(root->left , input , ceil);
    }
    else{
        return helper(root->right , input , ceil);
    }
}

int floor(TreeNode* root, int input) {
    if (root == NULL) return -1;
    int ceil = -1;
    helper(root,input,ceil);
    
    return ceil;
    
}
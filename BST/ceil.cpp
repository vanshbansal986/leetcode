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
    if((root->data - input) < (ceil - input) && (root->data - input) > 0){
        ceil = root->data;   
    }

    if(input < root->data){
        return helper(root->left , input , ceil);
    }
    else{
        return helper(root->right , input , ceil);
    }
}

int ceil(TreeNode* root , int input){
    int ceil = INT_MAX;
    helper(root,input,ceil);

    return ceil;
}
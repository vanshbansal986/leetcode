#include "binaryTreeMain.h"
#include<vector>
#include<stack>

int helper(TreeNode *root){
    if(root == NULL){
        return 0;
    }

    int left_height = helper(root->left);
    int right_height = helper(root->right);

    int max_height = 1 + max(left_height,right_height);

    return max_height;
}

int max_height(TreeNode *root){
    return helper(root);
    
}

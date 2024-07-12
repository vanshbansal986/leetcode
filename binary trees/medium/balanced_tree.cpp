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

bool balanced_tree(TreeNode *root){
    
    if(root == NULL){
        return true;
    }

    int left_depth = depth(root->left);
    int right_depth = depth(root->right);

    if(abs(left_depth-right_depth) > 1){
        return false;
    }
    else{
        bool left_tree = balanced_tree(root->left);
        bool right_tree = balanced_tree(root->right);

        return left_tree && right_tree;
    }
}

int max_height(TreeNode *root){
    return depth(root);
    
}

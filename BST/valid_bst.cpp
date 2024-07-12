#include "binaryTreeMain.h"
#include<vector>
#include<stack>

bool helper(TreeNode* root){
    if(root == NULL){
        return true;
    }

    bool a,b;
    
    if(root->right == NULL){
        return true;
    }
    else if(root->data < root->right->data){
        TreeNode* rightNode = root->right;
        while(rightNode->left != NULL){
            rightNode = rightNode->left;
        }
        if(root->data < rightNode->data){
            a = helper(root->right);
        }

    }

    if(root->left == NULL){
        return true;
    }
    else if(root->data > root->left->data){
        
        TreeNode* leftNode = root->left;

        while(leftNode->right != NULL){
            leftNode = leftNode->right;
        }

        if(root->data > leftNode->data){
            b = helper(root->left);
        }

        return a && b;
    }

    return false;
}

int valid(TreeNode* root) {
    return helper(root);
    
}
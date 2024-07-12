#include "binaryTreeMain.h"
#include<vector>
#include<stack>

int maxi(TreeNode *root){
    if(root == NULL){
        return INT_MIN;
    }

    return max(maxi(root->left) , maxi(root->right));
}

int mini(TreeNode *root){
    if(root == NULL){
        return INT_MAX;
    }

    return min(mini(root->left) , mini(root->right));
}

bool helper(TreeNode* root){
    if(root == NULL){
        return true;
    }

    int val = root->data;
    int rightMax = maxi(root->right);
    int leftMax = mini(root->left);

    bool output = (val < rightMax) && (val>leftMax) && (helper(root->left)) && helper(root->right);

    return output;
}

int valid(TreeNode* root) {
    return helper(root);
    
}
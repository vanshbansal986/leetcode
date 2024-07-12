#include "binaryTreeMain.h"
#include<vector>
#include<stack>
#include<string>
#include<queue>

bool isLeaf(TreeNode *root){

}


void helper(TreeNode* root , TreeNode *prev){
    if(root == NULL){
        return;
    }

    helper(root->right , prev);
    helper(root->left , prev);

    root->right = prev;
    root->left = NULL;
    prev = root;

   
}

void flatten(TreeNode* root) {
    return helper(root,NULL);
}
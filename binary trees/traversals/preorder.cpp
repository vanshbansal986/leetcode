#include "binaryTreeMain.h"
#include<vector>

void helper(vector<int> &output , TreeNode *root){
    if(root == NULL){
        return;
    }

    output.push_back(root->data);
    helper(output , root->left);
    helper(output , root->right);
}

vector<int> preorder(TreeNode *root){
    vector<int> output;

    helper(output , root);

    return output;
}

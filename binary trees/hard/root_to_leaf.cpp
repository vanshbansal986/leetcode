#include "binaryTreeMain.h"
#include<vector>
#include<stack>

bool isLeaf(TreeNode *root){
    if(root->left == NULL && root->right == NULL){
        return true;
    }

    return false;
}

void helper2(TreeNode *root ,vector<int> &mini, vector<vector<int>> &output){
    
    if(root == NULL){
        return;
    }

    mini.push_back(root->data);

    if(isLeaf(root)){
        
        output.push_back(mini);
        mini.pop_back();
        return;
    }
    else{

        if(root->left != NULL){
            helper2(root->left , mini , output);

        }
        if(root->right != NULL){
            helper2(root->right , mini , output);

        }

        mini.pop_back();
    }
}

vector<vector<int>> helper(TreeNode *root){
    vector<int> mini;
    
}

vector<vector<int>> max_height(TreeNode *root){
    
    
}

#include "binaryTreeMain.h"
#include<vector>
#include<stack>

void helper(vector<int> &output , TreeNode *root){
}

vector<int> preorder(TreeNode *root){
    stack<TreeNode*> s;
    
    s.push(root);

    while(!s.empty()){

        TreeNode *curr = s.top();
        s.pop();
        
        cout<< curr->data <<" ";
        
        if(curr->right != NULL){
            s.push(curr->right);
        }
        if(curr->left != NULL){
            s.push(curr->left);
        }
        
    }
}

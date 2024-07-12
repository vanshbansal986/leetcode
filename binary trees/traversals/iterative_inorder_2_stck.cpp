#include "binaryTreeMain.h"
#include<vector>
#include<stack>

void helper(vector<int> &output , TreeNode *root){
}

void preorder(TreeNode *root){

    if(root == NULL){
        return;
    }

    stack<TreeNode*> st1;
    stack<TreeNode*> st2;
    
    st1.push(root);

    while(!st1.empty()){
        
        
        TreeNode *curr = st1.top();
        st2.push(curr);
        st1.pop();

        if(curr->left != NULL){
            st1.push(curr->left);
        }
        if(curr->right != NULL){
            st1.push(curr->right);
        }

        
        
    }

    while(!st2.empty()){
        cout<<st2.top()<<" ";
        st2.pop();
    }
}

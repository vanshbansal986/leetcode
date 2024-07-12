#include "binaryTreeMain.h"
#include<vector>
#include<stack>

void helper(TreeNode *root){
    
    stack<TreeNode*> left;
    stack<TreeNode*> right;

    left.push(root);

    while(!left.empty() && !right.empty()){
        
        if(!left.empty()){
            while(!left.empty()){
                TreeNode *curr = left.top();
                left.pop();

                
                cout<<curr->data<<" "; 
                
                if(curr->left != NULL){
                    left.push(curr->left);
                }
                
                if(curr->right != NULL){
                    right.push(curr->right);
                }
                
            }
        }
        else{
            TreeNode *curr = right.top();
            right.pop();

            if(curr->left != NULL){
                left.push(curr->left);
            }
            else{
                cout<<curr->data<<" ";
            }

            if(curr->right != NULL){
                right.push(curr->right);
            }
        }

    }
}

int boundry(TreeNode *root){
    // return depth(root);
    
}

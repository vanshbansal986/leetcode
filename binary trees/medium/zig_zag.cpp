#include "binaryTreeMain.h"
#include<vector>
#include<stack>


vector<vector<int>> zig_zag(TreeNode *root){

    vector<vector<int>> output;

    stack<TreeNode*> st1;
    stack<TreeNode*> st2;

    st1.push(root);

    while(! (st1.empty() && st2.empty()) ){
        
        if(!st1.empty()){
            vector<int> mini;

            while(!st1.empty()){
                TreeNode *curr = st1.top();
                mini.push_back(curr->data);

                if(curr->left != NULL){
                    st2.push(curr->left);
                }
                if(curr->right != NULL){
                    st2.push(curr->right);
                }

                st1.pop();
            }

            output.push_back(mini);
        }

        if(!st2.empty()){
            vector<int> mini;
            
            while(!st2.empty()){
                TreeNode *curr = st2.top();
                mini.push_back(curr->data);

                if(curr->right != NULL){
                    st1.push(curr->right);
                }

                if(curr->left != NULL){
                    st1.push(curr->left);
                }

                st2.pop();
            }

            output.push_back(mini);
        }

    }

    return output;

}

int max_height(TreeNode *root){
    //return depth(root);
    
}

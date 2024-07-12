#include "binaryTreeMain.h"
#include<vector>
#include<queue>

void helper(vector<int> &output , TreeNode *root){
    if(root == NULL){
        return;
    }

    output.push_back(root->data);
    helper(output , root->left);
    helper(output , root->right);
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> output;
    if(root == NULL){
        return output;
    }
    
    queue<TreeNode*> pending;
    vector<int> mini;
    
    pending.push(root);
    pending.push(NULL);
    
    while(!pending.empty()){
        
        TreeNode *front = pending.front();
        


        if(front != NULL){
            if(front->left != NULL){
                pending.push(front->left);
            }
            if(front->right != NULL){
                pending.push(front->right);
            }

            mini.push_back(front->data);
        }
        else{

            output.push_back(mini);
            mini.clear();
            vector<int> mini;

            if(pending.size()>1){
                pending.push(NULL);
            }
        }

        pending.pop();

    }


}

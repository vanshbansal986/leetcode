#include "binaryTreeMain.h"
#include<vector>
#include<stack>
#include<string>
#include<queue>


string serialize(TreeNode* root){
    string s;
    s.push_back('[');
    
    queue<TreeNode*> pending;
    
    if(root != NULL){
        pending.push(root);
    }

    while(!pending.empty()){

        TreeNode *front = pending.front();
        
        pending.pop();
        
        int val = 48 + front->data;
        s.push_back(val);
        s.push_back(',');

        if(front->left == NULL){
            s.push_back('N');
            s.push_back(',');
        }
        else{
            pending.push(front->left);
        }

        if(front->right == NULL){
            s.push_back('N');
            s.push_back(',');
        }
        else{
            pending.push(front->right);
        }


    }

    s.pop_back();
    s.push_back(']');

    return s;
}

TreeNode* helper(string data , int &curr){
    if(data[curr] == 'N'){
        return NULL;
    }

    int root_val = data[curr] - 48;
    TreeNode * root = new TreeNode(root_val);

    curr++;
    TreeNode *left = helper(data ,curr);
    TreeNode *right = helper(data ,curr);

    root->left = left;
    root->right = right;

    return root;

}

// Decodes your encoded data to tree.    
TreeNode* deserialize(string data){            
    //return helper(data , 1);
}
#include "binaryTreeMain.h"
#include<vector>
#include<stack>



bool isLeaf(TreeNode *root){
    if(root->left == NULL && root->right == NULL){
        return true;
    }

    return false;
}

void right_print(TreeNode *root){
    TreeNode *curr = root;
    stack<int> st;

    while(curr != NULL){
        if(!isLeaf(curr)){
            st.push(curr->data);
        }

        if(curr->right != NULL){
            curr = curr->right;
        }
        else{
            curr = curr->left;
        }
    }

    while(st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

}

void leaf_print(TreeNode *root){
    if(root == NULL){
        return;
    }

    if(isLeaf(root)){
        cout<<root->data<<" ";
        return;
    }

    leaf_print(root->left);
    leaf_print(root->right);

}

void left_print(TreeNode *root){


	TreeNode *curr = root;

    // print left half of tree
    while(curr != NULL){
        

        if(!isLeaf(curr)){
            cout<<curr->data<<" ";
        }

        if(curr->left != NULL){
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
        
    }


}

int boundry(TreeNode *root){
    if(root != NULL){
        cout<<root->data<<" ";
    }

    left_print(root->left);
    leaf_print(root);
    right_print(root->right);
    
}

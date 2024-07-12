#include "binaryTreeMain.h"
#include<vector>
#include<stack>



TreeNode* lowestCommonAncestor(TreeNode *root , TreeNode* p, TreeNode* q){
    if(root == NULL){
        return NULL;
    }

    if(root->data == p->data || root->data == q->data){
        return root;
    }

    TreeNode *left_ans = lowestCommonAncestor(root->left,p,q);
    TreeNode *right_ans = lowestCommonAncestor(root->right,p,q);

    if(left_ans != NULL && right_ans != NULL){
        return root;
    }
    else if(left_ans != NULL && right_ans == NULL){
        return left_ans;
    }
    else if(left_ans == NULL && right_ans != NULL){
        return right_ans;
    }
    else{
        return NULL;
    }

    
}
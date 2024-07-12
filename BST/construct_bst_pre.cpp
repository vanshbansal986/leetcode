#include "binaryTreeMain.h"
#include<vector>
#include<stack>

TreeNode *helper(vector<int>& pre , int start , int end){
    if(start > end){
        return NULL;
    }
    

    int root_val = pre[start];
    TreeNode *root = new TreeNode(root_val);

    int i = start + 1;
    while(i <= end && pre[i] < root_val){
        i++;
    }

    TreeNode *left = helper(pre , start+1 , i-1);
    TreeNode *right = helper(pre , i , end);

    root->right = right;
    root->left = left;

    return root;
    
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder , 0 , preorder.size()-1);
}
#include "binaryTreeMain.h"
#include<vector>
#include<stack>


TreeNode* helper(vector<int>& pre, vector<int>& in , int inS , int inE , int preS , int preE){
    if(inS > inE || preS > preE){
        return NULL;
    }

    TreeNode* root = new TreeNode(pre[preS]);

    int rootVal = pre[preS];
    
    int rootInd = 0;
    for(int i = inS; i<=inE; i++){
        if(in[i] == rootVal){
            rootInd = i;
            break;
        }
    }

    int left_pre_start = preS + 1;
    int left_in_start = inS;
    int left_in_end = rootInd - 1;
    int left_pre_end = left_pre_start + (left_in_end - left_in_start );

    TreeNode *leftChild = helper(pre , in , left_in_start , left_in_end , left_pre_start , left_pre_end);

    int right_pre_start = left_pre_end + 1;
    int right_pre_end = preE;
    int right_in_start = rootInd + 1;
    int right_in_end = inE;

    TreeNode *rightChild = helper(pre,in , right_pre_start , right_pre_end , right_in_start , right_in_end);

    root->left = leftChild;
    root->right = rightChild;

    return root;

}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int preE = preorder.size() - 1;
    int inE = inorder.size() - 1;

    return helper(preorder , inorder , 0 , inE , 0 , preE);
}
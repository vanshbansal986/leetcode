#include "binaryTreeMain.h"
#include<vector>
#include<stack>


TreeNode* helper(vector<int>& in, vector<int>& post , int inS , int inE , int postS , int postE){
    // base case
    if (inS > inE || postS>postE){
        return NULL;
    }    

    // root of binary tree
    TreeNode *root=new TreeNode(post[postE]);

 

    // finding the root index in inorder array
    int rootInd=-1;
    for(int i=inS; i<=inE; i++){
        if(in[i]== post[postE]){
            rootInd=i;
            break;
        }
    }

    int Lin_start = inS;       //in0rder start for left tree would be the first elem of inorder array
    int Lin_end = rootInd-1;    // end would be the elem before the root 
    int Lpost_start = postS;    // post start for left tree would be the first elem of post array
    int Lpost_end = Lin_end + Lpost_start - Lin_start;  // use maths to calc this
    
    TreeNode *leftChild=helper(post, in, Lin_start, Lin_end, Lpost_start, Lpost_end);

    
    int Rin_start = rootInd + 1;  // right subtree starts after root in inorder
    int Rin_end = inE;      // right subtree ends in the last i.e last elem of inorder array
    int Rpost_start = Lpost_end + 1;    // right subtree starts after left subtree ends in post
    int Rpost_end = postE-1;        // right subtree ends at the 2nd last elem of post array

    TreeNode *rightChild=helper(post, in, Rin_start, Rin_end, Rpost_start, Rpost_end);

    root->left=leftChild;
    root->right=rightChild;

    return root;

}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int preE = preorder.size() - 1;
    int inE = inorder.size() - 1;

    return helper(preorder , inorder , 0 , inE , 0 , preE);
}
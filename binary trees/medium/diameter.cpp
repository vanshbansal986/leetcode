#include "binaryTreeMain.h"
#include<vector>
#include<stack>

class pair1{
    int height;
    int diameter;
};

int depth(TreeNode *root){
    if(root == NULL){
        return 0;
    }

    int left_height = depth(root->left);
    int right_height = depth(root->right);

    int max_height = 1 + max(left_height,right_height);

    return max_height;
}

pair<int,int> helper(TreeNode *root){
    if(root == NULL){
        pair<int,int> p(0,0);
        return p;
    }

    pair<int,int> left_tree = helper(root->left);
    pair<int,int> right_tree = helper(root->right);

    int left_height = left_tree.first;
    int left_diameter = left_tree.second;
    int right_height = right_tree.first;
    int right_diameter = right_tree.second;

    int height = 1 + max(left_height , right_height);
    int diameter = left_height + right_height + 1;

    pair<int,int> p = make_pair(height,diameter);
    return p;

}

int diameter(TreeNode *root){
    return helper(root).second;
    
}

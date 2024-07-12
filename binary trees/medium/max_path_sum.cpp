#include "binaryTreeMain.h"
#include<vector>
#include<stack>



int helper(TreeNode *root , int &max_sum){
    if(root == NULL){
        return 0;
    }

    int left_val = helper(root->left , max_sum);
    int right_val = helper(root->right , max_sum);

    int val = root->data + max(left_val,right_val);
    
    int total_val = root->data + left_val + right_val;
    
    max_sum = max(total_val , max_sum);

    return val;

}

int diameter(TreeNode *root){

    int max_sum = 0;
    int ans = helper(root,max_sum);
    
    return max_sum;
}

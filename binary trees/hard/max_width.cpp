#include "binaryTreeMain.h"
#include<vector>
#include<stack>
#include<queue>

int helper(vector<TreeNode*> nodes){
    int n = nodes.size();
    int size = 0;
    int max_size = 0;

    for(int i=0; i<n; i++){
        
        if(nodes[i] == NULL){

        }
    }
}

int childSum(TreeNode *root){

    queue<pair<TreeNode* , int>> pending;
    int ind = 0;
    int max_width = 0;
    

    if(root != NULL){
        pending.push(make_pair(root,ind));
    }

    while(pending.empty()){
        pair<TreeNode* , int> front = pending.front();
        pair<TreeNode* , int> back = pending.back();


        int min = front.second;

        int width = back.second - front.second + 1;
        
        if(width > max_width){
            max_width = width;
        }

        for(int j = 0; j<pending.size(); j++){
            
            pair<TreeNode* , int> curr = pending.front(); 
            

            int i = curr.second - min;

            if(curr.first->left != NULL){
                pending.push(make_pair(curr.first->left , 2*i + 1));
            }
            if(curr.first->right != NULL){
                pending.push(make_pair(curr.first->right,2*i + 2));
            }

            pending.pop();

        }
        
    }

    return max_width;


}
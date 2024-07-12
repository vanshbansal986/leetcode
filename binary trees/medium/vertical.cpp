#include "binaryTreeMain.h"
#include<vector>
#include<stack>
#include<unordered_map>

void helper2(TreeNode *root , unordered_map<int,vector<int>> &m , int val){
    if(root == NULL){
        return;   
    }

    if(m.count(val) != 0){
        
        m[val].push_back(root->data);
    }
    else{
        vector<int> v(root->data);
        m[val] = v;
    }

    helper2(root->left , m , val-1);
    helper2(root->right , m , val+1);
}

vector<vector<int>> helper(TreeNode *root){
    int val = 0;
    unordered_map<int,vector<int>> m;
    vector<vector<int>> output;

    helper2(root,m,0);

    for(auto i = m.begin(); i!= m.end(); i++){
        output.push_back(i->second);
    }

    return output;



}

int max_height(TreeNode *root){
    //return helper(root);
    
}

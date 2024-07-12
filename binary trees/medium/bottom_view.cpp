#include "binaryTreeMain.h"
#include<vector>
#include<stack>
#include<unordered_map>
#include<map>


vector<int> vertical(TreeNode *root){

    map<int ,int > m;
    queue <pair< TreeNode* , int>> pending;

    if(root != NULL){
        pending.push(make_pair(root , 0));
    }

    while(!pending.empty()){
        pair< TreeNode* , int > temp = pending.front();
        pending.pop();

        TreeNode *front_node = temp.first;
        int hd = temp.second;

        
        m[hd] = (front_node->data);
        

        if(front_node->left != NULL){
            pending.push( make_pair ( front_node->left , hd-1 ));
        } 

        if(front_node->right != NULL){
            pending.push( make_pair ( front_node->right , hd+1 ));
        } 
    }

    vector<int> ans;

    for(auto i : m){
       
       ans.push_back(i.second);
        
    }

    return ans;

}

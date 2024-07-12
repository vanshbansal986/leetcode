#include "binaryTreeMain.h"
#include<vector>
#include<stack>
#include<unordered_map>
#include<map>


vector<int> vertical(TreeNode *root){

    map<int , map<int , vector<int> > > m;
    queue <pair< TreeNode* , pair<int,int> > > pending;

    if(root != NULL){
        pending.push(make_pair(root , make_pair(0,0)));
    }

    while(!pending.empty()){
        pair< TreeNode* , pair<int,int> > temp = pending.front();
        pending.pop();

        TreeNode *front_node = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        m[hd][lvl].push_back(front_node->data);

        if(front_node->left != NULL){
            pending.push( make_pair ( front_node->left , make_pair( hd-1 , lvl+1 ) ) );
        } 

        if(front_node->right != NULL){
            pending.push( make_pair ( front_node->right , make_pair( hd+1 , lvl+1 ) ) );
        } 
    }

    

}

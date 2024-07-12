#include "binaryTreeMain.h"
#include<vector>
#include<stack>

    void make_map(TreeNode* root , TreeNode* target , unordered_map<TreeNode*,TreeNode*> &m){
        if(root == target || root == NULL){
            return;
        }

        if(root->left != NULL){
            m[root->left] = root;


        }
        if(root->right != NULL){
            m[root->right] = root;

        }

        make_map(root->left , target , m);
        make_map(root->right , target , m);


    }

    void helper(TreeNode *root , int k , int val , vector<int> &ans,unordered_map<TreeNode*,TreeNode*> m,unordered_map<TreeNode*,bool> &visited){

        if(root == NULL){
            return;
        }
        if(visited[root] == true){
            return;
        }

        visited[root] = true;

        if(val > k){
            return;
        }
        if(val == k){
            ans.push_back(root->data);
            return;
        }


        helper(root->left  , k , val+1, ans , m , visited);
        helper(root->right , k , val+1 , ans , m , visited);

        if(m.count(root) != 0 && m[root] != NULL){
            
            helper(m[root] , k , val+1 , ans , m , visited);

        }

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<TreeNode*,TreeNode*> m;
        unordered_map<TreeNode*,bool> visited;
        m[root] = NULL;
        
        make_map(root,target,m);
        helper(target,k,0,ans,m,visited);

        return ans;
    }
#include "binaryTreeMain.h"
#include<vector>
#include<stack>



TreeNode* lowestCommonAncestor(TreeNode *root , TreeNode* p, TreeNode* q){
    queue<TreeNode*> pending;
    
    pending.push(root);
    
    vector<TreeNode*> nodes;
    vector<int> output;

    int p_ind = 0;
    int q_ind = 0;

    while (pending.size() != 0){
        
        TreeNode *front=pending.front();
        pending.pop();
        
        if(front == NULL){
            output.push_back(-1);
            nodes.push_back(NULL);
        }    
        else{
            output.push_back(front->data);
            nodes.push_back(front);
            
            if(front->data == p->data){
                p_ind = output.size()-1;
            }
            if(front->data == q->data){
                q_ind = output.size()-1;
            }

            pending.push(front->left);
            pending.push(front->right);
        }
        
    }    

    vector<int> x;
    vector<int> y;

    while(p_ind>0){
        x[p_ind] = p_ind;

        p_ind = (p_ind + 1)/2 - 1;
    }

    while(q_ind>0){
        y[q_ind] = q_ind;

        q_ind = (q_ind + 1)/2 - 1;
    }

    if(x.size() > y.size()){
        return nodes[y.front()];
    }
    else{
        return nodes[x.front()];
    }

    
    
}

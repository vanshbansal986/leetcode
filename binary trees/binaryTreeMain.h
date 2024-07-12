#include "int_binaryTree.h"
#include <queue>

TreeNode *takeinput(){
    int rootData;
    cout<<"Enter root data: ";
    cin>>rootData;

    TreeNode *root=new TreeNode(rootData);
    queue<TreeNode*> pending;
    pending.push(root);

    while(pending.size()!=0){
        TreeNode *front=pending.front();
        int leftData;
        int rightData;

        cout<<"Enter the left child for "<<front->data<<"th node: ";
        cin>>leftData;

        if(leftData != -1){
            TreeNode *leftChild=new TreeNode(leftData);
            front->left=leftChild;
            pending.push(leftChild);
        }

        cout<<"Enter the right child for "<<front->data<<"th node: ";
        cin>>rightData;

        if(rightData != -1){
            TreeNode *rightChild=new TreeNode(rightData);
            front->right=rightChild;
            pending.push(rightChild);
        }

        pending.pop();


    }

    return root;
}

void printTree(TreeNode *root){
    
    
    queue<TreeNode*> pending;
    pending.push(root);

    while(pending.size() != 0){
        TreeNode* front=pending.front();

        cout<<front->data<<": ";
        
        if(front->left != NULL){
            cout<<"L"<<front->left->data<<", ";
            pending.push(front->left);
        }
        else{
            cout<<"L"<<"-1"<<", ";
        }
        
        if(front->right != NULL){
            cout<<"R"<<front->right->data;  
            pending.push(front->right);
        }
        else{
            cout<<"R"<<"-1";
        }       

        pending.pop();
        cout<<endl;
    }
}
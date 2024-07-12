#include <iostream>
using namespace std;

// template <typename T>

class TreeNode{
    public:
    
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }

    ~TreeNode(){
        delete left;
        delete right;
    }

};
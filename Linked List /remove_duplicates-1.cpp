// https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

#include<iostream>
#include<unordered_map>
using namespace std;

class node{
    public:
    int data;
    node *next;

    node(int data){
        this->data=data;
        next=NULL;
    }
};

node *takeinput(){
    int data;
    cin>>data;
    node *head=NULL;

    while (data != -1 ){
        node *newNode=new node(data);
        if(head==NULL){
            head=newNode;
        }
        else{
            node *temp=head;
            while(temp->next !=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
        }

        cin>>data;
    }

    return head;
    
}

int length(node *head)
{
	int count=0;
    node *temp=head;
    while(temp != NULL){
        temp=temp->next;
        count++;
    }
    return count;
}

node *remove_duplicates(node *head){
    unordered_map<int,int> m;
    node *temp = head;
    
    while(temp != NULL){
        int val = temp->data;
        m[val] = 1;

        temp = temp->next;
    }

    temp = head;
    m[head->data] = 0;
    while(temp != NULL && temp->next != NULL){
        node *prev = temp;
        node *curr = prev->next;
        node *next = curr->next;

        int val = curr->data;
        if(m[val] == 1){
            // we have seen this node once so we change its flag value
            m[val] = 0;
            temp = temp->next;
        }
        else if(m[val] == 0){
            // we have to remove this node
            
            prev->next = next;
            delete curr;
            temp = temp;
            // m[val] -= 1;
        }
        
    }

    return head;



}

void print(node *head){

    node *temp=head;
    while(temp!=NULL){      // or we can use while(temp != NULL){}
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    node *head = takeinput();
    

    node *head1 = remove_duplicates(head);
    print(head1);

   
    return 0;
}


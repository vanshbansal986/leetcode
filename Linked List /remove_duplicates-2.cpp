// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/

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
    int head_flag = 0;
    
    while(temp != NULL){
        int val = temp->data;
        if(m.count(val)){
            m[val] += 1;
        }
        else{
            m[val] = 1;
        }

        temp = temp->next;
    }

    temp = head;

    while(temp != NULL && temp->next != NULL){
        
        if(temp == head && head_flag == 0){

            int val = temp->data;
            if(m[val] > 1){
                head = temp->next;
                temp = head;
            }
            else if(m[val] == 1){
                temp = temp;
                head_flag = 1;
            }

        }
        else{
            node *prev = temp;
            node *curr = temp->next;
            node *next = curr->next;

            int val = curr->data;
            if(m[val] > 1){
                // we have to delete this node
                prev->next = next;
                delete curr;
                temp = temp;
            }
            else if(m[val] == 1){
                temp = temp->next;
            }

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



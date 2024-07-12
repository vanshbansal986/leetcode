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
    node *temp = head;
    int head_flag = 0;
    while(temp->next != NULL){
        if(temp == head && head_flag == 0){
            node *adj = temp->next;
            node *curr = temp;
            int adj_val = adj->data;
            int curr_val = curr->data; 

            if(curr_val == adj_val){
                while(curr_val == adj_val){
                    adj = adj->next;
                    adj_val = adj->data;
                }
                head = adj;
                temp = head;
            }
            else{
                head_flag = 1;
                temp = temp;
            }

        }
        else{
            node *prev = temp;
            node *curr = prev->next;
            node *adj = curr->next;
            int curr_val = curr->data;
            int adj_val;
            
            if(adj == NULL){
                adj_val = -1;
            }
            else{
                adj_val = adj->data;
            }
            

            if(curr_val == adj_val){
                while(curr_val == adj_val){
                    adj = adj->next;
                    adj_val = adj->data;
                }
                prev->next = adj;
                temp = prev;

            }
            else{
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


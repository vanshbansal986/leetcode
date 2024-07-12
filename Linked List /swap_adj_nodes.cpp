#include<iostream>
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

node *swap_adj(node *head){
    node *temp = head;
    node *head1 = NULL;
    int flag = 0;
    
    while(temp->next != NULL){
        if(flag == 0){
            
            node *adj = temp->next;
            node *adj_next = adj->next;

            // head = adj;
            adj->next = temp;           //head->next = temp;
            temp->next = adj_next;      //temp->next = adj_next;

            head = adj;
            head1 = adj;
            temp = temp;
            
            flag = 1;

            cout<<"the values are: "<<"temp:"<<temp->data<<" head: "<<head1->data<<" adj:"<<adj->data<<" adj_next:"<<adj_next->data<<endl;

        }
        // else{
        //     node *curr_node = temp->next;
        //     node *adj_node = curr_node->next;
        //     node *adj_next = adj_node->next;

        //     temp->next = adj_node;
        //     adj_node->next = curr_node;
        //     curr_node->next = adj_next;

        //     temp = curr_node; 
        // }

        node *curr_node = temp->next;
        node *adj_node = curr_node->next;
        node *adj_next = adj_node->next;

        temp->next = adj_node;
        adj_node->next = curr_node;
        curr_node->next = adj_next;

        temp = curr_node;

    }

    return head1;

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
    node *head1 = takeinput();
    

    node *head = swap_adj(head1);
    print(head);

   
    return 0;
}


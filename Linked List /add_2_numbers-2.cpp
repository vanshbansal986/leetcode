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

node *add_two(node *head1 , node *head2){
    node *temp1 = head1;
    node *temp2 = head2;
    node *head = NULL;
    node *tail = NULL;

    int carry = 0;
    while(temp1 != NULL || temp2 != NULL){
        
        int sum1 = 0;
        int sum2 = 0;
        if(temp1 == NULL){
            sum1 = 0;
        }
        else{
            sum1 = temp1->data;
            temp1 = temp1->next;
        }
        if(temp2 == NULL){
            sum2 = 0;
        }
        else{
            sum2 = temp2->data;
            temp2 = temp2->next;
        }
        

        int sum = (sum1 + sum2 + carry)%10;
        // cout<<"sum is:"<<sum<<endl;
        carry = (sum1+sum2)/10;

        // inserting this sum in linked list
        
        node *newNode = new node(sum);
        
        if(head == NULL){
            head = newNode;
            tail = head;
        }
        else{
            tail->next = newNode;
            tail = tail->next;
        }

        
        
        
    }
    tail->next = NULL;
    return head;
}

void print(node *head){

    node *temp=head;
    while(temp != NULL){      // or we can use while(temp != NULL){}
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    node *head1 = takeinput();
    node *head2=  takeinput();

    node *head = add_two(head1,head2);
    print(head);

   
    return 0;
}

int64_t a;
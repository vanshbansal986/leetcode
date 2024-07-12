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

    int length1 = length(temp1);
    int length2 = length(temp2);

    int multiplier1 = 1;
    for(int i=1; i<length1; i++){
        multiplier1 *= 10;
    }

    int multiplier2 = 1;
    for(int i=1; i<length2; i++){
        multiplier2 *= 10;
    }

    int sum1 = 0;
    while(temp1 != NULL){
        
        int val =0;
        val = temp1->data * multiplier1;
        sum1 += val; 
        
        multiplier1 = multiplier1/10;
        temp1 = temp1->next;

    }

    int sum2 = 0;
    while(temp2 != NULL){
        
        int val =0;
        val = temp2->data * multiplier2;
        sum2 += val; 
        
        multiplier2 = multiplier2/10;
        temp2 = temp2->next;

    }

    int totalSum = sum1 + sum2;

    while(totalSum >= 1){
        int val = totalSum % 10;
        node *newNode = new node(val);
        
        if(head == NULL){
            head = newNode;
        }
        else{
            node *temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }

            temp->next = newNode;
        }

        totalSum = totalSum/10;

    }

    return head;


}

void print(node *head){

    node *temp=head;
    while(temp->data!=-1){      // or we can use while(temp != NULL){}
        cout<<temp->data<<endl;
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
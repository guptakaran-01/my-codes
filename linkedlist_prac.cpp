#include<iostream>
using namespace std ;


class node{
    public:
    int data ;
    node * next ;

    node(int d){
        this->data=d;
        this->next=NULL;
    }
    ~node(){
    }
};

void print(node* &head){
    node* temp =head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    
}

void insertathead(node* &head , int data){
    node* temp=new node(data);
    temp->next=head;
    head=temp;
}

void insertatend(node* &tail , int data){
    node * temp=new node(data);
    tail->next=temp;
    tail=temp;

}

void insertatposition(node* &head , int position , int data){
    
     if(position==1){
         insertathead(head , data);
         return ;
     }
     else{
         node * temp=head;
        int count =1;
        while (count<position-1)
        {
            temp=temp->next;
            count++;
        }

        node* n=new node(data);
       n->next=temp->next;
       temp->next=n;       

     }

}

void deletenode (node* &head , int position)
{
    node *temp=head;
    if(position==1){
        head=head->next;
        temp->next=NULL;
        delete(temp);
    }
    else{
        int count=1;
        node *prev=NULL;
        while(count < position){
            prev=temp;
            temp=temp->next;
            count++;
        }
        prev->next=temp->next;
        temp->next=NULL;
        delete(temp);
    }
}




int main()
{
    node *n1= new node(10);
    
    node* head=n1;
    node* tail=n1;

    // print(head);

    insertathead(head , 12);
    // print(head);

    insertatend(tail , 11);
    // print(head);

    insertatposition(head , 4 ,22);
    print(head);

    
    deletenode(head , 2);  

    print(head);



    return 0;
}

#include<iostream>
using namespace std ;

class Node{
 public:
    int data ;
    Node* next;

    
    Node (int d){
        this->data=d;
        this->next=NULL;
    }

};

class stack {
   Node* top;

   public:
   stack(){
    top=NULL;
   }

   void push (int d){
    Node* n=new Node(d);
    n->next=top;
    top=n;
   }

   void pop(){
    if(top==NULL){
        cout<<"Stack Undderflow"<<endl;
        return;
    }
    else{
        Node*temp=top;
        top=top->next;
        delete temp;
    }
   }

   int peek (){
      if(top==NULL){
         cout<<"Stack is empty"<<endl;
        return -1;
      }
      else{
        return top->data;
      }
   }

   bool isempty(){
      if(top==NULL){
        return true;
      }
      else return false ;
   }


};


int main() {
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.peek() << endl; 
    s.pop();
    cout << s.peek() << endl; 
}
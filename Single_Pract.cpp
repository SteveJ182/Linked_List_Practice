#include <iostream>
using namespace std;
struct Node{
  int value;
  struct Node * next; //next is a struct and the * mean to connect to the next Node
  
}

class LinkedList{
  public:
  LinkedList(){
    //it does not matter the order the variable are made as we can call private varibale in public
    head = nullptr;
    tail = nullptr;
  }
  
  //function to add a nose to the linked list, should be added next to tail/ point to tail
  void createNode(int value)
  {
    node *temp = new Node;
    temp->data = value;
    temp->next = nullptr;
    
      //checks if list is empty
      if(head == nulptr){
        head = temp;
        tail = temp;
      }
      //if not then assigns value
      else{
        tail->next = temp;
        tail=temp;
      }
      
  }
  
  //function to iterate through the list
  void printList(){
    Node * current = head;
    //once a nullptr is found the list is the end/tail and knows to stop
    while(current != nullptr){
      cout << curent->value << endl;
      current = current->next;
    }
  }
  
  
  private:
  Node *head;
  Node *tail;
  
};


int main() 
{
    cout << "Hello, World!";
    return 0;
}

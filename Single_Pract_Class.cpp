#include <iostream>
using namespace std;
//each node consits of a data item and an address of another node

class Node{
  public:
  int data;  //data item
  Node* next; //pointer to another struct node

  //Constructor to intialize the node with data
  Node(int new_data){
    this->data=new_data;
    this->next = nullptr;
  }

};

// Function to traverse and print the singly linked list
void traverseList(Node* head){
  //A loop that runs till head is nullptr
  while(head!=nullptr){
    //printing data of current node
    cout<< head->data << " ";
    //Moving to next node
    head = head->next;
  }
  cout << endl;
}

//Function to traverse list recursively 
void recursive(Node* head){
  //Base condition is when the head is nullptr
  if(head == nullptr){
    cout << endl;
    return;
  }
  //printing the current node data
  cout << head->data << " ";
  //Moving to the next node
  recursive(head->next);
  
}



int main() 
{
  //hard-coded linked list:
  //10 -> 20 -> 30 -> 40
  Node* head = new Node(10);  // assigns value of 10 to data at head of list, This also assigns the next value or the tail to null 
  head->next = new Node(20);  //assigns the tail value to 20 and makes a new tail value null
  head->next->next = new Node(30);  //assigns the tail value from prior to 30 and makes a new tail value to null
  head->next->next->next = new Node(40); // assigns the tail value from proir to 30 and makes a new tail value to null

  traverseList(head);
  recursive(head);
  return 0;
}

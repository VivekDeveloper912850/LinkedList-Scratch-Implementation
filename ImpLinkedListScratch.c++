#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node *next;
    Node(){
        //cout << "Default Constructor call " << endl;
        next  = NULL;
    }
    Node(int data){
       // cout << "Parametrized cons call" << endl;
        this->data = data;
        this->next = NULL;
    }

   
};
  void insertAtHead(Node* &head , Node* &tail , int data){
    if(head == NULL){
        // EMPTY LL
        // STEP 1 : create a new node
        Node *newNode = new Node(data);
        // step 2 update the head
        head = newNode;
        tail = newNode;
    }
    else{
         // creating the New Node
    Node *newNode = new Node(data);
    // Attach the New Node to Head
    newNode->next = head;
    // Update the Head Node
       head = newNode;

    }
   
  }

  void insertAtTail(Node* &head , Node* &tail , int data){
    if(head == NULL){
       // Empty LL
       // step1: create new node
       Node *newNode = new Node(data);
       // Step2: single node hai entire ll me
       // that why head or tail one palace par point karega
       head = newNode;
       tail = newNode;
    }
    else{
        // non empty ll
        // step1: create a new node
        Node *newNode = new Node(data);
        // step2: tail ko attach kar do new node se
           tail->next = newNode;
           // step3: Update the tail
               tail = newNode;

    }
  }

  int getLength(Node *head){
    int count = 0;
    while(head != NULL){
        count++;
    }
    return count;
  }

  void insertAtPosition(Node* &head , Node* &tail , int data , int pos){
    if(pos < 1){
        cout << "Cannot insert. Please enter the valid position" << endl;
        return;
    }
    int length = getLength(head);
    if(pos > length){
        cout << "Cannot insert , Please enter the valid position" << endl;
        return;
    }

    if(pos == 1){
        insertAtHead(head , tail , data);
    }
    else if(pos == length){
        insertAtTail(head, tail , data);
    }
    else{
        // insert the Middle Element LL
        // STEP1: create the linkelist...
        Node *newNode = new  Node(data);
        //step2: tranverse pre // curr to position
        Node* prev = NULL;
        Node* curr = head;
        while(pos != 1){
            prev = curr;
            curr = curr->next;
            pos--;
        }
        //step3: attach prev to new Node
        prev->next = newNode;
        // step4 attach newNode to curr
        newNode->next = curr;

           
    }
  }

 void printLL(Node* head){
        int count = 0;
        Node *temp = head;
        while(temp != NULL){
            count++;
           cout << temp->data << "->";
           temp = temp->next;
        }
        cout << endl;

        //cout << "LinkedList Length is := " << count << endl;

    }

int main(){
    Node *head = NULL;
    Node *tail = NULL;

    insertAtTail(head , tail , 10);
    insertAtTail(head , tail ,20);
    insertAtTail(head , tail , 30);
    insertAtTail(head , tail , 500);
    //printLL(head);

    insertAtPosition(head , tail , 5 , 1);
    printLL(head);
   // Node s;
//    Node *first = new Node(10);
//     Node *second = new Node(20);
//      Node *third = new Node(30);
//       Node *fourth = new Node(40);
//        Node *fifth = new Node(50);

//        first->next = second;
//        second->next = third;
//        third->next = fourth;
//        fourth->next = fifth;
//        Node *tail = fifth;


//        Node* head = first;
//        cout << "Printing the LinkeList := " << endl;
//        printLL(head);

//        //insertAtHead(head ,500);
//        //printLL(head) ;

//        insertAtTail(head , tail ,500);
//        printLL(head);

    return 0;
}
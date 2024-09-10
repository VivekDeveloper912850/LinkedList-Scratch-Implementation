#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(){
        prev = NULL;
        next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
void print(Node* head){

   Node* temp = head;
   while(temp != NULL){
     cout <<temp->data << "->";
     temp = temp->next;
   }
   cout << endl;
}
 
 void insertAtHead(Node* &head , Node* &tail , int data){
    // LL is Empty
    if(head == NULL){
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        // LL is not Empty
        Node *newNode = new Node(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
 }

 void insertAtTail(Node* &head , Node* &tail , int data){
    // Empty case
    if(head == NULL){

    }
    else{
        // non empty case 
         Node* newNode = new Node(data);
         tail->next = newNode;
         newNode->prev = tail;
         tail = newNode;
    }
 }

int findLength(Node* &head){
    Node* temp = head;
    int len = 0;
    while(temp != NULL){
        len++;
        temp = temp->next; 
    }
    return len;
}

//Insert At Any Position
void insertAtPosition(Node* &head , Node* &tail , int data , int pos){
    int len  = findLength(head);
    // Empty case
    if(head == NULL){
       Node* newNode = new Node(data);
       head = newNode;
       tail = newNode;
    }
    else{
        if(pos == 1){
            // first position of Element add karna hai
            insertAtHead(head , tail , data);
        }

        else if(pos == len+1){
            // last position of element add karna hai
            insertAtTail(head , tail , data);
        }
        else{
            // Middle Element me add karna hai
            // create the new Node

            Node* newNode = new Node(data);
            Node* prevNode = NULL;
            Node* currNode = head;

            while(pos != 1){
                pos--;
                prevNode = currNode;
                currNode = currNode->next;
            }
            // update the pointer
            prevNode->next = newNode;
            newNode->prev = prevNode;
            newNode->next = currNode;
            currNode->prev = newNode;

        }
    }
}
// Delete the Node
void deleteAtNode(Node* &head , Node* &tail , int pos){
    int len = findLength(head);
    if(head == tail){
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return;
    }
    // Empty case
    if(head == NULL){
        cout << "cannot delete node because LL is Empty" << endl;
        return;
    }
    else if(pos == 1){

      Node* temp = head;
      head = head->next;
      temp->next = NULL;
      head->prev = NULL;
      delete temp;
    }
    else if(pos == len){
      // delete the last node
      Node* prevNode = tail->prev;
      prevNode->next = NULL;
      tail->prev = NULL;
      delete tail;
      tail = prevNode;
    }
    else{
        // middle element delete karna hai
        //step1: set the prevNode , currNode ,
        Node* prevNode = NULL;
        Node* currNode = head;
        while(pos != 1){
            pos--;
            prevNode = currNode;
            currNode = currNode->next;
        }
        // set the nextNode
        Node* nextNode = currNode->next;
        // update the pointer
        prevNode->next = nextNode;
        currNode->prev = NULL;
        currNode->next = NULL;
        nextNode->prev = prevNode;
        delete currNode;

    }
}
int main(){

    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head , tail , 10);
     insertAtHead(head , tail , 20);
       insertAtHead(head , tail , 40);
        insertAtHead(head , tail , 60);
       // insertAtTail(head , tail , 100);

      // insertAtPosition(head, tail, 1000, 5);

      deleteAtNode(head , tail , 1);
        print(head);
        





    // Node* head = new Node(10);
    // print(head);
    // cout << findLength(head) << endl;

    return 0;
}
#include <iostream>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;
    ListNode* prev;
};

class DoublyLinkedList {
public:
    ListNode* first;
    ListNode* last;
    ListNode* loc;
    ListNode* ploc;

    // Constructor to initialize the linked list
    DoublyLinkedList() {
        first = nullptr;
        last = nullptr;
    }

    // Function to insert a node at the end of the list
    void insertAtEnd(int value) {
        ListNode* newNode = new ListNode();
        newNode->data = value;
        newNode->next = nullptr;  // Since it's the last node
        newNode->prev = last;     // Link it to the previous last node

        if (last != nullptr) {
            last->next = newNode; // Link the old last node to the new node
        }
        last = newNode;            // Update the last node pointer

        if (first == nullptr) {    // If the list was empty, set first to newNode
            first = newNode;
        }
    }

    void insertAtHead(int value){
        ListNode* newNode = new ListNode();
        newNode->data = value;
        newNode->next = first;
        newNode->prev = nullptr;

        if (first != nullptr){
            first->prev = newNode;
        }
        first = newNode;

        if (first == nullptr){
            first = newNode;
        }
    }

    // Function to display the list
    void display() {
        ListNode* current = first;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void reverse(){
        first = last;
        for (int i = 0; i < 8; i++) {
            ListNode* temp = last -> next;
            last -> next = last -> prev;
            last -> prev = temp;
            last = last -> next;
        }
        

    }
    //gives the pointer to the searched value
    ListNode* search(int value){
        loc = first;
        ploc = nullptr;
        for (int i = 0;i < 8; i++){
            if (loc -> data == value){
                return loc; /* returns the pointer to the position 
                            where the value is*/
            }
            ploc = loc;
            loc = loc-> next;
            
        }

    }

    void swap(int val1, int val2){
        ListNode* node1 = this->search(val1);
        ListNode* node2 = this->search(val2);
        
        ListNode* tempNext = node1 -> next;
        ListNode* tempPrev = node1 -> prev;

        node1 -> prev -> next = node2;
        node1 -> next -> prev = node2;

        node2 -> prev -> next = node1;
        node2 -> next -> prev = node1;

        node1 -> next = node2 -> next;
        node1 -> prev = node2 -> prev;

        node2 -> next = tempNext;
        node2 -> prev = tempPrev;
    }

    void sortEvenOdd(){
    ListNode* loc = first;  // Start from the head of the list
    ListNode* lastEven = nullptr;  // Track the position of the last even node

    while (loc != nullptr) {
        ListNode* nextNode = loc->next;  // Store next node

        if ((loc->data) % 2 == 0) {
            // If the data is even, move it to the beginning
            if (lastEven == nullptr) {
                // Move the first even node to the head if it's not already there
                if (loc != first) {
                    this->moveToHead(loc);
                }
                lastEven = first;  // Update the last even pointer
            } else {
                // Move the even node right after the last even node
                this->moveAfter(lastEven, loc);
                lastEven = loc;  // Update the last even pointer
            }
        }
        loc = nextNode;  // Move to the next node
    }
}

// Helper function to move the node to the head
void moveToHead(ListNode* node) {
    if (node == first) return;  // Already at the head
    // Remove node from its current position
    node->prev->next = node->next;
    if (node->next != nullptr) {
        node->next->prev = node->prev;
    }

    // Insert at the head
    node->next = first;
    first->prev = node;
    node->prev = nullptr;
    first = node;
}

// Helper function to move node after another node
void moveAfter(ListNode* after, ListNode* node) {
    if (node == after) return;  // Already in the correct position

    // Remove node from its current position
    if (node->prev != nullptr) {
        node->prev->next = node->next;
    }
    if (node->next != nullptr) {
        node->next->prev = node->prev;
    }

    // Insert after the specified node
    node->next = after->next;
    if (after->next != nullptr) {
        after->next->prev = node;
    }
    node->prev = after;
    after->next = node;
}


};

int main() {
    // creating a new linked list
    DoublyLinkedList dll;

    //adding values to linked list
    int list[] = {1, 24, 36, 7, 2, 7, 1, 44};

    //inserting values into the doubly linked list
    for (int i = 0; i < 8; i++) {
        dll.insertAtEnd(list[i]);
    }

    // Display the list
    dll.display();

    // dll.reverse();
    // dll.display();

    // dll.swap(7,24);
    // dll.display();

    dll.insertAtHead(4);
    dll.display();

    dll.sortEvenOdd();
    dll.display();
    return 0;
}
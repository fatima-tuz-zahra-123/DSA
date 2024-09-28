#include <iostream>
using namespace std;

class ListNode {
public:
    int data;
    ListNode *next;
};

class LinkedList {
public:
    ListNode *start;  // Stores the address of the head node.
    ListNode *last;   // Stores the address of the last node.

    LinkedList() {
        start = NULL;
        last = NULL;
    }

    // Check if the list is empty
    bool isEmpty() {
        return start == NULL;
    }

    // Insert at the front of the list
    void insertAtFront(int value) {
        ListNode *newnode = new ListNode();
        newnode->data = value;
        newnode->next = NULL;

        if (isEmpty()) {
            start = newnode;
            last = newnode;
        } else {
            newnode->next = start;
            start = newnode;
        }
    }

    // Insert at the end of the list
    void insertAtEnd(int value) {
        ListNode *newnode = new ListNode();
        newnode->data = value;
        newnode->next = NULL;

        if (isEmpty()) {
            start = newnode;
            last = newnode;
        } else {
            last->next = newnode;
            last = newnode;
        }
    }

    // Print the linked list
    void PrintList() {
        ListNode *temp = start;
        if (temp == NULL) {
            cout << "List is empty." << endl;
        } else {
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;  // Move to the next node
            }
            cout << endl;
        }
    }
	bool Search(int value) {
        ListNode* loc = start;
        ListNode* ploc = NULL;

        while(loc != NULL && loc->data < value){
            ploc = loc;
            loc = loc->next;
            
        }

        if(loc != NULL && loc->data == value){
            //loc = NULL;
            return true;
        }
        return false;

     void insertInSortedOrder(int value) {
        if (Search(value)){
            cout<< "Value already exists in the list."<< endl;
            return;
        }

        ListNode *newnode = new ListNode();
        newnode->data = value;
        newnode->next = NULL;

       //empty list 
        if (isEmpty() || start->data >= value) {
            newnode->next = start;
            start = newnode;
            if (newnode->next == NULL) {
                last = newnode;  // Update last if it was the only element
            }
        } else {
            // Traverse the list to find the appropriate position
            ListNode *current = start;
            while (current->next != NULL && current->next->data < value) {
                current = current->next;
            }

            // Insert new node after current node
            newnode->next = current->next;
            current->next = newnode;

            // Update the last pointer if new node is placed at the end
            if (newnode->next == NULL) {
                last = newnode;
            }
        }
    }

    void Delete(int value) {
    ListNode* loc = start;
    ListNode* ploc = NULL;

    if (Search(value)) {
        // Traverse the list to find the node to delete
        while (loc != NULL && loc->data != value) {
            ploc = loc;
            loc = loc->next;
        }

        // If the value is not found
        if (loc == NULL) {
            cout << "Value not found in the list." << endl;
            return;
        }

        // If the node to delete is the first node
        if (ploc == NULL) {
            start = loc->next;
        } else {
            ploc->next = loc->next;
        }

        // If the node to delete is the last node, update last pointer
        if (loc == last) {
            last = ploc;
        }

        // Delete the node and deallocate memory
        delete loc;
        loc = NULL;
        
        cout << "Value deleted from the list and memory deallocated." << endl;
    } else {
        cout << "Value not found in the list." << endl;
    }
}


    void Destroy(){
        ListNode* temp;

        while(start != NULL){
            temp = start;
            start = start->next;
            delete temp;
            
        }
       
        temp = NULL;
        start = NULL;
    }
};
int main() {
    LinkedList list1;
    char choice;
    int value;

    while (true) {
        cout << "\nEnter your function:\n";
        cout << "P = Print list\n";
        cout << "I = Check if the list is empty\n";
        cout << "F = Insert at front\n";
        cout << "E = Insert at end\n";
        cout << "S = Search for a value\n";
        cout << "O = Insert in sorted order\n";
        cout << "D = Delete a value\n";
        cout << "X = Destroy the entire list\n";
        cout << "Q = Quit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 'P':
            case 'p':
                cout << "Current list: ";
                list1.PrintList();
                break;

            case 'I':
            case 'i':
                if (list1.isEmpty()) {
                    cout << "The list is empty." << endl;
                } else {
                    cout << "The list is not empty." << endl;
                }
                break;

            case 'F':
            case 'f':
                cout << "Enter value to insert at front: ";
                cin >> value;
                list1.insertAtFront(value);
                break;

            case 'E':
            case 'e':
                cout << "Enter value to insert at end: ";
                cin >> value;
                list1.insertAtEnd(value);
                break;

            case 'S':
            case 's':
                cout << "Enter value to search for: ";
                cin >> value;
                if (list1.Search(value)) {
                    cout << "Value " << value << " found in the list." << endl;
                } else {
                    cout << "Value " << value << " not found in the list." << endl;
                }
                break;

            case 'O':
            case 'o':
                cout << "Enter value to insert in sorted order: ";
                cin >> value;
                list1.insertInSortedOrder(value);
                break;

            case 'D':
            case 'd':
                cout << "Enter value to delete: ";
                cin >> value;
                list1.Delete(value);
                break;

            case 'X':
            case 'x':
                cout << "Destroying the entire list." << endl;
                list1.Destroy();
                cout << "List destroyed." << endl;
                break;

            case 'Q':
            case 'q':
                cout << "Exiting the program." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

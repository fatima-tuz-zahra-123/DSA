#include <iostream>
using namespace std;

class BST_Node {
public:
    int data;
    BST_Node* LeftChild;
    BST_Node* RightChild;

    BST_Node(int value) {
        this->data = value;
        LeftChild = RightChild = nullptr;
    }
};

class BST {
private:
    BST_Node* root;

public:
    BST() {
        root = nullptr;
    }

    bool IsEmpty() {
        return root == nullptr;
    }

    void Search(int value, BST_Node*& loc, BST_Node*& ploc) {
        loc = root;
        ploc = nullptr;
        
        while (loc != nullptr) {
            if (value == loc->data) {
                return;
            } else {
                ploc = loc;
                loc = (value < loc->data) ? loc->LeftChild : loc->RightChild;
            }
        }
    }

    void InsertWithoutDuplication(int value) {
        BST_Node *loc, *ploc;
        Search(value, loc, ploc);

        if (loc != nullptr) {
            cout << "Value " << value << " already exists. Duplicate insertion is not allowed." << endl;
            return;
        }

        BST_Node* newNode = new BST_Node(value);

        if (ploc == nullptr) {
            root = newNode;  // Tree is empty
        } else if (value < ploc->data) {
            ploc->LeftChild = newNode;
        } else {
            ploc->RightChild = newNode;
        }
    }

    void PreOrderTraversal(BST_Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            PreOrderTraversal(node->LeftChild);
            PreOrderTraversal(node->RightChild);
        }
    }

    void InOrderTraversal(BST_Node* node) {
        if (node != nullptr) {
            InOrderTraversal(node->LeftChild);
            cout << node->data << " ";
            InOrderTraversal(node->RightChild);
        }
    }

    void PostOrderTraversal(BST_Node* node) {
        if (node != nullptr) {
            PostOrderTraversal(node->LeftChild);
            PostOrderTraversal(node->RightChild);
            cout << node->data << " ";
        }
    }

    void PrintSmallest() {
        if (IsEmpty()) {
            cout << "Tree is empty." << endl;
            return;
        }
        BST_Node* current = root;
        while (current->LeftChild != nullptr) {
            current = current->LeftChild;
        }
        cout << "Smallest value: " << current->data << endl;
    }

    void PrintLargest() {
        if (IsEmpty()) {
            cout << "Tree is empty." << endl;
            return;
        }
        BST_Node* current = root;
        while (current->RightChild != nullptr) {
            current = current->RightChild;
        }
        cout << "Largest value: " << current->data << endl;
    }

    void PrintLeafNodes(BST_Node* node) {
        if (node != nullptr) {
            if (node->LeftChild == nullptr && node->RightChild == nullptr) {
                cout << node->data << " ";
            } else {
                PrintLeafNodes(node->LeftChild);
                PrintLeafNodes(node->RightChild);
            }
        }
    }

    int CountLeafNodes(BST_Node* node) {
        if (node == nullptr) return 0;
        if (node->LeftChild == nullptr && node->RightChild == nullptr) return 1;
        return CountLeafNodes(node->LeftChild) + CountLeafNodes(node->RightChild);
    }

    int CountInternalNodes(BST_Node* node) {
        if (node == nullptr || (node->LeftChild == nullptr && node->RightChild == nullptr)) return 0;
        return 1 + CountInternalNodes(node->LeftChild) + CountInternalNodes(node->RightChild);
    }

    // Wrapper functions for traversals and counting
    void PreOrder() { PreOrderTraversal(root); }
    void InOrder() { InOrderTraversal(root); }
    void PostOrder() { PostOrderTraversal(root); }

    void DisplayLeafNodes() {
        cout << "Leaf nodes: ";
        PrintLeafNodes(root);
        cout << endl;
    }

    int GetLeafNodeCount() {
        return CountLeafNodes(root);
    }

    int GetInternalNodeCount() {
        return CountInternalNodes(root);
    }
};

int main() {
    BST tree;
    
    // Testing insertions
    tree.InsertWithoutDuplication(10);
    tree.InsertWithoutDuplication(5);
    tree.InsertWithoutDuplication(20);
    tree.InsertWithoutDuplication(3);
    tree.InsertWithoutDuplication(7);
    tree.InsertWithoutDuplication(15);
    tree.InsertWithoutDuplication(30);

    cout << "Tree is empty: " << tree.IsEmpty() << endl;

    // Testing traversals
    cout << "InOrder Traversal: ";
    tree.InOrder();
    cout << endl;

    cout << "PreOrder Traversal: ";
    tree.PreOrder();
    cout << endl;

    cout << "PostOrder Traversal: ";
    tree.PostOrder();
    cout << endl;

    // Testing smallest and largest values
    tree.PrintSmallest();
    tree.PrintLargest();

    // Testing leaf nodes
    tree.DisplayLeafNodes();
    cout << "Number of leaf nodes: " << tree.GetLeafNodeCount() << endl;

    // Testing internal nodes
    cout << "Number of internal nodes: " << tree.GetInternalNodeCount() << endl;

    return 0;
}

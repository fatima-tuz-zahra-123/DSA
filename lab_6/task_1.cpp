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

    bool Search(int value, BST_Node*& loc, BST_Node*& ploc) {
        loc = root;
        ploc = nullptr;
        
        while (loc != nullptr) {
            if (value == loc->data) {
                return true;
            } else {
                ploc = loc;
                loc = (value < loc->data) ? loc->LeftChild : loc->RightChild;
            }
        }
        return false;
        
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
    void PreOrder() {if(root != nullptr) PreOrderTraversal(root);else cout << "the tree is empty" <<endl; }
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

    //lab7 task1
    BST_Node* DeleteNode(int key){
        //if root is a nullptr or tree is empty
        if(root == nullptr){ 
            cout<< "No Nodes In The Tree"<<endl;
            return root;
        }
        
        BST_Node *loc, *ploc;
        Search(key,loc, ploc);
      
        
        if(loc != nullptr)
        {
            //case: leaf node
            if (loc->LeftChild == nullptr && loc->RightChild == nullptr) 
            {
                if (ploc != nullptr) 
                {
                    if (ploc->LeftChild == loc) ploc->LeftChild = nullptr;
                    else ploc->RightChild = nullptr;
                } 
                else 
                {
                    root = nullptr; 
                }
            }
        
            //case 2: one child
            else if(loc->LeftChild == nullptr|| loc->RightChild == nullptr)
            {
                BST_Node* child = loc->LeftChild? loc->LeftChild : loc->RightChild;
                if (ploc->LeftChild == loc)
                    ploc->LeftChild = child;
                else ploc->RightChild = child;
                
            }
            else
            {
                // case 3: two children
                BST_Node *predecessor = loc->LeftChild;
                BST_Node *predecessorParent = loc;
                while (predecessor->RightChild != nullptr)
                {
                predecessorParent = predecessor;
                predecessor = predecessor->RightChild;
                }
                
                loc->data = predecessor->data;
                if (ploc == nullptr)
                {
                    loc->data = predecessor->data;
                    loc->LeftChild = predecessor->LeftChild;
                }
                else if (predecessorParent->RightChild == predecessor)
                    predecessorParent->RightChild = predecessor->LeftChild;
                else
                    predecessorParent->LeftChild = predecessor->LeftChild;

                delete predecessor;

                
            }
        }
        return loc;
    }

    BST_Node* TreeDeletion(BST_Node* node)
    {
        if (node != nullptr) 
        {
            TreeDeletion(node->LeftChild);
            TreeDeletion(node->RightChild);
            delete node;
        }
        return node;
    }
    
    //wrapper function
    BST_Node* DeleteTree()
    {
        TreeDeletion(root);
        root = nullptr;
        return root;
    }

    void LeafNodeDeletion() { DeleteLeafNodes(root); }

    void DeleteLeafNodes(BST_Node * node)
    {
        BST_Node *loc = node;
        if (node != nullptr) {
            if (loc->LeftChild != nullptr && loc->LeftChild->LeftChild == nullptr && loc->LeftChild->RightChild == nullptr) 
                loc->LeftChild = nullptr;
            else DeleteLeafNodes(node->LeftChild);
            if (loc->RightChild != nullptr && loc->RightChild->LeftChild == nullptr && loc->RightChild->RightChild == nullptr)
                loc->RightChild = nullptr;
            else DeleteLeafNodes(node->RightChild);
            
            
        }

    }

    void LeftSubTreeNodeDeletion(){ DeleteNodeWithLeftSubtree(root);}

    void DeleteNodeWithLeftSubtree(BST_Node *node)
    {
        BST_Node *loc = node;
        if (node != nullptr) {
            if (loc->LeftChild == nullptr && loc->RightChild != nullptr) 
                loc->LeftChild = nullptr;
            else DeleteLeafNodes(node->LeftChild);
            if (loc->RightChild != nullptr && loc->RightChild->LeftChild == nullptr && loc->RightChild->RightChild == nullptr)
                loc->RightChild = nullptr;
            else DeleteLeafNodes(node->RightChild);

        }
    }
//wrapper function
    void countNodeTypes(int &leafCount, int &leftOnlyCount, int &rightOnlyCount, int &twoChildrenCount) {
        countNodeTypesRec(root, leafCount, leftOnlyCount, rightOnlyCount, twoChildrenCount);
    }

    void countNodeTypesRec(BST_Node* node, int &leafCount, int &leftOnlyCount, int &rightOnlyCount, int &twoChildrenCount) {
        if (node == nullptr) return;
        if (node->LeftChild == nullptr && node->RightChild == nullptr) {
            leafCount++;
        }
        else if (node->LeftChild != nullptr && node->RightChild == nullptr) {
            leftOnlyCount++;
        }
        else if (node->LeftChild == nullptr && node->RightChild != nullptr) {
            rightOnlyCount++;
        }
        else {
            twoChildrenCount++;
        }
        countNodeTypesRec(node->LeftChild, leafCount, leftOnlyCount, rightOnlyCount, twoChildrenCount);
        countNodeTypesRec(node->RightChild, leafCount, leftOnlyCount, rightOnlyCount, twoChildrenCount);
    }
};

int main() {
    BST tree;
    
    // Testing insertions
    tree.InsertWithoutDuplication(10);
    tree.InsertWithoutDuplication(5);
    tree.InsertWithoutDuplication(20);
    tree.InsertWithoutDuplication(3);
    tree.InsertWithoutDuplication(1);
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
    tree.DeleteNode(10);
    cout << "Post Node deletion PreOrder Traversal: ";
    tree.PreOrder();
    cout << endl;

    // tree.DeleteTree();
    // cout << "PreOrder Traversal: ";
    // tree.PreOrder();
    // cout << endl;
    
    // tree.LeafNodeDeletion();
    // cout << "Post leaf node deletion PreOrder Traversal: ";
    // tree.PreOrder();
    // cout << endl;

    int leafCount = 0;
    int leftOnlyCount = 0;
    int rightOnlyCount = 0;
    int twoChildrenCount = 0;

    tree.countNodeTypes(leafCount, leftOnlyCount, rightOnlyCount, twoChildrenCount);
    cout << "Leaf nodes: " << leafCount << endl;
    cout << "Left only nodes: " << leftOnlyCount << endl;
    cout << "Right only nodes: " << rightOnlyCount << endl;
    cout << "Two children nodes: " << twoChildrenCount << endl;


    tree.LeftSubTreeNodeDeletion();
    cout << "Post left subtree node deletion PreOrder Traversal: ";
    tree.PreOrder();
    cout << endl;



    return 0;
}

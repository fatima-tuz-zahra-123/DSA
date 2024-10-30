#include <iostream>
#include "/workspaces/DSA/lab_6/task_1.cpp"
using namespace std;

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

    return 0;
}

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

// HuffmanNode structure
struct HuffmanNode {
    char character;
    int frequency;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char c, int f) : character(c), frequency(f), left(nullptr), right(nullptr) {}
};

// MinHeap class
class MinHeap {
private:
    vector<HuffmanNode*> heap;

    void bubbleUp(int index) {
        while (index > 0 && heap[index]->frequency < heap[(index - 1) / 2]->frequency) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void buildMinHeap() {
        for (int i = heap.size() / 2 - 1; i >= 0; i--)
            heapify(i);
    }

    void heapify(int index) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heap.size() && heap[left]->frequency < heap[smallest]->frequency)
            smallest = left;

        if (right < heap.size() && heap[right]->frequency < heap[smallest]->frequency)
            smallest = right;

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapify(smallest);
        }
    }

public:
    MinHeap() {}

    void sortIntoMinHeap() {
        buildMinHeap();
    }

    void printHeap() {
        if (heap.empty()) {
            cout << "Nothing to print" << endl;
        } else {
            for (HuffmanNode* node : heap) {
                cout << node->character << " (" << node->frequency << ") ";
            }
            cout << endl;
        }
    }

    HuffmanNode* top() {
        return heap.empty() ? nullptr : heap[0];
    }

    bool isEmpty() {
        return heap.empty();
    }

    int getSize() {
        return heap.size();
    }

    HuffmanNode* pop() {
        if (this->isEmpty()) {
            cout << "Heap is empty" << endl;
            return nullptr;
        }

        HuffmanNode* topNode = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);

        return topNode;
    }

    void push(HuffmanNode* value) {
        heap.push_back(value);
        bubbleUp(heap.size() - 1);
    }
};

int main() {
    // Create a few HuffmanNode objects with characters and frequencies
    HuffmanNode* node1 = new HuffmanNode('a', 7);
    HuffmanNode* node2 = new HuffmanNode('b', 2);
    HuffmanNode* node3 = new HuffmanNode('c', 4);
    HuffmanNode* node4 = new HuffmanNode('d', 6);
    HuffmanNode* node5 = new HuffmanNode('e', 2);
    HuffmanNode* node6 = new HuffmanNode('f', 9);

    // Initialize the MinHeap and push nodes into it
    MinHeap kabaar;
    kabaar.push(node1);
    kabaar.push(node2);
    kabaar.push(node3);
    kabaar.push(node4);
    kabaar.push(node5);
    kabaar.push(node6);

    // Print the heap
    cout << "Initial Heap:" << endl;
    kabaar.printHeap();

    // Check if the heap is empty
    if (kabaar.isEmpty()) {
        cout << "Heap is empty" << endl;
    } else {
        cout << "Heap is not empty" << endl;
    }

    // Print the top element of the heap
    HuffmanNode* topNode = kabaar.top();
    if (topNode) {
        cout << "Top of Heap: Character = " << topNode->character 
             << ", Frequency = " << topNode->frequency << endl;
    }

    // Remove the top element and print the heap again
    kabaar.pop();
    cout << "Heap after popping the top element:" << endl;
    kabaar.printHeap();

    // Push a new node into the heap
    HuffmanNode* newNode = new HuffmanNode('g', 3);
    kabaar.push(newNode);
    cout << "Heap after pushing a new element:" << endl;
    kabaar.printHeap();

    // Clean up memory
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    delete node6;
    delete newNode;

    return 0;
}

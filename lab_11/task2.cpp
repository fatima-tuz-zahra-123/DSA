#include <iostream>
#include <string>
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

// Function to build Huffman Tree using MinHeap
HuffmanNode* buildHuffmanTree(const unordered_map<char, int>& frequencyTable) {
    MinHeap minHeap;

    // Push all characters as leaf nodes into the MinHeap
    for (const auto& entry : frequencyTable) {
        HuffmanNode* node = new HuffmanNode(entry.first, entry.second);
        minHeap.push(node);
    }

    // Build the tree
    while (minHeap.getSize() > 1) {
        HuffmanNode* left = minHeap.pop();
        HuffmanNode* right = minHeap.pop();

        // Create a new internal node with the sum of frequencies
        HuffmanNode* combined = new HuffmanNode('\0', left->frequency + right->frequency);
        combined->left = left;
        combined->right = right;

        // Push the combined node back into the heap
        minHeap.push(combined);
    }

    return minHeap.pop(); // Root node of the Huffman Tree
}

// Function to generate Huffman codes recursively
void generateCodes(HuffmanNode* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (!root) return;

    // If it's a leaf node, assign the code
    if (!root->left && !root->right) {
        huffmanCodes[root->character] = code;
    }

    generateCodes(root->left, code + "0", huffmanCodes);
    generateCodes(root->right, code + "1", huffmanCodes);
}

// Function to encode a string using Huffman codes
string encode(const string& input, const unordered_map<char, string>& huffmanCodes) {
    string encodedString;
    for (char c : input) {
        encodedString += huffmanCodes.at(c);
    }
    return encodedString;
}

// Function to decode an encoded string using the Huffman Tree
string decode(const string& encoded, HuffmanNode* root) {
    string decodedString;
    HuffmanNode* current = root;

    for (char bit : encoded) {
        if (bit == '0') {
            current = current->left;
        } else {
            current = current->right;
        }

        // If a leaf node is reached, append the character
        if (!current->left && !current->right) {
            decodedString += current->character;
            current = root; // Reset to root for the next sequence
        }
    }

    return decodedString;
}

int main() {
    string input = "hello world";

    // Task 1: Build frequency table
    unordered_map<char, int> frequencyTable;
    for (char c : input) {
        frequencyTable[c]++;
    }

    // Build the Huffman Tree
    HuffmanNode* root = buildHuffmanTree(frequencyTable);

    // Generate Huffman codes
    unordered_map<char, string> huffmanCodes;
    generateCodes(root, "", huffmanCodes);

    // Display the Huffman codes
    cout << "Huffman Codes:\n";
    for (const auto& entry : huffmanCodes) {
        cout << entry.first << ": " << entry.second << endl;
    }

    // Task 2: Encode the input string
    string encodedString = encode(input, huffmanCodes);
    cout << "\nEncoded String: " << encodedString << endl;

    // Decode the encoded string
    string decodedString = decode(encodedString, root);
    cout << "Decoded String: " << decodedString << endl;

    // Task 3: Compression analysis
    cout << "\nCompression Analysis:" << endl;
    int originalBits = input.size() * 8; // Each character is 8 bits
    int compressedBits = encodedString.size(); // Each bit in the encoded string
    cout << "Original size (bits): " << originalBits << endl;
    cout << "Compressed size (bits): " << compressedBits << endl;
    cout << "Compression Ratio: " << static_cast<double>(compressedBits) / originalBits << endl;

    // Clean up memory
    delete root; // Delete the root node to free memory for the tree

    return 0;
}

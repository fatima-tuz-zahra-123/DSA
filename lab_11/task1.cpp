#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

struct HuffmanNode {
    char character;
    int frequency;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char c, int f) : character(c), frequency(f), left(nullptr), right(nullptr) {}
};


struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->frequency > b->frequency; // MinHeap based on frequency
    }
};

// Function to generate Huffman codes
void generateCodes(HuffmanNode* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (!root) return;

    if (root->character != '\0') {
        huffmanCodes[root->character] = code;
    }

    generateCodes(root->left, code + "0", huffmanCodes);
    generateCodes(root->right, code + "1", huffmanCodes);
}

// Function to construct the Huffman Tree
HuffmanNode* buildHuffmanTree(const string& input, unordered_map<char, int>& frequencyTable) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> minHeap;

    // Populate the min-heap with all characters and their frequencies
    for (auto& pair : frequencyTable) {
        minHeap.push(new HuffmanNode(pair.first, pair.second));
    }

    // Build the Huffman Tree
    while (minHeap.size() > 1) {
        HuffmanNode* left = minHeap.top(); minHeap.pop();
        HuffmanNode* right = minHeap.top(); minHeap.pop();

        HuffmanNode* newNode = new HuffmanNode('\0', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;

        minHeap.push(newNode);
    }

    return minHeap.top();
}

// Function to encode the input string
string encode(const string& input, const unordered_map<char, string>& huffmanCodes) {
    string encodedString;
    for (char c : input) {
        encodedString += huffmanCodes.at(c);
    }
    return encodedString;
}

// Function to decode the encoded string
string decode(const string& encodedString, HuffmanNode* root) {
    string decodedString;
    HuffmanNode* current = root;

    for (char bit : encodedString) {
        current = (bit == '0') ? current->left : current->right;

        if (!current->left && !current->right) { // Leaf node
            decodedString += current->character;
            current = root;
        }
    }

    return decodedString;
}

void calculateCompressionRatio(const string& input, const string& encodedString) {
    int originalSize = input.size() * 8; // Each character is 8 bits
    int encodedSize = encodedString.size(); // Each bit is 1 bit

    double compressionRatio = (double)encodedSize / originalSize;

    cout << "\nOriginal Size (bits): " << originalSize;
    cout << "\nEncoded Size (bits): " << encodedSize;
    cout << "\nCompression Ratio: " << compressionRatio << endl;
}

int main() {
    string input = "hello world";

    // Step 1: Calculate the frequency of each character
    unordered_map<char, int> frequencyTable;
    for (char c : input) {
        frequencyTable[c]++;
    }

    // Step 2: Build the Huffman Tree
    HuffmanNode* root = buildHuffmanTree(input, frequencyTable);

    // Step 3: Generate Huffman codes
    unordered_map<char, string> huffmanCodes;
    generateCodes(root, "", huffmanCodes);

    // Print the Huffman codes
    cout << "Character\tFrequency\tHuffman Code" << endl;
    for (auto& pair : huffmanCodes) {
        cout << pair.first << "\t\t" << frequencyTable[pair.first] << "\t\t" << pair.second << endl;
    }

    // Step 4: Encode the input string
    string encodedString = encode(input, huffmanCodes);
    cout << "\nEncoded String: " << encodedString << endl;

    // Step 5: Decode the encoded string
    string decodedString = decode(encodedString, root);
    cout << "Decoded String: " << decodedString << endl;

    // Step 6: Compression analysis
    calculateCompressionRatio(input, encodedString);

    return 0;
}

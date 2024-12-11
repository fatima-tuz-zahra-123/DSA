#include <iostream>
using namespace std;

class hashTable {
private:
    int *array;
    int size;

public:
    // Constructor
    hashTable(int size) {
        this->size = size;
        this->array = new int[size];
        std::fill(array, array + size, -1); 
    }

    // Insert key-value pair
    void insert(int key, int value) {
        if (key >= 0 && key < size) {
            array[key] = value;
        } else {
            cout << "Error: Key out of bounds!" << endl;
        }
    }

    // Search value by key
    int search(int key) {
        if (key >= 0 && key < size) {
            return array[key];
        } else {
            cout << "Error: Key out of bounds!" << endl;
            return -1;
        }
    }

    // Delete key-value pair
    void deleting(int key) {
        if (key >= 0 && key < size) {
            array[key] = -1; // Set the slot to -1 to mark it as deleted
        } else {
            cout << "Error: Key out of bounds!" << endl;
        }
    }

   
    void printArray() {
        for (int i = 0; i < size; i++) {
            cout << "Key: " << i << ", Value: " << array[i] << endl;
        }
    }

    //without deallocating this, an error shows up
    ~hashTable() {
        delete[] array; 
    }
};


struct KeyValuePair {
    int key;
    int value;

    KeyValuePair(int key, int value) {
        this->key = key;
        this->value = value;
    }
};

int main() {
    hashTable table(6); 

    table.insert(1, 2);
    table.insert(3, 2);
    table.insert(4, 6);

   
    cout << "Hash Table Contents:" << endl;
    table.printArray();

    // Search for a value
    cout << "\nSearching for key 3: " << table.search(3) << endl;

    // Delete a key-value pair
    table.deleting(3);
    cout << "\nAfter deleting key 3:" << endl;
    table.printArray();

    return 0;
}

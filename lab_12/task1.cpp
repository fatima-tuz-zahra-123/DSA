#include <iostream>
#include <chrono>  

using namespace std;
using namespace std::chrono;

class hashTable{
private:
    int *array;
    int size;

public:

    // Constructor to initialise the table with a size
    hashTable(int size){
        this->size = size;
        this->array = new int[size];
        std::fill(array, array+size, -1);

    }
    void insert(int key, int value){
        if(key >=0 && key < size){
            array[key] = value;
        }
        else{
            cout << "Error: Key out of bound" << endl;
        }
    }

    int search(int key){
        auto start = high_resolution_clock::now(); // Start time
        
        if( key >= 0 && key < size){
            auto end = high_resolution_clock::now(); // End time
            auto duration = duration_cast<nanoseconds>(end - start).count(); // Calculate duration
            cout << "Search function took " << duration << " nanoseconds" << endl;
            return array[key];
        } else{
            cout << "Error: Key out of bound" << endl;
            return -1;
        }
    }

    void deleting(int key){
         if (key >= 0 && key < size) {
            array[key] = -1; // -1 means deleted
        } else {
            cout << "Error: Key out of bounds!" << endl;
        }
    }
    void printArray() {
        for (int i = 0; i < size; i++) {
        cout << "Key: " << i << ", Value: " << array[i] << endl;
        }
    }
};

struct KeyValuePair{
    int key;
    int value;

    KeyValuePair(int key, int value){
        this->key = key;
        this->value = value;
    }
};
int main(){
    
    hashTable table = hashTable(7);
    KeyValuePair ky1(1,2);
    KeyValuePair ky2(3,2);
    KeyValuePair ky3(6,3);

    table.insert(ky1.key, ky1.value);
    table.insert(ky2.key, ky2.value);
    table.insert(ky3.key, ky3.value);
    
    // table.printArray();
    cout << "Table after inserting" << endl;
    table.printArray();

    //delete a node and see the table
    table.deleting(3);
    cout << "\nTable after deleting" << endl;
    table.printArray();

    //try searchinf a value using a key
    int value = table.search(6);
    cout << "\nValue ofkey 6 is: " << endl;
    cout << value << endl;

}



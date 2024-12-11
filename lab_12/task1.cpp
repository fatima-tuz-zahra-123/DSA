#include <iostream>
using namespace std;

class hashTable{
    private:
        int *array;
        int size;

        public:
            hashTable(int size){
                this->size = size;
                this->array = new int[size];
                std::fill(array, array+size, -1);

            }
            void insert(int key, int value){
                array[key] = value;
            }

            int seacrh(int key){
                return array[key];
            }

            void deleting(int key){
                array[size] = -1;
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
    KeyValuePair ky3(6,6);

    table.insert(ky1.key, ky1.value);
    table.insert(ky2.key, ky2.value);
    table.insert(ky3.key, ky3.value);
    
    // table.printArray();
    table.printArray();

}

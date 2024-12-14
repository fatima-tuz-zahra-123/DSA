#include <iostream>
#include <utility> // For std::pair
#include <chrono>  
using namespace std;
using namespace std::chrono;

enum ProbingMethod { LINEAR, QUADRATIC, DOUBLE_HASHING };

class hashTable {
private:
    pair<int, int> *array; // Pair to store <key, value>
    int size;
    ProbingMethod probingMethod;

    // Hash function
    int hashFunction(int key) {
        return key % size;
    }

    // Second hash function for double hashing
    int secondHashFunction(int key) {
        return 1 + (key % (size - 1));
    }

public:
    hashTable(int size, ProbingMethod method) {
        this->size = size;
        this->probingMethod = method;
        this->array = new pair<int, int>[size];
        for (int i = 0; i < size; i++) {
            array[i] = make_pair(-1, -1); // Initialize as empty
        }
    }

    int insert(int key, int value) {
        auto start = high_resolution_clock::now(); // Start time

        int hash = hashFunction(key);
        int i = 0;
        int step = 1;
        while (array[(hash + i * step) % size].first != -1) {   //search until a free slot is found
            if (probingMethod == LINEAR) {
                step = 1;
            } else if (probingMethod == QUADRATIC) {
                step = i * i;
            } else if (probingMethod == DOUBLE_HASHING) {
                step = i * secondHashFunction(key);
            }
            i++;
            if (i == size) {
                cout << "Error: Hash table is full" << endl;
                return 0;
            }
        }
        array[(hash + i * step) % size] = make_pair(key, value);

        auto end = high_resolution_clock::now(); // End time
        auto duration = duration_cast<nanoseconds>(end - start).count(); // Calculate duration
        cout << "Insert function took " << duration << " nanoseconds" << endl;
        return duration;
    }

    int search(int key) {
        auto start = high_resolution_clock::now(); // Start time

        int hash = hashFunction(key);
        int i = 0;
        int step = 1;
        while (array[(hash + i * step) % size].first != -1) {
            if (array[(hash + i * step) % size].first == key) {
                auto end = high_resolution_clock::now(); // End time
                auto duration = duration_cast<nanoseconds>(end - start).count(); // Calculate duration
                cout << "search function took " << duration << " nanoseconds" << endl;
                return array[(hash + i * step) % size].second;
            }
            if (probingMethod == LINEAR) {
                step = 1;
            } else if (probingMethod == QUADRATIC) {
                step = i * i;
            } else if (probingMethod == DOUBLE_HASHING) {
                step = i * secondHashFunction(key);
            }
            i++;
            if (i == size) {
                break;
            }
        }
        cout << "Error: Key not found" << endl;
        return -1;
    }

    void deleting(int key) {
        auto start = high_resolution_clock::now(); // Start time

        int hash = hashFunction(key);
        int i = 0;
        int step = 1;
        while (array[(hash + i * step) % size].first != -1) {
            if (array[(hash + i * step) % size].first == key) {
                array[(hash + i * step) % size] = make_pair(-1, -1); // Mark as deleted
                auto end = high_resolution_clock::now(); // End time
                auto duration = duration_cast<nanoseconds>(end - start).count(); // Calculate duration
                cout << "Delete function took " << duration << " nanoseconds" << endl;
                return;
            }
            if (probingMethod == LINEAR) {
                step = 1;
            } else if (probingMethod == QUADRATIC) {
                step = i * i;
            } else if (probingMethod == DOUBLE_HASHING) {
                step = i * secondHashFunction(key);
            }
            i++;
            if (i == size) {
                break;
            }
        }
        cout << "Error: Key not found" << endl;
    }

    void printArray() {
        for (int i = 0; i < size; i++) {
            if (array[i].first != -1) {
                cout << "Key: " << array[i].first << ", Value: " << array[i].second << endl;
            } else {
                cout << "Key: " << i << ", Value: empty" << endl;
            }
        }
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
    // Choose probing method: LINEAR, QUADRATIC, or DOUBLE_HASHING
    ProbingMethod method = DOUBLE_HASHING;
    hashTable table(7, method);
    cout << "Probing method: " << method << endl;

    KeyValuePair ky1(1, 2);
    KeyValuePair ky2(3, 2);
    KeyValuePair ky3(8, 3);
    KeyValuePair ky4(10, 4);
    KeyValuePair ky5(17, 5);
    KeyValuePair ky6(20, 6);
    KeyValuePair ky7(24, 7);

    int total_duration = 0;
    total_duration += table.insert(ky1.key, ky1.value);
    total_duration += table.insert(ky2.key, ky2.value);
    total_duration += table.insert(ky3.key, ky3.value);
    total_duration += table.insert(ky4.key, ky4.value);
    total_duration += table.insert(ky5.key, ky5.value);
    total_duration += table.insert(ky6.key, ky6.value);
    total_duration += table.insert(ky7.key, ky7.value);

    cout << "\nTotal duration of insertions: " << total_duration << " nanonseconds" << endl;

    cout << "Table after inserting" << endl;
    table.printArray();

    // Delete a node and see the table
    table.deleting(3);
    cout << "\nTable after deleting" << endl;
    table.printArray();

    // Try searching for a value using a key
    int value = table.search(1);
    cout << "\nValue of key 1 is: " << endl;
    if(value != -1) cout << value << endl;
    else cout << "Key not found" << endl;

    return 0;
}
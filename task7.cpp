#include <iostream>
using namespace std;

vector<int> find_all_indices(vector<int> array, int key) {

    //initialise the vector and the array length
    vector<int> indices;
    int n = array.size();
    
    //if array is empty this loop won't work
    // iterate through the loop to search for the indices of the given element
    for (int i = 0; i < n; i++){
        if (array[i] == key && n != 0){
            // hanldes multiple occurences by adding all of them to the vector
            indices.push_back(i);

        }
    }
    return indices;
}

int main() {
    vector<int> nums = {1, 2, 3, 2, 5};

    // Case 1: multiple occurences
    vector<int> list1 = find_all_indices(nums, 2);
    cout << "Case 1: multiple occurences \n";
    cout << "The indices for key=2 are: ";
    for (int index : list1) cout << index << " ";cout << endl;


    // Case 2: key not present
    vector<int> list2 = find_all_indices(nums, 4);
    cout << "Case 2: key not present \n";
    cout << "The indices for key=4 are: ";
    for (int index : list2) cout << index << " ";cout << endl;

    // Case 3: array empty
    vector<int> num_empty = {};
    vector<int> list3 = find_all_indices(num_empty, 4);
    cout << "Case 3: array empty \n";
    cout << "The indices for key=4 are: ";
    for (int index : list2) cout << index << " ";cout << endl;
}


#include <iostream>
#include <vector>
#include "task7.cpp" 
using namespace std;

int main() {
    vector<int> nums = {1, 2, 3, 2, 5};

    // Case 1: multiple occurrences
    vector<int> list1 = find_all_indices(nums, 2);
    cout << "Case 1: multiple occurrences \n";
    cout << "The indices for key=2 are: ";
    for (int index : list1) cout << index << " "; cout << endl;

    // Case 2: key not present
    vector<int> list2 = find_all_indices(nums, 4);
    cout << "Case 2: key not present \n";
    cout << "The indices for key=4 are: ";
    for (int index : list2) cout << index << " "; cout << endl;

    // Case 3: array empty
    vector<int> num_empty = {};
    vector<int> list3 = find_all_indices(num_empty, 4);
    cout << "Case 3: array empty \n";
    cout << "The indices for key=4 are: ";
    for (int index : list3) cout << index << " "; cout << endl; // Fixed typo to print list3 instead of list2

    return 0;
}
#include <iostream>
using namespace std;

int multipltyMatrixStatic() {
    int matrix[5][4] = {
        {2, 4, 5, 7},
        {5, 3, 1, 3},
        {3, 7, 2, 1},
        {4, 5, 2, 7},
        {3, 7, 2, 4}
    };

    int vector[4][1] = {
        {3},
        {4},
        {1},
        {7}
    };

    // Result vector to store the multiplication result
    int result[5][1] = {0}; 
    int multipliedValue = 0;

    // Matrix-vector multiplication
    for (int i = 0; i < 5; i++) {
        multipliedValue = 0;  // Reset for each row
        for (int j = 0; j < 4; j++) {
            multipliedValue += matrix[i][j] * vector[j][0];  // Multiplying matrix row by vector column
        }
        result[i][0] = multipliedValue;  
    }

   
    cout << "Result vector:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << result[i][0] << endl;  // Print the result vector
    }

    return 0;
}

int main() {
    multipltyMatrixStatic();  // Call the function
    return 0;
}

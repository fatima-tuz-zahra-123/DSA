#include <iostream>

int main(){
// declare a variable fro user input
int size;
// ask user input
std :: cout << "Enter size of array: ";
//store user input
std :: cin >> size;

// initialise dynamic memory pointer
int *x = new int[size];  
//iterate through the structure and fill it up
for (int i = 0; i < size; i++)
{
    x[i] = i + 1;
std :: cout << "x[" << i << "] = "<< x[i] << std :: endl;
}

// free memory by deleting the pointer
delete x;
std :: cout << "memory freed" << std :: endl;

}
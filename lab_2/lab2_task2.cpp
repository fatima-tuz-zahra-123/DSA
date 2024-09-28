#include <iostream>

int main(){
// declare a variable fro user input
int size;
//declare a variable for sum 
float sum = 0;
// ask user input
std :: cout << "Enter size of array: ";
//store user input
std :: cin >> size;

// initialise dynamic memory pointer
int *x = new int[size];  
//iterate through the structure and fill it up
for (int i = 0; i < size; i++)
{
    std :: cout << "Enter your number "<< i+1 <<":" << std :: endl;
    std :: cin >> *x;
    //store the value in a variable
    float value = *(x + i);
    // take sum of the values
    sum = sum + value;
    
    

}

//print out the sum and the average values
std :: cout << "the sum of your values is: "<< sum << std :: endl;
std :: cout << "the average of the array elements is: "<< float(sum/size) << std :: endl;

//free memory by deleting the pointer
delete x;
std :: cout << "memory freed" << std :: endl;

}
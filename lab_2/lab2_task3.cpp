#include <iostream>
using namespace std;

int main() {
    int x = 4; 
    int* ptr = nullptr;  // Pointer initialized to nullptr

    for (int i = 0; i < 2; i++) //iterates both the cases
    {
        //add check for null pointer 
        if (ptr != NULL)
        {
            //runs if the pointer is not null
            cout << "Value pointed by ptr: " << *ptr << endl;  
        }
        else{
            //runs if the pointer is null
            std :: cout << "the pointer is nullptr" << std :: endl;
        }
        // changes the ptr to x(not null)
        ptr = &x;
    }
    return 0;
}

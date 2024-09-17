#include <iostream>
int main() {

    int list[5]={3,6,9,12,15};
	int *pArr= list;

    for (int i = 0; i<5; i++){
        //using the pointer to print the values
        std::cout << *pArr << std::endl;
        pArr++;//incrementing to get the next value
    }
    return 0;
}
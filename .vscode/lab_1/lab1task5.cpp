#include <iostream>

void swapA(int* pa, int* pb) { //function to swap by pointers
    int holdp;   
    holdp = *pa;  
    *pa = *pb;   
    *pb = holdp; 
    return;
}

void swapB(int** ppa, int** ppb){ //function to swap by pointer to pointer
    int holdpp;  
    holdpp = **ppa;
    **ppa = **ppb;
    **ppb = holdpp;
    return;
}

int main() {
     int a=5, b=10; 
	int *pa=&a; //pa and pb are pointer variables of type int. 
	int *pb=&b;
	
	int **ppa=&pa; //ppa and ppb are called double pointers or pointers-to-pointers.
	int **ppb=&pb;
    
    std::cout << "Before swap(a): " << *pa << " " << *pb << std::endl;

    swapA(pa, pb);   

    std::cout << "After swap(a): " << *pa << " " << *pb << std::endl;

    swapB(ppa, ppb);

    std::cout << "After swap(b): " << *pa << " " << *pb << std::endl;
 
    return 0;
}

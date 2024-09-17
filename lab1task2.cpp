#include <iostream>  

int main()
{
    int a, *pa;  
    pa = &a;     
    
    std::cout << "pa = &a --> pa = " << pa << std::endl << std::endl;
    
    pa = pa*3
}

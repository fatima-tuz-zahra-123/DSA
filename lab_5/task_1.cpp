#include <iostream>
using namespace std;

class Stack {
public:
    int top = -1;
    int* items; 
    int size;

    Stack(int size){
        this->size = size;
        items = new int[size];
    }

    void Push(int element){
        if (isFull()){
            cout <<"Stack overlow!"<< endl;
            return;
        }
        top++;
        items[top] = element;
        
    }

    void Pop(int element){
        if ( isEmpty()){
            cout << "Stack underflow!" << endl;
            return;
        }
        //cout << items[top] << endl;
        top--;
    }

    bool isEmpty(){
        return top == -1;
    }

    bool isFull(){
        return top == size;
    }

    void Clear(){
        delete items;
        this->items = nullptr;
    }

    void Peak(){
        if (top == -1){
            cout << "The stack is empty." << endl;
        }
        cout << "top of the stack is!: \n" + this->items[top] << endl;
    }


};
bool isOpeningBracket(char x){
    return x == '(' || x == '[' || x =='{';
}
bool isClosingBracket(char x){
    return x == ')' || x == ']' || x =='}';
}
bool isPair(char x, char y){
    if (x == ')'){
        return y == '(';
    }
    else if (x == ']'){
        return y == '[';
    }
    else if (x == '}'){
        return y == '{';
    }
    else{
        return false;
    }
}

main(){
    string expression;
    cout << "Enter the expression" << endl;
    cin >> expression;
    Stack stack = Stack(expression.length());

    int counter = 0;
    bool correct = false;
    while (counter < expression.length()){
        if (isOpeningBracket(expression[counter])){
            stack.Push(expression[counter]);
        }
        else if (isClosingBracket(expression[counter])){
            if (isPair(expression[counter], stack.items[stack.top])){
                correct = true;
                stack.Pop(expression[counter]);
            }
            else{
                correct = false;
            }
        }
        counter++;
    }
    if (stack.top == -1){
        cout << "This expression is correct.";
    }
    else{
        cout << "This expression is NOT correct." << endl;
    }
    
}
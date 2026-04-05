#include <iostream>
#define MAX 100
using namespace std;
int stack[MAX];
int top = -1; 

void push(int value) {
    if (top >= MAX - 1) {
        cout << "Stack overflow" << endl;
    }           
    else {
        top++;
        stack[top] = value;
        cout << value << " pushed into stack" << endl;
    }
}

int pop() {
    if (top < 0) {
        cout << "Stack underflow" << endl;
        return -1;
    }
else {
int value = stack[top];
top--;
return value;
}
}
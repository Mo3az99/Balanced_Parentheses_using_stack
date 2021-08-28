#include <iostream>
#include <stdint.h>
#include <string>
using namespace std;

#define MAX 1000 //max size for stack

class Stack
{
    int top;
public:
    int myStack[MAX]; //stack array

    Stack() { top = -1; }
    void push(uint8_t u8_data);
    uint8_t pull();
    bool isEmpty();
    void printStack();
};
//pushes element on to the stack
void Stack::push(uint8_t u8_data)
{
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow!!!";
        return;
    }
    else {
        myStack[++top] = u8_data;
        //printf("%d \n", u8_data);
        return;
    }
}

//removes or pops elements out of the stack
uint8_t Stack::pull()
{
    if (top < 0) {
        throw  "Stack Underflow!!";
        return 0;
    }
    else {
        uint8_t u8_data = myStack[top--];
        return u8_data;
    }
}

//check if stack is empty
bool Stack::isEmpty()
{
    return (top < 0);
}
void Stack::printStack() {
    if (isEmpty())
    {
        return;
    }
    for (int i = top; i >= 0; i--)
    {
        printf("%d \n", myStack[i]);

    }
}

uint8_t* balancedParentheses(uint8_t* expression) {

    class Stack stack1;
    class Stack stack2;
    uint8_t b[] = "Balanced";
    uint8_t nb[] = "Not Balanced";

    while (*expression != '\0')
    {
        if (*expression == '{')
        {
            stack1.push(0);
        }
        else if (*expression == '}')
        {
            try {
                stack1.pull();
            }
            catch (const char* msg)
            {
                return nb;
            }
        }
        else if (*expression == '(')
        {
            stack2.push(0);
        }
        else if (*expression == ')')
        {
            try {
                stack2.pull();
            }
            catch (const char* msg)
            {
                return nb;
            }
        }

        expression++;
    }

    if (stack1.isEmpty() && stack2.isEmpty())



        return b;
    else
    {
        return nb;

    }
}


int main()
{
    /* test 1
    class Stack stack;
    cout << "The Stack Push " << endl;
    stack.push(2);
    stack.push(4);
    stack.push(6);
    stack.printStack();
    cout << "The Stack Pop : " << endl;
    while (!stack.isEmpty())
    {
        printf("%d \n", stack.pull());
    }*/



    cout << "{}\t" << balancedParentheses((uint8_t*)("{}")) << endl;

    cout << "()\t" << balancedParentheses((uint8_t*)("()")) << endl;

    cout << "{1+(2/5)+2}\t" << balancedParentheses((uint8_t*)("{1+(2/5)+2}")) << endl;

    cout << "(2*3+(5/2+(4*3)))\t" << balancedParentheses((uint8_t*)("(2*3+(5/2+(4*3)))")) << endl;

    cout << "{({2+10}}*11}\t" << balancedParentheses((uint8_t*)("{({2+10}}*11}")) << endl;



    return 0;
}

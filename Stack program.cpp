#include<iostream>
using namespace std;
int top=-1;
void push(int stack[],int x,int n)
{
    if(top==n-1)
    {
        cout<<"stack is full "<<endl;
    }
    else
    {
        top=top+1;
        stack[top]=x;
    }
}
void pop()
{
    if(top==-1)
    {
        cout<<"underflow "<<endl;
    }
    else
    {
        top=top-1;
    }
}
int size()
{
    return top+1;
}
int topElement(int stack[])
{
    return stack[top];
}
int main()
{
    int stack[3];
    push(stack,5,3);
    cout<<"current size is "<<size()<<endl;
    push(stack,6,3);
    push(stack,7,3);
    cout<<"current size is "<<size()<<endl;
    push(stack,8,3);
    cout<<"current size is "<<size()<<endl;
    cout << "The current top element in stack is " << topElement(stack) << endl;
    for(int i=0;i<3;i++)
    {
        pop();
    cout << "The current top element in stack is " << topElement(stack) << endl;
    }
    pop();
}

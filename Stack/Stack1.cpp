#include<bits/stdc++.h>
#include<iostream>
#include<conio.h>
using namespace std;

#define M 5
int STACK[M];
int top = -1;

void push(int i)
{
    if(top==M-1)
    {
        cout<<"Stack Overflow"<<endl;
        return;
    }
    top++;
    STACK[top] = i;
}

int pop()
{
    if(top <= -1)
    {
        cout<<"\nStack Underflow"<<endl;
        return top;
    }
    int i = STACK[top--];
    return i;
}

void peep()
{
    if(top <= -1)
    {
        cout<<"\nEmpty Stack";
        return;
    }
    cout<<"        [";
    for (int i = 0; i <= top; i++)
    {
        cout<<STACK[i]<<"[";
    }
    cout<<endl;
}

int main()
{
push(1);
push(2);
push(3);
push(4);
push(5);
peep();
push(6);
peep();
cout<<pop();
peep();
cout<<pop();
peep();
cout<<pop();
peep();
cout<<pop();
peep();
cout<<pop();
peep();
cout<<pop();
peep();
/**
        [1[2[3[4[5[
Stack Overflow
        [1[2[3[4[5[
5        [1[2[3[4[
4        [1[2[3[
3        [1[2[
2        [1[
1
Empty Stack
Stack Underflow
-1
Empty Stack
 * 
 */


getch();
return 0;
}
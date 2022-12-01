#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        d = data;
        next = NULL;
    }
};

class Stack
{
public:
    Node *head;
    int s;
    Stack()
    {
        head = NULL;
        s = 0;
    }
    void push(int x)
    {
        Node *temp = new Node(x);
        temp->next = head;
        head = temp;
        s++;
    }
    int pop()
    {
        if (head == NULL)
            return INT_MAX;
        int res = head->data;
        Node *temp = head;
        head = head->next;
        free(temp);
        s--;
        return res;
    }
    int size()
    {
        return s;
    }
    bool isEmpty()
    {
        if (head == NULL)
            return true;
    }
    int peek()
    {
        if (head == NULL)
            return INT_MAX;
        return head->data;
    }
};

int main()
{
    

    return 0;
}
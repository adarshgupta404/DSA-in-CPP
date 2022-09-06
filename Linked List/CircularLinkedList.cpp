#include<bits/stdc++.h>
#include<iostream>
#include<conio.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        Node(int d)
        {
            this->data = d;
            this->next = NULL;
        }
        ~Node()
        {
            int val = this->data;
            if (next != NULL)
            {
                delete next;
                next = NULL;
            }
            cout << "Memory free for node with data " << val << endl;
        }
};
int main()
{


getch();
return 0;
}

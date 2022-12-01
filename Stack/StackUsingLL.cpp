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
        this->data = d;
        this->next = NULL;
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
        if (isEmpty())
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
        else
            return false;
    }
    int peek()
    {
        if (isEmpty())
            return INT_MAX;
        return head->data;
    }
    void display()
    {
        Node* temp = head;
        while (temp!=NULL)
        {
            cout<<"["<<temp->data<<"]"<<"-->";
            temp = temp->next;
        }
        cout<<"[NULL]";
    }
};

int main()
{
    Stack s;
    int d;
    while (true)
    {
        int a;
        cout << "LINKED LIST MENU" << endl
             << "1.CREATE" << endl
             << "2.DISPLAY" << endl
             << "3.PUSH" << endl
             << "4.POP" << endl
             << "5.SIZE" << endl
             << "6.PEEK" << endl
             << "Any key-EXIT" << endl;
        printf("Enter your choice: ");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("Enter number of Nodes: ");
            int n;
            scanf("%d", &n);
            int x;
            printf("Enter elements in Nodes: ");
            for (int i = 0; i < n; i++)
            {
                cin>>x;
                s.push(x);
            }
            s.display();
            break;
        case 2:
            s.display();
            break;
        case 3:
            cin>>d;
            s.push(d);
            s.display();
            break;
        case 4:
            cout<<s.pop()<<endl;
            s.display();
            break;
        case 5:
            cout<<s.size();
            break;
        case 6:
            cout<<s.peek();
            break;
        default:
            goto end;
        }
        cout<<endl;
    }
end:
    cout << endl;
    

    return 0;
}
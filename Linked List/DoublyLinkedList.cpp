#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int d)
    {
        this->data = d;
        prev = NULL;
        next = NULL;
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

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << "[" << temp->data << "]--->";
        temp = temp->next;
    }
}

int getLength(Node *head)
{
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    cout << "\nNumber of Nodes present in Doubly Linked list is " << len << ".\n";
    return len;
}

void InsertAtTail(Node *&tail, Node *&head)
{
    if (tail == NULL)
    {
        cout << "Insert at Tail: ";
        int d;
        cin >> d;
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        int d;
        cin >> d;
        Node *temp = new Node(d);
        tail->next = temp;
        tail->prev = tail;
        tail = temp;
    }
}

void InsertAtHead(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "Empty list!\n";
        cout << "Insert at Head: ";
        int d;
        cin >> d;
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        int d;
        cin >> d;
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void InsertAtPos(Node *&head, Node *&tail)
{
    int pos;
    cout << "Enter the postion you want to insert : ";
    cin >> pos;

    if (pos == 1)
    {
        InsertAtHead(head, tail);
        return;
    }

    int cnt = 1;
    Node *temp = head;
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL)
    {
        InsertAtTail(tail, head);
        return;
    }

    int d;
    cout << "Enter the element : ";
    cin >> d;
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void deleteNode(Node *&head)
{
    int pos;
    cout << "Enter the postion to be deleted: ";
    cin >> pos;
    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *prev = NULL;
        Node *curr = head;
        int cnt = 2;
        while (cnt <= pos)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    Node *node1 = NULL;
    Node *head = node1;
    Node *tail = node1;
    while (true)
    {
        char a;
        cout << "\nLINKED LIST MENU" << endl
             << "1.CREATE" << endl
             << "2.DISPLAY" << endl
             << "3.INSERT_END" << endl
             << "4.INSERT_BEGINNING" << endl
             << "5.INSERT BETWEEN" << endl
             << "6.DELETE" << endl
             << "7.NO OF NODES" << endl
             << "Any key-EXIT" << endl;
        printf("Enter your choice: ");
        cin >> a;
        switch (a)
        {
        case '1':
            printf("Enter number of Nodes: ");
            int n;
            scanf("%d", &n);
            for (int i = 1; i < n; i++)
            {
                InsertAtTail(tail, head);
            }
            break;
        case '2':
            display(head);
            break;
        case '3':
            InsertAtTail(tail, head);
            break;
        case '4':
            InsertAtHead(head, tail);
            break;
        case '5':
            InsertAtPos(head, tail);
            break;
        case '6':
            deleteNode(head);
            break;
        case '7':
            cout << "No of Nodes in the linked list is " << getLength(head) << "." << endl;
            break;
        default:
            goto end;
        }
    }
end:
    cout << endl;
    getch();
    return 0;
}
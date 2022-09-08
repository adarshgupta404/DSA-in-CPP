#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>
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
    //~Node();
};

void InsertAtHead(Node *&tail)
{
    int d;
    cin >> d;
    Node *temp = new Node(d);
    temp->next = tail->next;
    tail->next = temp;
}

void InsertAtTail(Node *&tail)
{
    int d;
    cin >> d;
    Node *newNode = new Node(d);
    newNode->data = d;
    newNode->next = tail->next;
    tail->next = newNode;
    tail= newNode;
}

void addEmpty(Node*& tail, int data)
{
    Node* newNode = new Node(data);
    newNode->data = data;
    tail = newNode;
    tail->next = tail;
}

void createList(Node* &tail)
{
    printf("Enter the number of nodes you want to insert: ");
    int n;
    scanf("%d", &n);
    if (n == 0)
        return;
    printf("Enter the data at 1: ");
    int d;
    scanf("%d", &d);
    addEmpty(tail,d);
    for (int i = 1; i < n; i++)
    {
        InsertAtTail(tail);
    }
}

void display(Node *&tail)
{
    if (tail == NULL) {
        printf("The list is empty");
        return;
    }
    Node* temp = tail->next;
    do{
        printf("[%d]--->",temp->data);
        temp = temp->next;
    }while(temp != tail->next);
    printf("\n");
}

void InsertAtPos(Node *&tail)
{
    int pos,d;
    if (pos == 1)
    {
        InsertAtHead(tail);
        return;
    }

    printf("\nEnter the position you want: ");
    scanf("%d", &pos);
    printf("\nEnter the data you want at position %d: ",pos);
    scanf("%d", &d);
    Node* p = tail;
    Node* newNode = new Node(d);
    while (pos>1)
    {
        p = p->next;
        pos--;
    }
    newNode->next = p->next;
    p->next = newNode;
    if(p == tail) 
        tail =  tail->next; 
}

int No_of_Nodes(Node *&tail)
{
    int cnt = 1;
    Node *temp = tail->next;
    while (temp != tail)
    {
        cnt++; 
        temp = temp->next;
    }
    return cnt;
}


void delete_firstNode(Node* &tail)
{
    Node* temp = tail->next;
    tail->next = temp->next;
    free(temp);
    temp = NULL;
}

void delete_lastNode(Node* &tail)
{
    Node* temp = tail->next;
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    temp->next = tail->next;
    free(tail);
    tail = temp;
}

void delete_intermediate(Node* &tail)
{
    int pos;
    printf("\nEnter the position you want to delete: ");
    scanf("%d", &pos);
    if(pos == 1)
    {
        delete_firstNode(tail);
        return;
    }    
    
    int l = No_of_Nodes(tail);
    if(pos==l)
    {
        delete_lastNode(tail);
        return;
    }
    
    Node* temp = tail->next;
    while (pos>2)  
    {
        temp = temp->next;
        pos--;
    }
    Node* temp2 = temp->next;
    temp->next = temp2->next;
    if(temp2 == tail)
        tail = temp;
    free(temp2);
    temp2 = NULL;
}

void search(Node *&tail, int d)
{
    Node *p = tail->next;
    int cnt = 0;

    do
    {
        cnt++;
        if (p->data == d)
        {
            printf("%d is present at postion %d.\n", d, cnt);
            return;
        }
        p = p->next;
    }while (p != tail->next);
    cout << "Not Present.\n";
}


void reverse(Node *&tail)
{
    Node* currN, *prevN, *nextN;
    currN = tail->next;
    nextN = currN->next;
    while (currN!=tail)
    {
        prevN = currN;
        currN = nextN;
        nextN = currN->next;
        currN->next = prevN;
    }
    nextN->next = tail;
    tail = nextN;
}

int main()
{
    int d;
    Node *node1 = NULL;
    Node *tail = node1;
    cout << "LINKED LIST MENU" << endl
             << "1.CREATE" << endl
             << "2.DISPLAY" << endl
             << "3.INSERT_ENDING" << endl
             << "4.INSERT_BEGINNING" << endl
             << "5.INSERT BETWEEN" << endl
             << "6.DELETE_BEGINNING" << endl
             << "7.DELETE_ENDING" << endl
             << "8.DELETE_INTERMEDIATE" << endl
             << "9.NO. OF NODES" << endl
             << "10.REVERSE" << endl
             << "11.NO OF NODES" << endl
             << "Any key-EXIT" << endl;
    while (true)
    {
        int a;
        printf("Enter your choice: ");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            createList(tail);
            break;
        case 2:
            display(tail);
            break;
        case 3:
            InsertAtTail(tail);
            display(tail);
            break;
        case 4:
            InsertAtHead(tail);
            display(tail);
            break;
        case 5:
            InsertAtPos(tail);
            display(tail);
            break;
        case 6:
            delete_firstNode(tail);
            display(tail);
            break;
        case 7:
            delete_lastNode(tail);
            display(tail);
            break;
        case 8:
            delete_intermediate(tail);
            display(tail);
            break;
        case 9:
            cout << "Number of Nodes in the linked list is " << No_of_Nodes(tail) << "." << endl;
            break;
        case 10:
            cout<<"After Reversing: ";
            reverse(tail);
            display(tail);
            break;
        case 11:
            cout << "Enter the element to be searched: ";
            int num;
            cin >> num;
            search(tail, num);
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
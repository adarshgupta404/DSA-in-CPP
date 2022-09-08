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
/*
void InsertAtPos(Node *&tail, int pos)
{
    if (pos == 1)
    {
        InsertAtHead(head);
        return;
    }

    int cnt = 1;
    Node *temp = head;
    while (cnt < pos)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL)
    {
        InsertAtTail(tail);
        return;
    }
    int d;
    cin >> d;
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}
*/
void deleteNode(Node *&head, int pos)
{
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
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void search(Node *&head, int d)
{
    Node *p = head;
    int cnt = 0;
    while (p != NULL)
    {
        cnt++;
        if (p->data == d)
        {
            printf("%d is present at postion %d.\n", d, cnt);
            return;
        }
        p = p->next;
    }
    cout << "\nNot Present.\n";
}

void sort(Node *head)
{
    Node *current = head, *index = NULL;
    int temp;
    if (head == NULL)
    {
        return;
    }
    else
    {
        while (current != NULL)
        {
            // index points to the node next to current
            index = current->next;

            while (index != NULL)
            {
                if (current->data > index->data)
                {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

void reverse(Node *&head)
{
    Node *before = NULL;
    Node *after = NULL;
    while (head != NULL)
    {
        after = head->next;
        head->next = before;
        before = head;
        head = after;
    }
    head = before;
}

int No_of_Nodes(Node *&head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

int main()
{
    int d;
    Node *node1 = NULL;
    Node *tail = node1;
    cout << "LINKED LIST MENU" << endl
             << "1.CREATE" << endl
             << "2.DISPLAY" << endl
             << "3.INSERT_END" << endl
             << "4.INSERT_BEGINNING" << endl
             << "5.INSERT BETWEEN" << endl
             << "6.DELETE" << endl
             << "7.SEARCH" << endl
             << "8.SORT" << endl
             << "9.REVERSE" << endl
             << "10.NO OF NODES" << endl
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
            break;
        case 4:
            InsertAtHead(tail);
            break;
       /* case 5:
            int loc;
            printf("Enter the location to insert node: ");
            scanf("%d", &loc);
            InsertAtPos(tail, loc);
            break;
        case 6:
            printf("Enter the position of element to be delete: ");
            int pos;
            scanf("%d", &pos);
            deleteNode(head, pos);
            break;
        /*case 7:
            cout << "Enter the element to be searched: ";
            int num;
            cin >> num;
            search(head, num);
            break;
        case 8:
            sort(head);
            display(head);
            break;
        case 9:
            reverse(head);
            display(head);
            break;
        case 10:
            cout << "No of Nodes in the linked list is " << No_of_Nodes(head) << "." << endl;
            break;*/
        default:
            goto end;
        }
    }
end:
    cout << endl;
    getch();
    return 0;
}
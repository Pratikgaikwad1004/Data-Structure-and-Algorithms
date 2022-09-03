#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    if (newnode == NULL)
    {
        cout << "Queue is full." << endl;
    }
    else
    {
        if (front == NULL && rear == NULL)
        {
            front = newnode;
            rear = newnode;
            newnode->next = NULL;
        }
        else
        {
            newnode->next = NULL;
            rear->next = newnode;
            rear = newnode;
        }
    }
}

void dequeue()
{
    if (front == NULL && rear == NULL)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        struct Node *ptr = front;
        int n = ptr->data;
        front = front->next;
        free(ptr);
        cout << n << " is deleted." << endl;
    }
}

void display()
{
    if (front == NULL && rear == NULL && front == rear)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        struct Node *ptr = front;
        cout << "Queue elements - ";
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }
}

int main()
{
    int i = 0;
    do
    {
        int ch, a;
        cout << "\n\n"
             << endl;
        cout << "1. Enqueue." << endl;
        cout << "2. Display." << endl;
        cout << "3. Dequeue." << endl;
        cout << "0. Exit." << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter element - ";
            cin >> a;
            enqueue(a);
            break;
        case 2:
            display();
            break;
        case 3:
            dequeue();
            break;
        case 0:
            i = 1;
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    } while (i == 0);

    return 0;
}
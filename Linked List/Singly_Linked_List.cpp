#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void create_linked_list(int data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = head;
    head = newnode;
}

struct Node *insert_at_first(int data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = head;
    head = newnode;
    cout << "Element inserted." << endl;
    return head;
}

struct Node *insert_at_last(int data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    struct Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newnode;
    newnode->next = NULL;
    return head;
}

struct Node *insert_at_index(int data, int index)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    struct Node *p = head;
    struct Node *q = head->next;
    int i = 1;
    while (i < index)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    newnode->next = q;
    p->next = newnode;
    return head;
}

void display()
{
    struct Node *ptr = head;
    cout << "Elements - ";
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

int main()
{
    int i = 0;
    do
    {
        int ch, a, b;
        cout << "\n \n";
        cout << "1. Create linked list." << endl;
        cout << "2. Display linked list." << endl;
        cout << "3. Insert at first." << endl;
        cout << "4. Insert at last." << endl;
        cout << "5. Insert at index." << endl;
        cout << "0. Exit." << endl;
        cin >> ch;
        switch (ch)
        {
        case 0:
            i = 1;
            break;
        case 1:
            cout << "Enter how many elements you want to insert - " << endl;
            cin >> b;
            for (int i = 0; i < b; i++)
            {
                cout << "Enter element - " << endl;
                cin >> a;
                create_linked_list(a);
            }
            cout << "Linked list created." << endl;
            break;
        case 2:
            display();
            break;
        case 3:
            cout << "Enter element - " << endl;
            cin >> a;
            insert_at_first(a);
            break;
        case 4:
            cout << "Enter element - " << endl;
            cin >> a;
            insert_at_last(a);
            break;
        case 5:
            cout << "Enter element - " << endl;
            cin >> a;
            cout << "Enter index - " << endl;
            cin >> b;
            insert_at_index(a, b);
            break;
        default:
            cout << "Invalid Input.";
            break;
        }
    } while (i == 0);

    return 0;
}
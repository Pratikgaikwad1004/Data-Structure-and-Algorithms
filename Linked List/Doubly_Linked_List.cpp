#include <iostream>
using namespace std;

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *create_linked_list(int data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = head;
    if (head != NULL)
    {
        head->prev = newnode;
        head = newnode;
    }
    head = newnode;
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

struct Node *insert_at_first(int data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = head;
    newnode->prev = NULL;
    head = newnode;
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
    newnode->prev = ptr;
    newnode->next = NULL;
    return head;
}

struct Node *insert_at_index(int data, int index)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    struct Node *ptr = head;
    int i = 1;
    while (i < index)
    {
        ptr = ptr->next;
        i++;
    }
    newnode->next = ptr->next;
    ptr->next = newnode;
    newnode->prev = ptr;
    return head;
}

struct Node *delete_first_node()
{
    struct Node *ptr = head;
    head = head->next;
    head->prev = NULL;
    cout << ptr->data << " is deleted." << endl;
    free(ptr);
    return head;
}

struct Node *delete_last_node()
{
    struct Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->prev->next = NULL;
    cout << ptr->data << " is deleted." << endl;
    free(ptr);
    return head;
}

struct Node *delete_at_index(int index)
{
    struct Node *ptr = head;
    int i = 0;
    while (i < index)
    {
        ptr = ptr->next;
        i++;
    }
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    cout << ptr->data << " is deleted." << endl;
    free(ptr);
    return head;
}

void search(int data)
{
    struct Node *ptr = head;
    int i = 0;
    bool element = false;
    while (ptr != NULL)
    {
        if (ptr->data == data)
        {
            element = true;
            break;
        }
        ptr = ptr->next;
        i++;
    }
    if (element)
    {
        cout << data << " found at index " << i << endl;
    }
    else
    {
        cout << data << " is not found." << endl;
    }
}

int main()
{
    int i = 0;
    do
    {
        int ch, a, b;
        cout << "\n\n"
             << endl;
        cout << "1. Create linked list." << endl;
        cout << "2. Display linked list." << endl;
        cout << "3. Insert at first." << endl;
        cout << "4. Insert at last." << endl;
        cout << "5. Insert at index." << endl;
        cout << "6. Delete first node." << endl;
        cout << "7. Delete last node." << endl;
        cout << "8. Delete at index." << endl;
        cout << "9. Search in linked list." << endl;
        cout << "0. Exit." << endl;
        cin >> ch;
        switch (ch)
        {
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
        case 6:
            delete_first_node();
            break;
        case 7:
            delete_last_node();
            break;
        case 8:
            cout << "Enter index - " << endl;
            cin >> b;
            delete_at_index(b);
            break;
        case 9:
            cout << "Enter element - " << endl;
            cin >> a;
            search(a);
            break;
        case 0:
            i = 1;
            break;
        default:
            cout << "Invalid input." << endl;
            break;
        }
    } while (i == 0);

    return 0;
}
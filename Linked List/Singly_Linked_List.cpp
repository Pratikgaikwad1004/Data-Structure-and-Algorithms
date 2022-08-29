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
    cout << data << " inserted at first." << endl;
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
    cout << data << " inserted at last." << endl;
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
    cout << data << " inserted at index. " << index << endl;
    return head;
}

struct Node *delete_first_node()
{
    struct Node *ptr = head;
    head = ptr->next;
    cout << ptr->data << " is deleted. " << endl;
    free(ptr);
    return head;
}

struct Node *delete_last_node()
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    cout << q->data << " is deleted.";
    free(q);
    return head;
}

struct Node *delete_at_index(int index)
{
    int i = 1;
    struct Node *p = head;
    struct Node *q = head->next;
    while (i < index)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    cout << q->data << " is deleted." << endl;
    free(q);
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
        cout << data << " Not found." << endl;
    }
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
        cout << "6. Delete first node." << endl;
        cout << "7. Delete last node." << endl;
        cout << "8. Delete at index." << endl;
        cout << "9. Search in linked list." << endl;
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
        case 6:
            delete_first_node();
            break;
        case 7:
            delete_last_node();
            break;
        case 8:
            cout << "Enter index - " << endl;
            cin >> a;
            delete_at_index(a);
            break;
        case 9:
            cout << "Enter element you want to search - " << endl;
            cin >> a;
            search(a);
            break;
        default:
            cout << "Invalid Input.";
            break;
        }
    } while (i == 0);

    return 0;
}
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *create_linked_list(int data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = head;
    struct Node *ptr = head;
    if (head != NULL)
    {
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }
    else
    {
        newnode->next = newnode;
    }
    head = newnode;
    return head;
}

void display()
{
    struct Node *ptr = head;
    cout << "Elements - ";
    do
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != head);
}

struct Node *insert_at_first(int data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    struct Node *ptr = head;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = newnode;
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
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = newnode;
    newnode->next = head;
    cout << data << " inserted at last." << endl;
    return head;
}

struct Node *insert_at_index(int data, int index)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    int i = 1;
    struct Node *p = head;
    struct Node *q = head->next;
    while (i < index)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = newnode;
    newnode->next = q;
    return head;
}

struct Node *delete_first_node()
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != head)
    {
        q = q->next;
    }
    q->next = head->next;
    head = head->next;
    cout << p->data << " is deleted." << endl;
    free(p);
    return head;
}

struct Node *delete_last_node()
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != head)
    {
        p = p->next;
        q = q->next;
    }
    p->next = head;
    cout << q->data << " is deleted." << endl;
    free(q);
    return head;
}

void search(int data)
{
    struct Node *ptr = head;
    bool element = false;
    int i = 0;
    do
    {
        if (ptr->data == data)
        {
            element = true;
            break;
        }

        ptr = ptr->next;
        i++;
    } while (ptr != head);
    if (element)
    {
        cout << data << " found at index " << i << endl;
    }
    else
    {
        cout << data << " Not found." << endl;
    }
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

int main()
{
    int i = 0;
    do
    {
        int ch, a, b;
        cout << "\n \n"
             << endl;
        cout << "1. Create linked list." << endl;
        cout << "2. Display." << endl;
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
            cin >> a;
            delete_at_index(a);
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
            cout << "Invalid choice." << endl;
            break;
        }
    } while (i == 0);

    return 0;
}
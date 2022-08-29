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

void display()
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
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

            break;
        case 2:
            display();
            break;
        default:
            cout << "Invalid Input.";
            break;
        }
    } while (i == 0);

    return 0;
}
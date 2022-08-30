#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

int isFull()
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        cout << "\nStack is full." << endl;
        return true;
    }
    else
    {
        return false;
    }
}

int isEmpty()
{
    if (top == NULL)
    {
        cout << "\nStack is empty." << endl;
        return true;
    }
    else
    {
        return false;
    }
}

struct Node *push(int data)
{
    if (isFull())
    {
        cout << "\nStack Overflow." << endl;
    }
    else
    {
        struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr->data = data;
        ptr->next = top;
        top = ptr;
    }
    return top;
}

struct Node *pop()
{
    if (isEmpty())
    {
        cout << "\nStack Underflow." << endl;
    }
    else
    {
        struct Node *ptr = top;
        top = top->next;
        free(ptr);
        cout << "\nElement deleted." << endl;
    }
    return top;
}

void topEle()
{
    cout << "\n"
         << top->data << endl;
}

void display()
{
    struct Node *ptr = top;
    cout << "\nStack elements - ";
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

void peak(int data)
{
    struct Node *ptr = top;
    bool element = false;
    int i = 0;
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
        cout << "\n"
             << data << " is found at index " << i << endl;
    }
    else
    {
        cout << "\n"
             << data << " not found." << endl;
    }
}

int main()
{
    int i = 0;
    do
    {
        int ch, a;
        cout << "\n \n"
             << endl;
        cout << "1. Push." << endl;
        cout << "2. Display." << endl;
        cout << "3. Pop." << endl;
        cout << "4. isEmpty." << endl;
        cout << "5. isFull." << endl;
        cout << "6. Peak." << endl;
        cout << "7. Top." << endl;
        cout << "0. Exit." << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter element - " << endl;
            cin >> a;
            push(a);
            break;
        case 2:
            display();
            break;
        case 3:
            pop();
            break;
        case 4:
            isEmpty();
            break;
        case 5:
            isFull();
            break;
        case 6:
            cout << "Enter element - " << endl;
            cin >> a;
            peak(a);
            break;
        case 7:
            topEle();
            break;
        case 0:
            i = 1;
            break;

        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (i == 0);

    return 0;
}
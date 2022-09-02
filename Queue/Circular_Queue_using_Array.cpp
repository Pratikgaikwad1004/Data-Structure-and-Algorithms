#include <iostream>
using namespace std;

struct Array
{
    int total_size;
    int front;
    int rear;
    int *ptr;
};

struct Array *arr = NULL;

struct Array *create_queue(int t_size)
{
    struct Array *p = (struct Array *)malloc(sizeof(struct Array));
    p->total_size = t_size;
    p->rear = 0;
    p->front = 0;
    p->ptr = (int *)malloc(t_size * sizeof(int));
    arr = p;
    cout << "\nEmpty queue initialized." << endl;
    return arr;
}

int isEmpty()
{
    if (arr->front == arr->rear)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int isFull()
{
    if ((arr->rear + 1) % arr->total_size == arr->front)
    {
        return true;
    }
    else
    {
        return false;
    }
}

struct Array *enqueue(int data)
{
    if (isFull())
    {
        cout << "Queue is full." << endl;
    }
    else
    {
        arr->rear = (arr->rear + 1) % arr->total_size;
        arr->ptr[arr->rear] = data;
        cout << arr->ptr[arr->rear] << " is inserted." << endl;
    }
    return arr;
}

struct Array *dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty." << endl;
    }
    else
    {
        arr->front = (arr->front + 1) % arr->total_size;
        cout << arr->ptr[arr->front] << " is deleted." << endl;
    }
    return arr;
}

int main()
{
    int i = 0;
    do
    {
        int ch, a;
        cout << "\n \n"
             << endl;
        cout << "1. Create queue." << endl;
        cout << "2. Enqueue." << endl;
        cout << "3. Dequeue." << endl;
        cout << "0. Exit." << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter size of queue - " << endl;
            cin >> a;
            create_queue(a);
            break;
        case 2:
            cout << "Enter element - " << endl;
            cin >> a;
            enqueue(a);
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
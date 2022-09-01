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
    p->rear = -1;
    p->front = -1;
    p->ptr = (int *)malloc(t_size * sizeof(int));
    arr = p;
    cout << "\nEmpty queue initialized." << endl;
    return arr;
}

struct Array *enqueue(int data)
{
    if (arr->rear == arr->total_size - 1)
    {
        cout << "Queue is full." << endl;
    }
    else
    {
        int i = arr->rear + 1;
        arr->ptr[i] = data;
        arr->rear += 1;
        cout << arr->ptr[i] << " is inserted." << endl;
    }
    return arr;
}

struct Array *dequeue()
{
    if (arr->front == arr->rear)
    {
        cout << "Queue is empty." << endl;
    }
    else
    {
        int i = arr->front + 1;
        arr->ptr[i] == '\0';
        arr->front += 1;
    }
    return arr;
}

void display()
{
    if (arr->front == arr->rear)
    {
        cout << "Queue is empty." << endl;
    }
    else
    {
        int i = arr->front + 1;
        cout << "Queue elements - ";
        while (i < arr->rear + 1)
        {
            cout << arr->ptr[i] << " ";
            i++;
        }
    }
    cout << "\nfront and rear is - " << arr->front << arr->rear << endl;
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
        cout << "4. Display." << endl;
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
        case 4:
            display();
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
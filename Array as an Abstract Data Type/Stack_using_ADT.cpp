#include <iostream>
using namespace std;

struct my_array
{
    /* data */
    int total_size;
    int use_size;
    int *ptr;
};
struct my_array *arr = NULL;
struct my_array *create_stack(int t_size)
{
    struct my_array *p = (struct my_array *)malloc(sizeof(struct my_array));
    p->total_size = t_size;
    p->use_size = 0;
    p->ptr = (int *)malloc(t_size * sizeof(int));
    arr = p;
    cout << "\nEmpty stack initialized." << endl;
    return arr;
}

struct my_array *push(int data)
{
    if (arr->use_size >= arr->total_size)
    {
        cout << "\nStack is full." << endl;
    }
    else
    {
        int i = arr->use_size;
        arr->ptr[i] = data;
        cout << data << " inserted at index " << i << endl;
        arr->use_size += 1;
    }
    return arr;
}

struct my_array *pop()
{
    if (arr->use_size == 0)
    {
        cout << "\nStack is empty." << endl;
    }
    else
    {
        int i = arr->use_size - 1;
        arr->ptr[i] = arr->ptr[i + 1];
        arr->use_size -= 1;
        cout << "\nElement deleted" << endl;
    }
    return arr;
}

void peak(int index)
{
    if (index > arr->use_size - 1)
    {
        cout << "\nStack has only " << arr->use_size - 1 << " index." << endl;
    }
    else
    {
        cout << "\n"
             << arr->ptr[index] << endl;
        cout << arr->use_size;
    }
}

void top()
{
    int i = arr->use_size - 1;
    cout << "\n"
         << arr->ptr[i] << endl;
}

void show()
{
    if (arr->use_size == 0)
    {
        cout << "\nStack is empty." << endl;
    }
    else
    {
        cout << "\nStack Elements - ";
        for (int i = 0; i < arr->use_size; i++)
        {
            cout << arr->ptr[i] << " ";
        }
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
        cout << "1. Create Stack." << endl;
        cout << "2. Display Stack." << endl;
        cout << "3. Push." << endl;
        cout << "4. Pop." << endl;
        cout << "5. Peak." << endl;
        cout << "6. Top." << endl;
        cout << "0. Exit." << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter size - " << endl;
            cin >> a;
            create_stack(a);
            break;
        case 2:
            show();
            break;
        case 3:
            cout << "Enter element - " << endl;
            cin >> a;
            push(a);
            break;
        case 4:
            pop();
            break;
        case 5:
            cout << "Enter index - " << endl;
            cin >> a;
            peak(a);
            break;
        case 6:
            top();
            break;
        case 0:
            i = 1;
            break;
        default:
            cout << "Invalid Input.";
            break;
        }

    } while (i == 0);

    /* code */
    return 0;
}

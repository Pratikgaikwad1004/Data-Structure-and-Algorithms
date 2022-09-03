#include <iostream>
using namespace std;

struct Array
{
    int total_size;
    int use_size;
    int *ptr;
};

struct Array *arr = NULL;

void create_array(int total_size)
{
    struct Array *newarray = (struct Array *)malloc(sizeof(struct Array));
    newarray->total_size = total_size;
    newarray->use_size = 0;
    newarray->ptr = (int *)malloc(total_size * sizeof(int));
    arr = newarray;
}

void push(int data)
{
    if (arr->use_size == arr->total_size)
    {
        cout << "Array is full." << endl;
    }
    else
    {
        arr->ptr[arr->use_size] = data;
        cout << arr->ptr[arr->use_size] << " is inserted." << endl;
        arr->use_size += 1;
    }
}

void insertion_sort()
{
    int val, j;
    for (int i = 1; i <= arr->use_size; i++)
    {
        val = arr->ptr[i];
        j = i - 1;

        while (j >= 0 && arr->ptr[j] > val)
        {
            arr->ptr[j + 1] = arr->ptr[j];
            j--;
        }
        arr->ptr[j + 1] = val;
    }
    cout << "Array sorted using insertion sort." << endl;
}

void display()
{
    int i = 0;
    cout << "Array elements - ";
    while (i < arr->use_size)
    {
        cout << arr->ptr[i] << " ";
        i++;
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
        cout << "1. Create array." << endl;
        cout << "2. Push." << endl;
        cout << "3. Display." << endl;
        cout << "4. Insertion sort." << endl;
        cout << "0. Exit." << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter size - " << endl;
            cin >> a;
            create_array(a);
            break;
        case 2:
            cout << "Enter element - " << endl;
            cin >> a;
            push(a);
            break;
        case 3:
            display();
            break;
        case 4:
            insertion_sort();
            break;
        case 0:
            i = 1;
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    } while (i == 0);
}
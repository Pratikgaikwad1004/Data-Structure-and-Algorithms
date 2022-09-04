#include <iostream>
using namespace std;

struct Array
{
    int total_size;
    int use_size;
    int *ptr;
};

struct Array *arr = NULL;

void create_array(int total_size, int use_size)
{
    struct Array *newarray = (struct Array *)malloc(sizeof(struct Array));
    newarray->total_size = total_size;
    newarray->use_size = use_size;
    newarray->ptr = (int *)malloc(total_size * sizeof(int));
    int data;
    arr = newarray;
    for (int i = 0; i < use_size; i++)
    {
        cout << "Enter " << i << " element - ";
        cin >> data;
        arr->ptr[i] = data;
    }
    cout << "Array created." << endl;
}

void selection_sort()
{
    for (int i = 0; i < arr->use_size; i++)
    {
        int minindex = i;
        int j = i + 1;
        while (j < arr->use_size)
        {
            if (arr->ptr[minindex] > arr->ptr[j])
            {
                minindex = j;
            }
            j++;
        }
        int temp = arr->ptr[i];
        arr->ptr[i] = arr->ptr[minindex];
        arr->ptr[minindex] = temp;
    }
}

void display()
{
    int i = 0;
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
        cout << "2. Display array." << endl;
        cout << "3. Sort array using selection sort." << endl;
        cout << "0. Exit." << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Array size - ";
            cin >> a;
            create_array(a, a);
            break;
        case 2:
            display();
            break;
        case 3:
            selection_sort();
            break;
        case 0:
            i = 1;
            break;
        default:
            cout << "Invalid choice.";
            break;
        }
    } while (i == 0);

    return 0;
}
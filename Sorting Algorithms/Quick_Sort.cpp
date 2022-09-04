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
struct my_array *create_array(int t_size, int u_size)
{
    struct my_array *p = (struct my_array *)malloc(sizeof(struct my_array));
    p->total_size = t_size;
    p->use_size = u_size;
    p->ptr = (int *)malloc(t_size * sizeof(int));
    arr = p;
    int n;
    for (int i = 0; i < arr->use_size; i++)
    {
        cout << "Enter " << i << " element - ";
        cin >> n;
        arr->ptr[i] = n;
    }
    cout << "Array created." << endl;
    return arr;
}

int partition(int low, int high)
{
    int pivot = arr->ptr[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (arr->ptr[i] <= pivot)
        {
            i++;
        }
        while (arr->ptr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = arr->ptr[i];
            arr->ptr[i] = arr->ptr[j];
            arr->ptr[j] = temp;
        }
    } while (i < j);
    temp = arr->ptr[low];
    arr->ptr[low] = arr->ptr[j];
    arr->ptr[j] = temp;
    return j;
}

void quick_sort(int low, int high)
{
    int index;
    if (low < high)
    {
        index = partition(low, high);
        quick_sort(low, index - 1);
        quick_sort(index + 1, high);
    }
}

void show()
{
    cout << "Array Elements - ";
    for (int i = 0; i < arr->use_size; i++)
    {
        cout << arr->ptr[i] << " ";
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
        cout << "3. Sort array using quick sort." << endl;
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
            show();
            break;
        case 3:
            quick_sort(0, arr->use_size - 1);
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
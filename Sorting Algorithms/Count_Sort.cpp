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

void count_sort()
{
    int max = 0;
    for (int i = 0; i < arr->use_size; i++)
    {
        if (max < arr->ptr[i])
        {
            max = arr->ptr[i];
        }
    }
    int *tempArr = (int *)malloc((max + 1) * sizeof(int));

    for (int i = 0; i < max + 1; i++)
    {
        tempArr[i] = 0;
    }

    for (int i = 0; i < arr->use_size; i++)
    {
        tempArr[arr->ptr[i]] = tempArr[arr->ptr[i]] + 1;
    }

    int i = 0, j = 0;
    while (i < max + 1)
    {
        if (tempArr[i] > 0)
        {
            arr->ptr[j] = i;
            tempArr[i] = tempArr[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
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
        cout << "3. Sort array using count sort." << endl;
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
            count_sort();
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
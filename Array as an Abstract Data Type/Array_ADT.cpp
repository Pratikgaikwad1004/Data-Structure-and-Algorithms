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
    return arr;
}

void show()
{
    cout << "Array Elements - ";
    for (int i = 0; i < arr->use_size; i++)
    {
        cout << arr->ptr[i] << " ";
    }
}

struct my_array *set_value()
{
    int n;
    for (int i = 0; i < arr->use_size; i++)
    {
        cout << "Enter Element - " << endl;
        cin >> n;
        arr->ptr[i] = n;
    }
    return arr;
}

struct my_array *insert_at_index(int data, int index)
{
    if (arr->use_size >= arr->total_size)
    {
        cout << "Array is full" << endl;
    }
    else
    {
        for (int i = arr->use_size - 1; i >= index; i--)
        {
            arr->ptr[i + 1] = arr->ptr[i];
        }
        arr->ptr[index] = data;
        arr->use_size += 1;
    }
    return arr;
}

struct my_array *insert_in_sorted(int data)
{
    if (arr->use_size >= arr->total_size)
    {
        cout << "Array is full" << endl;
    }
    else
    {
        for (int i = 0; i < arr->use_size; i++)
        {
            if (arr->ptr[i] > data)
            {
                for (int j = arr->use_size - 1; j >= i; j--)
                {
                    arr->ptr[i + 1] = arr->ptr[i];
                }
                arr->ptr[i] = data;
                arr->use_size += 1;
                break;
            }
        }
    }
    return arr;
}

int main()
{
    int in = 0;
    do
    {
        int ch, a, b;
        cout << "\n \n"
             << endl;
        cout << "1. Create Array." << endl;
        cout << "2. Insert in Array." << endl;
        cout << "3. Display Array." << endl;
        cout << "4. Insert at index." << endl;
        cout << "5. Insert in sorted." << endl;
        cout << "0. Exit." << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter total size of array - " << endl;
            cin >> a;
            cout << "Enter use size of array - " << endl;
            cin >> b;
            create_array(a, b);
            break;
        case 2:
            set_value();
            break;
        case 3:
            show();
            break;
        case 4:
            cout << "Enter element - " << endl;
            cin >> a;
            cout << "Enter index - " << endl;
            cin >> b;
            insert_at_index(a, b);
            break;
        case 5:
            cout << "Enter element - " << endl;
            cin >> a;
            insert_in_sorted(a);
            break;
        case 0:
            in = 1;
            break;
        default:
            cout << "Invalid Choice." << endl;
            break;
        }
    } while (in == 0);

    return 0;
}
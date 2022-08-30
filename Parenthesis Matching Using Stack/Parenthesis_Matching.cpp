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
    }
    return top;
}

int parenthesis_matching(char *exp)
{
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(1);
        }
        else if (exp[i] == ')')
        {
            if (isEmpty())
            {
                return false;
            }
            pop();
        }
    }

    if (isEmpty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    char *exp = "((1+1))";

    if (parenthesis_matching(exp))
    {
        cout << "Parenthesis matched." << endl;
    }
    else
    {
        cout << "Parenthesis not matched." << endl;
    }

    return 0;
}
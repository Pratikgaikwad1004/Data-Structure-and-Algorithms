#include <iostream>
using namespace std;

struct Node
{
    char data;
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

struct Node *push(char data)
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

char pop()
{
    char n;
    if (isEmpty())
    {
        cout << "\nStack Underflow." << endl;
    }
    else
    {
        struct Node *ptr = top;
        top = top->next;
        n = ptr->data;
        free(ptr);
    }
    return n;
}

int match(char a, char b)
{
    if ((a == '{' && b == '}') || (a == '[' && b == ']') || (a == '(' && b == ')'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int parenthesis_matching(char *exp)
{
    char element;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            push(exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (isEmpty())
            {
                return false;
            }
            element = pop();
            if (!match(element, exp[i]))
            {
                return false;
            }
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
    char *exp = "({([1+1])})";

    if (parenthesis_matching(exp))
    {
        cout << "\nParenthesis matched.\n"
             << endl;
    }
    else
    {
        cout << "\nParenthesis not matched.\n"
             << endl;
    }

    return 0;
}
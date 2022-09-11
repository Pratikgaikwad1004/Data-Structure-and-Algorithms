#include <iostream>
using namespace std;

struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
};

struct Node *root = NULL;

struct Node *create_node(int data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    if (root == NULL)
    {
        root = newnode;
        cout << "Root node created." << endl;
    }
    else
    {
        struct Node *ptr = root;
        while (true)
        {
            if (data == ptr->data)
            {
                cout << "Node already exist." << endl;
                break;
            }

            if (data < ptr->data)
            {
                if (ptr->left == NULL)
                {
                    ptr->left = newnode;
                    cout << "Node inserted at left." << endl;
                    break;
                }
                else
                {
                    ptr = ptr->left;
                }
            }
            else
            {
                if (ptr->right == NULL)
                {
                    ptr->right = newnode;
                    cout << "Node inserted at right." << endl;
                    break;
                }
                else
                {
                    ptr = ptr->right;
                }
            }
        }
    }
    return root;
}

void pre_order(struct Node *ptr)
{
    if (ptr != NULL)
    {
        cout << ptr->data << " ";
        pre_order(ptr->left);
        pre_order(ptr->right);
    }
}
void in_order(struct Node *ptr)
{
    if (ptr != NULL)
    {
        in_order(ptr->left);
        cout << ptr->data << " ";
        in_order(ptr->right);
    }
}
void post_order(struct Node *ptr)
{
    if (ptr != NULL)
    {
        post_order(ptr->left);
        post_order(ptr->right);
        cout << ptr->data << " ";
    }
}

int power(int base, int a)
{
    if (a != 0)
        return (base * power(base, a - 1));
    else
        return 1;
}

int get_height(struct Node *ptr)
{
    int height = 0;
    if (ptr != NULL)
    {
        height = 1 + max(get_height(ptr->left), get_height(ptr->right));
    }
    return height;
}

// This is for check tree is BST or Not.
int height = get_height(root);
int i = power(2, height) * 2;
int used_size = 0;
int *arr = (int *)malloc(i * sizeof(int));

void store_inorder(struct Node *ptr)
{
    if (ptr != NULL)
    {
        store_inorder(ptr->left);
        arr[used_size++] = ptr->data;
        store_inorder(ptr->right);
    }
}

void isBST()
{
    store_inorder(root);
    bool bst = true;
    for (int i = 0; i < used_size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            bst = false;
        }
    }
    if (bst)
    {
        cout << "Tree is BST." << endl;
    }
    else
    {
        cout << "Tree is not BST." << endl;
    }
    used_size = 0;
}

// Check Tree is BST or Not code completed.

void search(int data)
{
    struct Node *ptr = root;
    bool found = false;
    while (ptr != NULL)
    {
        if (ptr->data == data)
        {
            found = true;
            break;
        }
        if (data < ptr->data)
        {
            ptr = ptr->left;
        }
        else
        {
            ptr = ptr->right;
        }
    }

    if (found)
    {
        cout << data << " is found." << endl;
    }
    else
    {
        cout << data << " not found." << endl;
    }
}

struct Node *delete_node(int data)
{
    struct Node *prev = NULL;
    struct Node *ptr = root;
    bool found = false;
    if (root->data == data)
    {
        if (ptr->left == NULL)
        {
            root = ptr->right;
        }
        else if (ptr->right == NULL)
        {
            root = ptr->left;
        }
        else
        {
            struct Node *l = ptr->left;
            root = ptr->right;
            struct Node *r = root;
            while (r->left != NULL)
            {
                r = r->left;
            }
            r->left = l;
        }
        return root;
    }
    while (ptr != NULL)
    {
        if (data < ptr->data)
        {
            prev = ptr;
            ptr = ptr->left;
        }
        else
        {
            prev = ptr;
            ptr = ptr->right;
        }
        if (ptr->data == data)
        {
            found = true;
            struct Node *node_to_be_delete = ptr;
            if (node_to_be_delete->left == NULL && node_to_be_delete->right == NULL)
            {
                if (prev->data > node_to_be_delete->data)
                {
                    prev->left = NULL;
                }
                else
                {
                    prev->right = NULL;
                }
                int n = node_to_be_delete->data;
                free(node_to_be_delete);
                cout << n << " is deleted." << endl;
                break;
            }
            else
            {
                struct Node *l = node_to_be_delete->left;
                struct Node *r = node_to_be_delete->right;
                int n = node_to_be_delete->data;
                if (prev->data > node_to_be_delete->data)
                {
                    if (r != NULL)
                    {
                        prev->left = r;
                        while (r->left != NULL)
                        {
                            r = r->left;
                        }
                        r->left = l;
                        free(node_to_be_delete);
                        cout << n << " is deleted." << endl;
                        break;
                    }
                    else
                    {
                        prev->left = l;
                        while (l->right != NULL)
                        {
                            l = l->right;
                        }
                        l->right = r;
                        free(node_to_be_delete);
                        cout << n << " is deleted." << endl;
                        break;
                    }
                }
                else
                {
                    if (r != NULL)
                    {
                        prev->right = r;
                        while (r->left != NULL)
                        {
                            r = r->left;
                        }
                        r->left = l;
                        free(node_to_be_delete);
                        cout << n << " is deleted." << endl;
                        break;
                    }
                    else
                    {
                        prev->left = l;
                        while (l->right != NULL)
                        {
                            l = l->right;
                        }
                        l->right = r;
                        free(node_to_be_delete);
                        cout << n << " is deleted." << endl;
                        break;
                    }
                }
            }
        }
    }
    return root;
}
int main()
{
    int i = 0;
    do
    {
        int a, ch;
        cout << "\n\n"
             << endl;
        cout << "1. Insert node." << endl;
        cout << "2. Check tree is BST or NOT." << endl;
        cout << "3. Inorder traversal." << endl;
        cout << "4. Preorder traversal." << endl;
        cout << "5. Postorder traversal." << endl;
        cout << "6. Search node." << endl;
        cout << "7. Delete node." << endl;
        cout << "0. Exit." << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter node - ";
            cin >> a;
            create_node(a);
            break;
        case 2:
            isBST();
            break;
        case 3:
            in_order(root);
            break;
        case 4:
            pre_order(root);
            break;
        case 5:
            post_order(root);
            break;
        case 6:
            cout << "Enter node - ";
            cin >> a;
            search(a);
            break;
        case 7:
            cout << "Enter node - ";
            cin >> a;
            delete_node(a);
            break;
        case 0:
            i = 1;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }

    } while (i == 0);

    return 0;
}
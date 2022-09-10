#include <iostream>
using namespace std;

struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
};

struct Node *root = NULL;

struct Node *create_tree(int data)
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
        string side;
        while (true)
        {
            cout << "Which size you want insert node 'l' for left side and 'r' for right side - ";
            cin >> side;
            if (side == "l")
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

int get_height(struct Node *ptr)
{
    int height = 0;
    if (ptr != NULL)
    {
        height = 1 + max(get_height(ptr->left), get_height(ptr->right));
    }
    return height;
}

int isBST(struct Node *ptr)
{
    static struct Node *prev = NULL;
    if (ptr != NULL)
    {
        if (!isBST(ptr->left))
        {
            return 0;
        }
        if (prev != NULL && ptr->data <= prev->data)
        {
            return 0;
        }
        prev = ptr;
        return isBST(ptr->right);
    }
    else
    {
        return 1;
    }
}

int main()
{
    int i = 0;
    do
    {
        int ch, a, b;
        cout << "\n\n"
             << endl;
        cout << "1. Insert node." << endl;
        cout << "2. Preorder traversal." << endl;
        cout << "3. Inorder traversal." << endl;
        cout << "4. Postorder traversal." << endl;
        cout << "5. Height of tree." << endl;
        cout << "6. Check tree is binary tree or not." << endl;
        cout << "0. Exit." << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter node - ";
            cin >> a;
            create_tree(a);
            break;
        case 2:
            pre_order(root);
            break;
        case 3:
            in_order(root);
            break;
        case 4:
            post_order(root);
            break;
        case 5:
            cout << "Height of the tree is - " << get_height(root) - 1 << endl;
            break;
        case 6:
            if (isBST(root))
            {
                cout << "Tree is BST." << endl;
            }
            else
            {
                cout << "Tree is not BST." << endl;
            }
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
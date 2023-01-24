// Write a menu driven program in C or C++ to perform the following operations on
// Binary Search Tree.
// (a) insert a node.
// (b) inorder traversal.
// (c) preorder traversal.
// (d) postorder traversal.
// (e) search an given key.
// (f) Find the smallest element.
// (g) Find the largest element.
// (h) Delete an element.
// (i) Count the total number of nodes.
// (j) Count the total number of external nodes.
// (k) Count the total number of internal nodes.
// (l) Determine the height of the tree.

#include <iostream>
using namespace std;

class BST
{
    BST *lc;
    int data;
    BST *rc;

public:
    // default constructor
    BST()
    {
        this->lc = NULL;
        this->data = 0;
        this->rc = NULL;
    }
    // paramitarized constructor
    BST(int val)
    {
        this->lc = NULL;
        this->data = val;
        this->rc = NULL;
    }
    // insert operation
    BST *insert(BST *root, int val)
    {
        if (root == NULL)
            return new BST(val);
        BST *ptr = root;
        if (ptr->data < val)
            root->rc = insert(ptr->rc, val);
        else
            root->lc = insert(ptr->lc, val);
        return root;
    }
    // inorder traversal
    void inord(BST *root)
    {
        if (root == NULL)
            return;
        inord(root->lc);
        cout << root->data << " ";
        inord(root->rc);
    }
    // preorder traversal
    void preord(BST *root)
    {
        if (root == NULL)
            return;
        cout << root->data << " ";
        preord(root->lc);
        preord(root->rc);
    }
    // postorder traversal
    void postord(BST *root)
    {
        if (root == NULL)
            return;
        postord(root->lc);
        postord(root->rc);
        cout << root->data << " ";
    }
    int Search(BST *root, int key)
    {
        if (root == NULL)
            return 0;
        if (root->data == key)
            return 1;
        if (key < root->data)
        {
            Search(root->lc, key);
        }
        if (key > root->data)
        {
            Search(root->rc, key);
        }
        return 0;
    }
    BST *minValue(BST *root)
    {
        if (root->lc == NULL)
            return root;
        root->lc = minValue(root->lc);
        return root;
    }
    BST *maxValue(BST *root)
    {
        if (root->rc == NULL)
            return root;
        root->rc = maxValue(root->rc);
        return root;
    }
    // delete node operation
    BST *del(BST *root, int val)
    {
        if (root == NULL)
            return root;
        if (val < root->data)
        {
            root->lc = del(root->lc, val);
        }
        else if (val > root->data)
        {
            root->rc = del(root->rc, val);
        }
        else
        {
            if (root->lc == NULL && root->rc == NULL)
            {
                return NULL;
            }
            if (root->lc == NULL)
            {
                BST *temp = root->rc;
                free(root);
                return temp;
            }
            else if (root->rc == NULL)
            {
                BST *temp = root->lc;
                free(root);
                return temp;
            }
            else
            {
                BST *temp = minValue(root->rc);
                root->data = temp->data;
                root->rc = del(root->rc, root->data);
            }
        }
        return root;
    }
};

int main()
{
    BST b1;
    BST *root = NULL;
    root = b1.insert(root, 5);
    root = b1.insert(root, 8);
    root = b1.insert(root, 1);
    root = b1.insert(root, 9);
    root = b1.insert(root, 2);

    b1.inord(root);
    cout << endl;
    root = b1.del(root, 2);
    b1.inord(root);
    cout << endl;

    cout << b1.Search(root, 91);
    return 0;
}
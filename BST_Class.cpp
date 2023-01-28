#include <bits/stdc++.h>
#include "BST.cpp"
using namespace std;
class BST
{
    BinaryTreeNode<int> *root;

    bool hasData(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            return false;
        }
        if (node->data == data)
        {
            return true;
        }
        else if (data < node->data)
        {
            return hasData(data, node->left);
        }
        else
        {
            return hasData(data, node->right);
        }
    }

    BinaryTreeNode<int> *insert(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if (data < node->data)
        {
            node->left = insert(data, root->left);
        }
        else
        {
            node->right = insert(data, node->right);
        }
        return node;
    }
    BinaryTreeNode<int> *deleteData(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            return NULL;
        }
        if (data > node->data)
        {
            node->right = deleteData(data, node->right);
            return node;
        }
        else if (data < node->data)
        {
            node->left = deleteData(data, node->left);
            return node;
        }
        else
        {
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }
            else if (node->left == NULL)
            {
                BinaryTreeNode<int> *temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            else if (node->right == NULL)
            {
                BinaryTreeNode<int> *temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else
            {
                BinaryTreeNode<int> *minNode = node->right;
                while (minNode->left != NULL)
                {
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                node->data = rightMin;
                node->right = deleteData(rightMin, node->right);
                return node;
            }
        }
    }
    void printTree(BinaryTreeNode<int> *node)
    {
        cout<<"print";
        if (node == NULL)
        {
            return;
        }
        cout << node->data << " :: ";
        if (node->left != NULL)
        {
            cout << "L " << node->left->data;
        }
        if (node->right != NULL)
        {
            cout << "  R " << node->right->data;
        }
        cout << endl;
        printTree(node->left);
        printTree(node->right);
    }

public:
    BST()
    {
        cout<<"constructor";
        root = NULL;
    }
    void deleteData(int data)
    {
        root = deleteData(data, root);
    }
    void insert(int data)
    {
        cout<<"insert";
        this->root = insert(data,root);
    }
    bool hasData(int data)
    {
        return hasData(data, root);
    }
    void printTree()
    {
        cout<<"printMain";
        printTree(root);
    }
    ~BST()
    {
        delete root;
    }
};
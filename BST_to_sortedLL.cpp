#include <bits/stdc++.h>
#include "BST.cpp"
using namespace std;

class Node
{
public:
    // BinaryTreeNode<int> *node;
    int data;
    Node *next;
};

Node *findTail(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    while (head->next != NULL)
    {
        head = head->next;
    }
    return head;
}

Node *BST_to_sortedLL(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    Node *newNode = new Node;
    // newNode->node=root;
    newNode->data = root->data;
    newNode->next = NULL;
    Node *leftHead = BST_to_sortedLL(root->left);
    Node *rightHead = BST_to_sortedLL(root->right);
    Node *leftTail = findTail(leftHead);
    if (leftHead == NULL)
    {
        leftHead = newNode;
    }
    else
    {
        leftTail->next = newNode;
    }
    newNode->next = rightHead;
    return leftHead;
}

void printLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "\t";
        head = head->next;
    }
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    Node *head = BST_to_sortedLL(root);
    printLL(head);
    return (0);
}
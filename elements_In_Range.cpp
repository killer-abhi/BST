#include <bits/stdc++.h>
#include "BST.cpp"
using namespace std;

void printInRange(BinaryTreeNode<int> *root, int k1, int k2)
{
    if (root == NULL)
    {
        return;
    }

    if (root->data >= k1 && root->data <= k2)
    {
        cout << root->data<< "\t" ;
    }
    printInRange(root->left, k1, k2);
    printInRange(root->right, k1, k2);
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    int l1, l2;
    cout << "Enter Lower Limit :: ";
    cin >> l1;
    cout << "Enter Upper Limit :: ";
    cin >> l2;
    printInRange(root, l1, l2);
    return (0);
}
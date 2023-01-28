#include <bits/stdc++.h>
#include "BST.cpp"
using namespace std;

bool searchInBST(BinaryTreeNode<int> *root, int key)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == key)
    {
        return true;
    }
    else if (key < root->data)
    {
        return searchInBST(root->left,key);
    }
    else
    {
        return searchInBST(root->right,key);
    }
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    int searchElement;
    cout << "Enter Element To Be Searched :: ";
    cin >> searchElement;
    if (searchInBST(root, searchElement))
    {
        cout << "\n\n Element Found";
    }
    else
    {
        cout << "\n Element Not Found !! ";
    }

    return (0);
}
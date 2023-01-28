#include <bits/stdc++.h>
#include "BST.cpp"
using namespace std;

int findMax(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    return max(root->data, max(findMax(root->left), findMax(root->right)));
}
int findMin(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return INT_MAX;
    }
    return min(root->data, min(findMin(root->left), findMin(root->right)));
}
bool isBST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return true;
    }
    int leftMax = findMax(root->left);
    int rightMin = findMin(root->right);

    bool output = (root->data > leftMax) && (root->data <= rightMin) && isBST(root->left) && isBST(root->right);
    return output;
}
bool isBST2(BinaryTreeNode<int> *root, int min = INT_MIN, int max = INT_MAX)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data < min || root->data > max)
    {
        return false;
    }
    bool isLeftOk = isBST2(root->left, min, root->data - 1);
    bool isRightOk = isBST2(root->right, root->data, max);
    return isLeftOk && isRightOk;
}
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    if (isBST2(root))
    {
        cout << "\n\n BST";
    }
    else
    {
        cout << "\n\n Not a BST";
    }
    return (0);
}
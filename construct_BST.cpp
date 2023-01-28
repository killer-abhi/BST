#include <bits/stdc++.h>
#include "BST.cpp"
using namespace std;

BinaryTreeNode<int>* newNode(int data){
    cout<<data<<endl;
    BinaryTreeNode<int>* node=new BinaryTreeNode<int>();
    node->data=data;
    node->left=node->right=NULL;
    return node;
}
BinaryTreeNode<int> *constructBST(int *arr, int si, int ei)
{
    if (si > ei)
    {
        return NULL;
    }
    int mid = (si + ei) / 2;

    int data=arr[mid];
    BinaryTreeNode<int> *root=newNode(data);
    
    root->left = constructBST(arr, 0, mid - 1);
    root->right = constructBST(arr, mid + 1, ei);

    return root;
}
int main()
{
    int n;
    cout << "Enter No. Of Nodes :: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[n];
    }
    BinaryTreeNode<int> *root = constructBST(arr, 0, n - 1);
    printLevelWise(root);
    return (0);
}
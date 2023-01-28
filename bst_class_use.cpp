#include<bits/stdc++.h>
#include "BST_Class.cpp"
using namespace std;
int main()
{
    BST b;
    b.insert(10);
    b.insert(6);
    b.insert(20);
    b.insert(7);
    b.insert(3);
    b.insert(15);

    b.printTree();
    return(0);
}
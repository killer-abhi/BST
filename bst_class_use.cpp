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
    b.insert(1);
    b.insert(15);
    b.printTree();

    b.deleteData(20);
    cout<<endl<<endl;
    b.printTree();
    return(0);
}
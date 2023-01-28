#include<bits/stdc++.h>
#include "BST.cpp"
using namespace std;

vector<int>* rootToNodePath(BinaryTreeNode<int>*root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        vector<int> *output=new vector<int>();
        output->push_back(key);
        return output;
    }
    vector<int>* leftAns=rootToNodePath(root->left,key);
    if(leftAns!=NULL){
        leftAns->push_back(root->data);
        return leftAns;
    }
    vector<int>* rightAns=rootToNodePath(root->right,key);
    if(rightAns!=NULL){
        rightAns->push_back(root->data);
        return rightAns;
    }
    else{
        return NULL;
    }
}
int main()
{
    BinaryTreeNode<int> *root=takeInputLevelWise();
    int key;
    cout<<"Enter Key Of Node to get Path ";
    cin>>key;
    vector<int>* res=rootToNodePath(root,key);
    for(int i=res->size()-1;i>=0;i--){
        cout<<res->at(i)<<"\t";
    }
    return(0);
}
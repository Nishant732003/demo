#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

public:
    Node(int x)
    {
        this->data = x;
        this->left = NULL;
        this->right = NULL;
    }
};
 void printkdistancedown(Node*root,int k){
    if(root==NULL || k<0){
        return;
    }
    if(k==0){
        cout << root->data << endl;
        return;
    }
    printkdistancedown(root->left, k - 1);
    printkdistancedown(root->right, k - 1);
 }
 int printkdistanceNode(Node*root,Node*target,int k){
    if(root==NULL || k<0)
        return -1;
    if(root==target){
        printkdistancedown(root, k);
    return 0;
    }
    int dl = printkdistanceNode(root->left, target, k);
    if(dl!=-1){
        if(dl+1==k)
            cout << root->data << endl;
    
    else{
        printkdistancedown(root->right, k - dl - 2);
        return 1 + dl;
    }
    }
    int dr = printkdistanceNode(root->right, target, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
            cout << root->data << endl;
    
    else
    {
        printkdistancedown(root->left, k - dr - 2);
        return 1 + dr;
    }
    }
    return -1;
 }
int main()
{
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    Node *target = root->left->right;
    printkdistanceNode(root, target, 2);
    return 0;
}
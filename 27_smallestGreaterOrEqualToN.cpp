//27

//Encuentra dato mas peque�o que sea mayor o igual que N

// C++ program to find the smallest value  
// greater than or equal to N 
#include <bits/stdc++.h> 
using namespace std; 
  
struct Node { 
    int data; 
    Node *left, *right; 
}; 
  
// To create new BST Node 
Node* createNode(int item) 
{ 
    Node* temp = new Node; 
    temp->data = item; 
    temp->left = temp->right = NULL; 
  
    return temp; 
} 
  
// To add a new node in BST 
Node* add(Node* node, int key) 
{ 
    // if tree is empty return new node 
    if (node == NULL) 
        return createNode(key); 
  
    // if key is less then or grater then 
    // node value then recur down the tree 
    if (key < node->data) 
        node->left = add(node->left, key); 
    else if (key > node->data) 
        node->right = add(node->right, key); 
  
    // return the (unchanged) node pointer 
    return node; 
} 
  
// function to find min value less then N 
int findMinforN(Node* root, int N) 
{ 
    // If leaf node reached and is smaller than N 
    if (root->left == NULL && root->right == NULL  
                                && root->data < N) 
        return -1; 
  
    // If node's value is greater than N and left value 
    // is NULL or smaller then return the node value 
    if ((root->data >= N && root->left == NULL)  
        || (root->data >= N && root->left->data < N)) 
        return root->data; 
  
    // if node value is smaller than N search in the 
    // right subtree 
    if (root->data <= N) 
        return findMinforN(root->right, N); 
  
    // if node value is greater than N search in the 
    // left subtree 
    else
        return findMinforN(root->left, N); 
} 
  
// Drivers code 
int main() 
{ 
    /*    19 
        /    \ 
       7     21 
     /   \ 
    3     11 
         /   \ 
         9    14 
          */
  
    Node* root = NULL; 
    root = add(root, 19); 
    root = add(root, 7); 
    root = add(root, 3); 
    root = add(root, 11); 
    root = add(root, 9); 
    root = add(root, 13); 
    root = add(root, 21); 
  
    int N = 18; 
    cout << findMinforN(root, N) << endl; 
  
    return 0; 
} 

//26

//ENCUANTRA EL VALOR MAS GRANDE PERO MENOR O IGUAL QUE UN NUMERO DADO

// C++ code to find the largest value smaller 
// than or equal to N 
#include <bits/stdc++.h> 
using namespace std; 

struct Node { 
	int key; 
	Node *left, *right; 
}; 

// To create new BST Node 
Node* newNode(int item) 
{ 
	Node* temp = new Node; 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// To insert a new node in BST 
Node* insert(Node* node, int key) 
{ 
	// if tree is empty return new node 
	if (node == NULL) 
		return newNode(key); 

	// if key is less then or grater then 
	// node value then recur down the tree 
	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key); 

	// return the (unchanged) node pointer 
	return node; 
} 

// function to find max value less then N 
int findMaxforN(Node* root, int N) 
{ 
	// Base cases 
	if (root == NULL) 
		return -1; 
	if (root->key == N) 
		return N; 

	// If root's value is smaller, try in rght 
	// subtree 
	else if (root->key < N) { 
		int k = findMaxforN(root->right, N); 
		if (k == -1) 
			return root->key; 
		else
			return k; 
	} 

	// If root's key is greater, return value 
	// from left subtree. 
	else if (root->key > N) 
		return findMaxforN(root->left, N);	 
} 

// Driver code 
int main() 
{ 
	int N = 4; 

	// creating following BST 
	/* 
				5 
			/ \ 
			2	 12 
		/ \ / \ 
		1 3 9 21 
					/ \ 
					19 25 */
	Node* root = insert(root, 25); 
	insert(root, 2); 
	insert(root, 1); 
	insert(root, 3); 
	insert(root, 12); 
	insert(root, 9); 
	insert(root, 21); 
	insert(root, 19); 
	insert(root, 25); 

	printf("%d", findMaxforN(root, N)); 

	return 0; 
} 


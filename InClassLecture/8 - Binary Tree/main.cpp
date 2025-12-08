#include <iostream>
using namespace std;

//Binary tree
// Ex: 8, 10, 11, 5, 2, 20, 4
//1. If child_val < parent_val, add child to the left of parent, else add child to the right of parent
//2. If the tree is empty, then the first node is parent node (root node)

struct node {
	int data;
	node* left;
	node* right;
};

class BST {
public:
	node* getnewnode(int i_data);
	node* insert(node* root, int i_data);
	node* search(node* root, int i_data);
	node* traverse(node* root);
};
	
node* BST::getnewnode(int i_data) {
	node* newnode = new node;
	newnode->data = i_data;
	newnode->left = NULL;
	newnode->right = NULL; 
	return newnode;
}

node* BST::insert(node* root, int i_data) {
	if (root == NULL) {
		root = getnewnode(i_data);
	} 
	else if (i_data <= root->data) {
		root->left = insert(root->left, i_data);
	}
	else {
		root->right = insert(root->right, i_data);
	}
	return root;
}

node* BST::search(node* root, int i_data) {
	if (root == NULL) {
		return NULL;
	}
	if (root->data == i_data) {
		return root;
	}
	if (i_data <= root->data) {
		return search(root->left, i_data);
	}
	if (i_data > root->data) {
		return search(root->right, i_data);
	}
}

node* BST::traverse(node* root) {
	if (root == NULL) {
		return NULL;
	}
	//inorder traversal (left, root, right)
	traverse(root->left);
	cout << root->data << " ";
	traverse(root->right);

}


int main() {

	BST* mytree = new BST;
	node* root = NULL;
	root = mytree->insert(root, 8);
	root = mytree->insert(root, 10);
	root = mytree->insert(root, 11);
	root = mytree->insert(root, 5);
	root = mytree->insert(root, 2);
	root = mytree->insert(root, 20);
	root = mytree->insert(root, 4);

	mytree->traverse(root);
	cout << "Traversing is done" << endl;

	if (mytree->search(root, 5) != NULL) {
		cout << "found" << endl;
	}
	else {
		cout << "not found" << endl;
	}


	return 0;
}
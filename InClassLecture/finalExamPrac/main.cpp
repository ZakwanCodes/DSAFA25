#include <iostream>
using namespace std;

struct node {
	int val;
	node* left;
	node* right;
};

class BST {
public:
	
	node* createnode(int i_val) {
		node* newnode = new node;
		newnode->val = i_val;
		newnode->left = NULL;
		newnode->right = NULL;
		return newnode;
	}

	node* insertnode(node* root, int i_val) {
		if (root == NULL) {
			root = createnode(i_val);
		}
		else if(root->val > i_val){
			root->left = insertnode(root->left, i_val);
		}
		else {
			root->right = insertnode(root->right, i_val);
		}

		return root;
	}

	node* print(node* root) {
		if (root == NULL) {
			return NULL;
		}

		print(root->left);
		cout << root->val << " ";
		print(root->right);
	}

	void countTotalNodes(node* root, int& count) {

		if (root == NULL) {
			return;
		}

		countTotalNodes(root->left, count);
		count++;
		countTotalNodes(root->right, count);

	}
};



int main() {

	BST binaryTree;

	node* root = NULL;
	
	root = binaryTree.insertnode(root, 2);
	root = binaryTree.insertnode(root, 5);
	root = binaryTree.insertnode(root, 5);
	root = binaryTree.insertnode(root, 1);
	root = binaryTree.insertnode(root, 1);
	root = binaryTree.insertnode(root, 1);
	root = binaryTree.insertnode(root, 1);



	binaryTree.print(root);

	int num = 0;
	binaryTree.countTotalNodes(root, num);

	cout << endl << "Total Nodes: " << num << endl;
	return 0;
}





/*#include <iostream>
using namespace std;

// Node structure
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* LCA(Node* root, Node* n1, Node* n2) {

    while (root != nullptr) {
      
        // If both n1 and n2 are smaller than root,
        // then LCA lies in left
        if (root->data > n1->data && root->data > n2->data)
            root = root->left;

        // If both n1 and n2 are greater than root,
        // then LCA lies in right
        else if (root->data < n1->data && root->data < n2->data)
            root = root->right;
        
        // Else Ancestor is found
        else
            break;
    }

    return root;
}

int main() {
  	
  	// Representation of input BST:
    //            20
    //           /  \
    //          8    22
    //        /   \     
    //       4    12   
    //           /   \   
    //         10    14  
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    // Node 4
    Node* n1 = root->left->left; 
    
    // Node 14
    Node* n2 = root->left->right->right; 

    Node* res = LCA(root, n1, n2);
    cout << res->data << endl;

    return 0;
}
*/

















/*
#include <iostream>
using namespace std;

struct node {
    int val;
    node* left;
    node* right;
};

// helper function with a previous node pointer
bool isBSTInorder(node* root, node*& prev) {
    if (root == NULL) return true;

    // check left subtree
    if (!isBSTInorder(root->left, prev)) return false;

    // check current node with previous node
    if (prev != NULL && root->val <= prev->val) return false;

    prev = root;  // update previous node

    // check right subtree
    return isBSTInorder(root->right, prev);
}

// wrapper function
bool isBST(node* root) {
    node* prev = NULL;
    return isBSTInorder(root, prev);
}

// simple insertion function
node* insert(node* root, int val) {
    if (root == NULL) {
        node* n = new node{val, NULL, NULL};
        return n;
    }
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// in-order printing
void printInorder(node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    node* root = NULL;
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 8);
    root = insert(root, 1);
    root = insert(root, 3);

    printInorder(root);  // prints: 1 2 3 5 8
    cout << endl;

    if (isBST(root))
        cout << "Tree is a BST" << endl;
    else
        cout << "Tree is NOT a BST" << endl;

    return 0;
}
*/


















/*// C++ Program to find Inorder Successor in 
// Binary Search Tree

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

Node* leftMost(Node* node) {
    Node* curr = node;
    while (curr->left != nullptr) 
        curr = curr->left;
    return curr;
}


Node* getSucc(Node* root, int target) {
    
    // Base Case 1: No Inorder Successor
    if (root == nullptr)
        return nullptr;
     
    // Base Case 2: root is same as target and 
    // right child is not empty
    if (root->data == target && root->right != nullptr)
        return leftMost(root->right);

    // Use BST properties to search for 
    // target and successor
    Node* succ = nullptr;
    Node* curr = root; 
    while (curr != nullptr) {
      
        // If curr node is greater, then it
        // is a potential successor
        if (target < curr->data) {
            succ = curr;
            curr = curr->left;
        }
      
        // If smaller, then successor must
        // be in the right child
        else if (target >= curr->data) 
            curr = curr->right;
      
    }

    return succ;
}

int main() {
  
    // Construct a BST
    //            20
    //          /    \
    //         8      22
    //       /   \
    //      4    12
    //          /  \
    //         10   14
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
  
    int target = 14;
    Node* succ = getSucc(root, target);
    if (succ != nullptr)
        cout << succ->data;
    else
        cout << "null";
    return 0;
}*/





















/*
// C++ Program to find kth largest element
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node (int x) {
            data = x;
            left = nullptr;
            right = nullptr;
        }
};

// Function which will traverse the BST
// in reverse inorder manner.
int kthLargestRecur(Node* root, int &cnt, int k) {

    // base case
    if (root == nullptr)
        return -1;

    int right = kthLargestRecur(root->right, cnt, k);

    // if kth largest number is present in
    // right subtree, then return it.
    if (right != -1)
        return right;

    // Increment the node count.
    cnt++;

    // If root node is the kth largest element,
    // then return it.
    if (cnt == k)
        return root->data;

    int left = kthLargestRecur(root->left, cnt, k);

    // else return value provided by
    // left subtree.
    return left;
}

int kthLargest(Node* root, int k) {
    int cnt = 0;
    return kthLargestRecur(root, cnt, k);
}

int main() {

    // Create a hard coded tree.
    //         20
    //       /   \
    //      8     22
    //    /  \
    //   4   12
    //      /  \
    //     10   14
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    int k = 3;

    cout << kthLargest(root, k) << endl;

    return 0;
}*/









/*


#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

int minValue(Node* root) {
    
    // If left child is null, root is minimum
    if (root->left == nullptr) return root->data;
    
    // Recurse on left child
    return minValue(root->left);
}

int main() {
    // Create BST
    //        5
    //       / \
    //      4   6
    //     /     \
    //    3       7
    //   / 
    //  1
    Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(6);
    root->left->left = new Node(3);
    root->right->right = new Node(7);
    root->left->left->left = new Node(1);

    cout << minValue(root) << endl;
}
*/

















/*
#include <iostream>
#include <vector>
using namespace std;

// Node structure
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Recursive Function for inorder
void getInorder(Node* node, vector<int>& traversal) {
    if (!node) return;

    getInorder(node->left, traversal);
    traversal.push_back(node->data);
    getInorder(node->right, traversal);
}

// Function to return Median of BST
int findMedian(Node* root) {
    vector<int> inorder;
    getInorder(root, inorder);
    int n = inorder.size();

    // n is even - 0 based indexing
    if (n % 2 == 0)
        return inorder[n/2-1];

    // n is odd - 0 based indexing
    else
        return inorder[n/2];
}

int main() {
    // Create BST:
    //            20
    //           /  \
    //          8    22
    //        /   \
    //       4    12
    //           /   \
    //         10    14

    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    cout << findMedian(root) << endl;
    return 0;
}
*/















/*
// C++ Program to convert binary
// tree to binary search tree.
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left, *right;
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

// Inorder traversal to store the nodes in a vector
void inorder(Node* root, vector<int>& nodes) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left, nodes);
    nodes.push_back(root->data);
    inorder(root->right, nodes);
}

// Inorder traversal to convert tree
// to BST.
void constructBST(Node* root, vector<int> nodes, int& index) {
    if (root == nullptr) return;

    constructBST(root->left, nodes, index);

    // Update root value
    root->data = nodes[index++];

    constructBST(root->right, nodes, index);
}

// Function to convert a binary tree to a binary search tree
Node* binaryTreeToBST(Node* root) {
    vector<int> nodes;
    inorder(root, nodes);

    // sort the nodes
    sort(nodes.begin(), nodes.end());

    int index = 0;
    constructBST(root, nodes, index);
    return root;
}

// Function to print the inorder traversal of a binary tree
void printInorder(Node* root) {
    if (root == NULL) {
        return;
    }
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {

    // Creating the tree
    //         10
    //        /  \
    //       2    7
    //      / \
    //     8   4
    Node* root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(8);
    root->left->right = new Node(4);

    Node* ans = binaryTreeToBST(root);
    printInorder(ans);

    return 0;
}*/





/*#include <iostream>
using namespace std;

 // Node structure
class Node {
public:
    int data;
    Node* left, *right;
    Node (int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

// Search for (x-node value) in second bst
bool findVal(Node* root, int x) {
    
    if (root == nullptr) return false;
    
    if (root->data == x) return true;
    else if (root->data < x)
        return findVal(root->right, x);
    else 
        return findVal(root->left, x);
}

// Function to count pairs with sum equal to x
int countPairs(Node* root1, Node* root2, int x) {

    if (root1 == nullptr) return 0;
    
    int ans = 0;
    
    // If pair (root1.data, x-root1.data) exists,
    // then increment the ans.
    if (findVal(root2, x-root1->data))
        ans++;
    
    // Recursively check for left and right subtree.    
    ans += countPairs(root1->left, root2, x);
    ans += countPairs(root1->right, root2, x);
    
    return ans;
}

int main() {
    
    // BST1
    //    2
    //  /  \
    // 1   3
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(3);
    
    // BST2
    //    5
    //  /  \
    // 4   6
    Node* root2 = new Node(5);
    root2->left = new Node(4);
    root2->right = new Node(6);
    
    int x = 6;
    cout << countPairs(root1, root2, x);

    return 0;
}*/
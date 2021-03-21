#include <stdio.h> 
#include <stdlib.h>
#include <iostream>

using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
	int data;
	struct node* left, * right;
};

/* function to create a new node of tree and returns pointer */
struct node* newNode(int data);

/* returns max of two integers */
int max(int a, int b) { return (a > b) ? a : b; }

/* function to Compute height of a tree. */
int height(struct node* node);

/* Function to get diameter of a binary tree */
int diameter(struct node* tree)
{
	/* base case where tree is empty */
	if (tree == NULL)
		return 0;

	/* get the height of left and right sub-trees */
	int lheight = height(tree->left);
	int rheight = height(tree->right);

	/* get the diameter of left and right sub-trees */
	int ldiameter = diameter(tree->left);
	int rdiameter = diameter(tree->right);

	/* Return max of following three
	 1) Diameter of left subtree
	 2) Diameter of right subtree
	 3) Height of left subtree + height of right subtree + 1 */
	return max(lheight + rheight + 1, max(ldiameter, rdiameter));
}

/*The second parameter is to store the height of tree.
   Initially, we need to pass a pointer to a location with value
   as 0. So, function should be used as follows:

   int height = 0;
   struct node *root = SomeFunctionToMakeTree();
   int diameter = diameterOpt(root, &height); */
int diameterOpt(struct node* root, int& height) // nod 8 => 1: 1 0
{
	/* lh --> Height of left subtree
	   rh --> Height of right subtree */
	int lh = 0, rh = 0;

	/* ldiameter  --> diameter of left subtree
	   rdiameter  --> Diameter of right subtree */
	int ldiameter = 0, rdiameter = 0;

	if (root == NULL)
	{
		height = 0;
		return 0; /* diameter is also 0 */
	}

	/* Get the heights of left and right subtrees in lh and rh
	  And store the returned values in ldiameter and ldiameter */
	ldiameter = diameterOpt(root->left, lh);
	rdiameter = diameterOpt(root->right, rh);

	/* Height of current node is max of heights of left and
	   right subtrees plus 1*/
	height = max(lh, rh) + 1;
	cout << "[" << root->data << "]=" << max(lh + rh + 1, max(ldiameter, rdiameter)) << ": " << lh + rh + 1 << " " << max(ldiameter, rdiameter) << endl;
	return max(lh + rh + 1, max(ldiameter, rdiameter));
}
/*
[5] = 1: 1 0
[2] = 2 : 2 1
[10] = 1 : 1 0
[6] = 2 : 2 1
[3] = 3 : 3 2
[4] = 1 : 1 0
[1] = 7 : 7 3
d = 7 height = 4
*/


/* UTILITY FUNCTIONS TO TEST diameter() FUNCTION */

/*  The function Compute the "height" of a tree. Height is the
	number f nodes along the longest path from the root node
	down to the farthest leaf node.*/
int height(struct node* node)
{
	/* base case tree is empty */
	if (node == NULL)
		return 0;

	/* If tree is not empty then height = 1 + max of left
	   height and right heights */
	return 1 + max(height(node->left), height(node->right));
}

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
	struct node* node = (struct node*)
		malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return(node);
}

/* Driver program to test above functions*/
int main()
{

	/* Constructed binary tree is
			  1
			/   \
		  2      3
		/  \
	  4     5
	*/
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->left->left = newNode(5);
	root->left->left->left = newNode(8);
	root->left->left->right = newNode(9);

	root->right = newNode(3);
	root->right->left = newNode(6);
	root->right->left->left = newNode(10);
	root->right->left->left->left = newNode(11);

	int height;
	int d = diameterOpt(root, height);
	printf("Diameter of the given binary tree is %d h=%d\n", d, height);

	return 0;
}
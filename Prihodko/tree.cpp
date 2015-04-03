#include "tree.h"

#include <stdio.h>

//TreeNode methods

TreeNode::TreeNode (int data) {
	this->data = data;
	parent = NULL;
	left = NULL;
	right = NULL;
}

TreeNode::~TreeNode () {
}

int TreeNode::getData () {
	return this->data;
}

void TreeNode::setData (int newData) {
	this->data = newData;
}

Tree::Tree () {
	root = NULL;
} 

Tree::~Tree () {
	destruct (root);
}

TreeNode * Tree::search (int key) {
	TreeNode *current = root;
	while (current != NULL && current->getData() != key) {
		if (key < current->getData())
			current = current->left;
		else 
			current = current->right;
	}

	return current;
}

TreeNode * Tree::insert (int data) {
	if (search(data) != NULL) return NULL;
	
	TreeNode *newNode = new TreeNode (data);

	if (root == NULL) {
		root = newNode;
		return root;
	}

	TreeNode *current = root, *parent = NULL;
	while (current != NULL) {
		parent = current;
		if (data > current->getData())
			current = current->right;
		else
			current = current->left;
	}

	newNode->parent = parent;
	if (data > parent->getData())
		parent->right = newNode;
	else 
		parent->left = newNode;

	return newNode;
}


TreeNode * Tree::minimum (TreeNode *node) {
	if (node == NULL) return NULL;
	while (node->left != NULL)
		node = node->left;
	return node;
}

TreeNode * Tree::maximum (TreeNode *node) {
	if (node == NULL) return NULL;
	while (node->right != NULL)
		node = node->right;
	return node;
}

TreeNode * Tree::successor (TreeNode *node) {
	if (node == NULL) return NULL;
	if (node->right != NULL)
		return minimum (node->right);
	
	if (node->parent != NULL && node->parent->left == node)
		return successor (node->parent);
	else return node;
}

TreeNode * Tree::deccessor (TreeNode *node) {
	if (node == NULL) return NULL;
	if (node->left != NULL)
		return maximum (node->left);
	
	if (node->parent != NULL && node->parent->right == node)
		return deccessor (node->parent);
	else return node;	
}

void Tree::remove (TreeNode *deleted) {
	if (deleted == NULL) return;
	
	if (deleted->left != NULL && deleted->right != NULL) {
		TreeNode *next = successor (deleted);
		int tmp = next->getData();
		next->setData (deleted->getData());
		deleted->setData (tmp);
		remove (next);
	} else {
		TreeNode *child = NULL;
		if (deleted->left != NULL)
			child = deleted->left;
		else
			child = deleted->right;
		if (deleted->parent != NULL) {
			if (child != NULL)
				child->parent = deleted->parent;
			if (deleted->parent->right == deleted)
				deleted->parent->right = child;
			else
				deleted->parent->left = child;
		} else {
			child->parent = NULL;
			root = child;
		}
	}
}

void Tree::destruct (TreeNode *node) {
	if (node->left != NULL)
		destruct (node->left);
	if (node->right != NULL)
		destruct (node->right);
	delete node;
}

void Tree::inorderTraverse () {
	inorderTraverse (root);
}

void Tree::inorderTraverse (TreeNode *current) {
	if (current != NULL) {
		if (current->left != NULL)
			inorderTraverse (current->left);
		printf("%d ", current->getData());
		if (current->right != NULL)
			inorderTraverse (current->right);
	}
}

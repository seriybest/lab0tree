#ifndef _TREE_H_
#define _TREE_H_

class TreeNode {
private:	
	int data; 
public:
	TreeNode *parent;
	TreeNode *left;
	TreeNode *right;

	TreeNode (int);
	~TreeNode ();
	int getData ();
	void setData (int);
};

class Tree {
private:
	TreeNode *root;
public:
	Tree ();
	~Tree ();
	TreeNode *insert (int);
	TreeNode *search (int);
	TreeNode *minimum (TreeNode *);
	TreeNode *maximum (TreeNode *);
	TreeNode *successor (TreeNode *); 
	TreeNode *deccessor (TreeNode *);
	void remove (TreeNode *);
	void destruct (TreeNode *);
	void inorderTraverse ();
	void inorderTraverse (TreeNode *);
};

#endif

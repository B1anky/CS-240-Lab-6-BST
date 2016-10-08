#ifndef BST_H
#define BST_H

#include "BSTNode.h"

class BST{

private:
	BSTNode* root;

public:
	
	//int _size;

	BST();
	BST(int val);
	~BST();
	int insert(int value);
	int find(int value);
	int remove(int value);
	int removeRoot();
	void prPrefix(BSTNode* t);
	void prInfix(BSTNode* t);
	void prPostfix(BSTNode* t);
	void printTree();
	void printTree(BSTNode* p, int indent);
	//inline int size(){return _size;}
};

#endif

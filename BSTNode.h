#ifndef BSTNODE_H
#define BSTNODE_H

#include <iostream>
#include <sys/time.h>
#include <vector>

class BSTNode{
	private:
		
	public:
		BSTNode *left;
		BSTNode *right;
		int value;
		
		BSTNode();
		BSTNode(BSTNode &other);
		BSTNode(int val);
		BSTNode& operator=(const BSTNode& other);
		~BSTNode();

		int insertNode(int value);
		int findValue(int value);
		BSTNode* removeNode(int value, BSTNode* parent);

		int minVal();
		int minValRec(BSTNode* curr);

		BSTNode* getLeft(BSTNode* t);
		BSTNode* getRight(BSTNode *t);
		int getVal();

		void setLeft(BSTNode* l);
		void setRight(BSTNode* r);
		void setValue(int value);

};

#endif

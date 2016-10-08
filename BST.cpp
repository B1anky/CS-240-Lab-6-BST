#include "BST.h"

BST::BST(){
	//_size = 0;
	root = NULL;
}

BST::BST(int val){
	//_size = 0;
	root->value = val;
	root->left = NULL;
	root->right = NULL;
}

BST::~BST(){
	delete root;
}

int BST::insert(int value)
{
	//base case for empty tree
	if(root == NULL){
		root = new BSTNode();
		root->setValue(value);
		return value;
	}else{
		return root->insertNode(value);
	}
}

int BST::find(int value){
	if(root == NULL){
		return 0;
	}else{
		return root->findValue(value);
	}
}
BSTNode* getLargest(BSTNode* node)
{
	if(node->right != NULL)
	{
		return getLargest(node->right);
	}
	return node;
}

int BST::removeRoot(){
	if(root != NULL){
		BSTNode* delPtr = root;
		int smallestInRightSubtree;

		//Root has no children
		if(root->left == NULL && root->right == NULL){
			root = NULL;
			delete delPtr;
			return 1;
		//One right child
		}else if(root->left == NULL && root->right != NULL){
			root = root->right;
			delPtr->right = NULL;
			delete delPtr;
			return 1;
		//One left child
		}else if(root->left != NULL && root->right == NULL){
			root = root->left;
			delPtr->left = NULL;
			delete delPtr;
			return 1;
		//Two children of root
		}else{
			smallestInRightSubtree = root->minValRec(root->right);
			root->removeNode(smallestInRightSubtree, root);
			root->value = smallestInRightSubtree;
			return 1;
		}
	}else{
		return 0;
	}
}

int BST::remove(int value){
	if(root == NULL){
		return 0;
	}

	if(root->getVal() == value){
		removeRoot();
	}else{
		BSTNode* removedNode = root->removeNode(value, NULL);
		if(removedNode != NULL){
			delete removedNode;
			removedNode = NULL;
			return 1;
		}else{
			return 0;
		}
	}
	return 0;
	
}

void BST::prPrefix(BSTNode* t) 
{
	if(this == NULL)return;
	std::cout << root->getVal() << std::endl;
		prPrefix(root->getLeft(t));
		prPrefix(root->getRight(t));
}

void BST::prInfix(BSTNode* t) {
	if(this == NULL)return;
	prInfix(root->getLeft(t));
	std::cout << root->getVal() << std::endl;
		prInfix(root->getRight(t));
}

void BST::prPostfix(BSTNode* t) {
	if(this == NULL)return;
		prPostfix(root->getRight(t));
	std::cout << root->getVal() << std::endl;
		prPostfix(root->getLeft(t));

}

void BST::printTree(BSTNode* p, int indent)
{
	int idd = indent;
	if(p != NULL) 
	{
		if(p->right) 
		{
			printTree(p->right, indent+2);
		}
		if (indent) 
		{
			while(idd--)
				std::cout << ' ';
			idd = indent;
		}
		if (p->right){
			std::cout<<" /\n";
			while(idd--)
				std::cout << ' ';
			idd = indent;
		}
		std::cout<< p->getVal() << "\n ";
		if(p->left) 
		{
			while(idd--)
			std::cout << ' ';
			std::cout <<" \\\n";
			printTree(p->left, indent+2);
		}
	}  
}


void BST::printTree()
{
	return printTree(root, 0);
}


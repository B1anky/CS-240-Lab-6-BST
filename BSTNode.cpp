#include "BSTNode.h"

BSTNode::BSTNode(){
	value = 0;
	left = NULL;
	right = NULL;
}


BSTNode::BSTNode(int val) {
	this->value = val;
	this->right = NULL;
	this->left = NULL;
}

BSTNode::BSTNode(BSTNode &other){
	BSTNode* newLeft = NULL;
	BSTNode* newRight = NULL;

	if(other.left != NULL)
		newLeft = new BSTNode(*other.left);
	if(other.right != NULL)
		newRight = new BSTNode(*other.right);

	value = other.value;
	std::swap(left, newLeft);
	std::swap(right, newRight);

	delete newLeft;
	delete newRight;
}

BSTNode& BSTNode::operator=(const BSTNode& other){
	BSTNode* newLeft = NULL;
	BSTNode* newRight = NULL;

	if(other.left != NULL)
		newLeft = new BSTNode(*other.left);
	if(other.right != NULL)
		newRight = new BSTNode(*other.right);

	value = other.value;
	std::swap(left, newLeft);
	std::swap(right, newRight);

	delete newLeft;
	delete newRight;

	return *this;
}

BSTNode::~BSTNode() {
	//if(left){
		delete left;
		left = NULL;
	//}
	//if(right){
		delete right;
		right = NULL;
	//}
}

int BSTNode::insertNode(int value){
	if(value == this->value){
		return 0;
	}else if(value < this->value){
		if(left == NULL){
			left = new BSTNode(value);
			return value;
		}else{
			return left->insertNode(value);
		}
	}else if(value > this->value){
		if(right == NULL){
			right = new BSTNode(value);
			return value;
		}else{
			return right->insertNode(value);
		}
	}
	return 0;
}

int BSTNode::findValue(int value){
	if(value == this->value){
		return value;
	}else if(value < this->value){
		if(left == NULL){
			return 0;
		}else{
			return left->findValue(value);
		}
	}else if(value > this->value){
		if(right == NULL){
			return 0;
		}else{
			return right->findValue(value);
		}
	}
	return 0;
}

BSTNode* BSTNode::removeNode(int inValue, BSTNode* parent){
	int rootVal = this->value;
	int value = inValue;
	//Looking down left branch
	if(value < rootVal){
		if(left != NULL){
			return left->removeNode(value, this);
		}else{
			return NULL;
		}
	//Looking down right branch
	}else if(value > rootVal){
		if(right != NULL){
			return right->removeNode(value, this);
		}else{
			return NULL;
		}
	//Found inrootValue "= case"
	}else{
		//Deleting a leaf
		if(left == NULL && right == NULL){
			///Found newLeftt leaf to delete
			if(parent->left == this){
				parent->left = NULL;
				return this;
			//Found right leaf to delete 
			}else{
				parent->right = NULL;
				return this;
			}	
		//Removing something with a right child
		}else if(left == NULL){
			//Removing something on parent's right branch
			if(parent->right == this){
				parent->right = this->right;
				this->right = NULL;
				return this;
			//Removing something on parent's left branch
			}else{
				parent->left = this->right;
				this->right = NULL;
				return this;
			}
		//Removing something with a left child	
		}else if(right == NULL){
			if(parent->left == this){
				parent->left = this->left;
				this->left = NULL;
				return this;
			}else{
				parent->right = this->left;
				this->left = NULL;
				return this;
			}
		//Deleting a node with two children (root case and some others)
		}else{
			//Find right-most left sub branch and place it there
			if(parent->right != NULL){
				int smallestInRightSubtree = minValRec(parent->right);
				right->removeNode(smallestInRightSubtree, this);
				this->value = smallestInRightSubtree;
			}
		}
	}
	return NULL;
}

int BSTNode::minValRec(BSTNode* curr){
	if(curr == NULL){
		return 0;
	}else{
		if(curr->left != NULL){
			return minValRec(curr->left);
		}else{
			return curr->value;
		}
	}
}

int BSTNode::minVal(){
	return minValRec(this);
}

BSTNode* BSTNode::getLeft(BSTNode* t) { 
	return t->left; 
}

BSTNode* BSTNode::getRight(BSTNode* t) { 
	return t->right; 
}

int BSTNode::getVal() { 
	if(this != NULL)
		return this->value; 
	return 0;
}

void BSTNode::setLeft(BSTNode* l) { 
	this->left = l; 
}

void BSTNode::setRight(BSTNode* r) { 
	this->right = r; 
}

void BSTNode::setValue(int value) { 
	this->value = value; 
}
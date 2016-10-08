#include "BST.h"

std::vector<int> makeRandomVector(int numElements);
double test1(int numElements);
double test2(int numElements);
double test3(int numElements);
double test4(int numElements);
double test5(int numElements);
double test6(int numElements);

int main(){

	test1(100000);
	test2(100000);
	test3(100000);
	test4(100000);
	test5(100000);
	test6(100000);
	
	return 0;
}


std::vector<int> makeRandomVector(int numElements){
	std::vector<int> swappedValues;
	int i = 0;
	for(i = 1; i <= numElements; i++){
		swappedValues.push_back(i);
	}
	for (i = 1; i < numElements; i++) {
		int j = rand() % i; 
		int tmp; 
   		tmp = swappedValues[i]; 
   		swappedValues[i] = swappedValues[j];
  	 	swappedValues[j] = tmp; 
	}
	return swappedValues;
}

double test1(int numElements){
	BST *inOrderTree = new BST();
	struct timeval start, finish;
	int iterations = 10;
	int i = 0;

	for(i = 0; i < numElements; i++){
		inOrderTree->insert(i);
	}

	gettimeofday(&start, NULL);

	//Find code goes here
	for(int j = 0; j < iterations; j++){
		for(i = 0; i < 100000; i+=10000){
			inOrderTree->find(i);
		}
	}

	gettimeofday(&finish, NULL);
	double totalTime = 
	(double)((double)(finish.tv_sec - start.tv_sec) * 1000000 + 
	(double)(finish.tv_usec - start.tv_usec)) / 
	(double)1000000;
	std::cout << "Total time for test 1: " << totalTime/iterations << " seconds" << std::endl;
	
	delete inOrderTree;
	return totalTime;
}

double test2(int numElements){
	BST *inRandomTree = new BST();
	srand(time(NULL));
	int i = 0;
	int iterations = 10;
	std::vector<int> randomVector = makeRandomVector(numElements);
	struct timeval start, finish;
	
	for(i = 0; i < randomVector.size(); i++){
		inRandomTree->insert(randomVector[i]);
	}

	//Start timing the find function
	gettimeofday(&start, NULL);

	//To run test 10 times and get average
	for(int j = 0; j < iterations; j++){
		for(i = 0; i < 100000; i+=10000){
			inRandomTree->find(i);
		}
	}
	
	gettimeofday(&finish, NULL);
	double totalTime = 
	(double)((double)(finish.tv_sec - start.tv_sec) * 1000000 + 
	(double)(finish.tv_usec - start.tv_usec)) / 
	(double)1000000;
	std::cout << "Total time for test 2: " << totalTime/iterations << " seconds" << std::endl;

	delete inRandomTree;
	return totalTime;
}

double test3(int numElements){
	BST *inOrderTree = new BST();
	struct timeval start, finish;
	int i = 0;
	int iterations = 10;

	for(i = 1; i <= numElements; i++){
		inOrderTree->insert(i);
	}

	//Remove code goes here
	for(int i = 4; i <= numElements; i+=4){
		inOrderTree->remove(i);
	}

	gettimeofday(&start, NULL);

	//Find code goes here
	for(int j = 0; j < iterations; j++){
		for(i = 0; i < 100000; i+=10000){
			inOrderTree->find(i);
		}
	}

	gettimeofday(&finish, NULL);
	double totalTime = 
	(double)((double)(finish.tv_sec - start.tv_sec) * 1000000 + 
	(double)(finish.tv_usec - start.tv_usec)) / 
	(double)1000000;
	std::cout << "Total time for test 3: " << totalTime/iterations << " seconds" << std::endl;

	delete inOrderTree;
	return totalTime;
}

double test4(int numElements){
	BST *inRandomTree = new BST();
	srand(time(NULL));
	int i = 0;
	int iterations = 10;
	std::vector<int> randomVector = makeRandomVector(numElements);
	struct timeval start, finish;
	
	for(i = 0; i < randomVector.size(); i++){
		inRandomTree->insert(randomVector[i]);
	}
	
	for(int i = 4; i <= randomVector.size(); i+=4){
		inRandomTree->remove(i);
	}

	gettimeofday(&start, NULL);

	for(int j = 0; j < iterations; j++){
		for(i = 0; i < 100000; i+=10000){
			inRandomTree->find(i);
		}
	}

	gettimeofday(&finish, NULL);
	double totalTime = 
	(double)((double)(finish.tv_sec - start.tv_sec) * 1000000 + 
	(double)(finish.tv_usec - start.tv_usec)) / 
	(double)1000000;
	std::cout << "Total time for test 4: "  << totalTime/iterations << " seconds" << std::endl;

	delete inRandomTree;
	return totalTime;
}

double test5(int numElements){
	BST *inOrderTree = new BST();
	struct timeval start, finish;
	int i = 0;
	int iterations = 10;

	for(i = 0; i < numElements; i++){
		inOrderTree->insert(i);
	}

	//Remove code goes here
	for(int i = 0; i <=  numElements; i++){
		if(i % 2 == 0 || i % 4 == 0){
			inOrderTree->remove(i);
		}
	}

	gettimeofday(&start, NULL);

	//Find code goes here
	for(int j = 0; j < iterations; j++){
		for(i = 0; i < 100000; i+=10000){
			inOrderTree->find(i);
		}
	}

	gettimeofday(&finish, NULL);
	double totalTime = 
	(double)((double)(finish.tv_sec - start.tv_sec) * 1000000 + 
	(double)(finish.tv_usec - start.tv_usec)) / 
	(double)1000000;
	std::cout << "Total time for test 5: " << totalTime/iterations << " seconds" << std::endl;
	
	delete inOrderTree;
	return totalTime;
}

double test6(int numElements){
	BST *inRandomTree = new BST();
	srand(time(NULL));
	int i = 0;
	int iterations = 10;
	std::vector<int> randomVector = makeRandomVector(numElements);
	struct timeval start, finish;
	
	for(i = 0; i < randomVector.size(); i++){
		inRandomTree->insert(randomVector[i]);
	}
	
	//Remove code goes here
	for(int i = 0; i <= randomVector.size(); i++){
		if(i % 2 == 0 || i % 4 == 0){
			inRandomTree->remove(i);
		}
	}

	gettimeofday(&start, NULL);

	for(int j = 0; j < iterations; j++){
		for(i = 0; i < 100000; i+=10000){
			inRandomTree->find(i);
		}
	}

	gettimeofday(&finish, NULL);
	double totalTime = 
	(double)((double)(finish.tv_sec - start.tv_sec) * 1000000 + 
	(double)(finish.tv_usec - start.tv_usec)) / 
	(double)1000000;
	std::cout << "Total time for test 6: " << totalTime/iterations << " seconds" << std::endl;

	delete inRandomTree;
	return totalTime;
}
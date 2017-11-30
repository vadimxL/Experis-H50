#include <stdio.h>
#include <stdlib.h>
#include "dynAlloc.h"
#define PASS 1
#define FAIL 0

int test1(); // numOfElements > size
int test2(); // test of insertDa ---> numOfElements == size, incrBlockSize = 0
int test3(); // Passing NULL to insertDa and removeDa
int test4(); // test of insertDa --->  numOfElements = size, incrBlockSize = 1
int test5(); // test of removeDa ---> numOfElements = 0
int test6(); // test for REALLOC_FAIL, PASS if insertDa returns REALLOC_FAIL
void printDa(int* ptr, size_t* size);

int main() {

int i = 1;

	printf("Test %d is %s\n", i++,test1() ? "PASS" : "FAIL" ); // Expected FAIL
	printf("Test %d is %s\n",i++, test2() ? "PASS" : "FAIL" ); // Expected FAIL
	printf("Test %d is %s\n",i++, test3() ? "PASS" : "FAIL"); // Expected FAIL
	printf("Test %d is %s\n",i++, test4() ? "PASS" : "FAIL"); // Expected PASS
	printf("Test %d is %s\n",i++, test5() ? "PASS" : "FAIL"); // Expected FAIL
	printf("Test %d is %s\n",i++, test6() ? "PASS" : "FAIL"); // Expected PASS

return 0;

}

int test1() {
		
	size_t size = 10, numOfElements = 25, incrBlockSize = 0;
	int* ptr = createDa(size);	

	if ( insertDa(&ptr, 666, &size, &numOfElements, incrBlockSize) == DA_OK )
		return PASS;
	return FAIL;

	destroyDa(ptr);
}

int test2() {

	size_t size = 10, numOfElements = 10, incrBlockSize = 0;
	int* ptr = createDa(size);	

	if ( insertDa(&ptr, 666, &size, &numOfElements, incrBlockSize) == DA_OK )
		return PASS; 
	return FAIL;

	destroyDa(ptr);
}

int test3() {


	size_t size = 10, numOfElements = 20, incrBlockSize = 1;
	int data = 666;
	int* ptr = createDa(size);	
	int a,b,c,d,e,f;

	a = insertDa(&ptr, data, NULL, &numOfElements, incrBlockSize);
	b = insertDa(&ptr, data, &size, NULL, incrBlockSize);
	
	c = insertDa(NULL, data, &size, &numOfElements, incrBlockSize);

	d = removeDa(NULL, &data, &numOfElements);
	e = removeDa(ptr, NULL, &numOfElements);
	f = removeDa(ptr, &data, NULL);

	if ( a  == DA_OK || b == DA_OK || c == DA_OK || d == DA_OK || e == DA_OK || f == DA_OK )
		return PASS;
	return FAIL;

	destroyDa(ptr);

}

int test4() {

	size_t size = 10, numOfElements = 10, incrBlockSize = 1, data = 666;
	int* ptr = createDa(size);	

	if ( insertDa(&ptr, data, &size, &numOfElements, incrBlockSize) == DA_OK )
		return PASS; 
	return FAIL;

	destroyDa(ptr);
}

int test5() {

	size_t size = 10, numOfElements = 0;
	int data = 666;
	int* ptr = createDa(size);	

	if ( removeDa(ptr, &data, &numOfElements) == DA_OK )
		return PASS; 
	return FAIL;

	destroyDa(ptr);
}

int test6() {
	size_t size = 10, numOfElements = 10, incrBlockSize = 1E19, data = 666;
	int* ptr = createDa(size);	

	if ( insertDa(&ptr, data, &size, &numOfElements, incrBlockSize) == REALLOC_FAIL )
		return PASS; 
	return FAIL;

	destroyDa(ptr);
}


void printDa(int* ptr, size_t* size) {
	printf("----------------- Printing an Array -------------------\n\n\n");	
	printf("{ ");
	for(int i=0; i < *size; i++) {
		printf("%d ", *(ptr+i));
	}
	printf(" }");
	printf("\n\n\n-------------------------------------------------------\n\n\n");
}

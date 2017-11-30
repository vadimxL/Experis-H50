#include <stdio.h>
#include "DA.h"
#define PASS 1
#define FAIL 0

int test1(); // Pass size=0 & incrBlockSize = 0 and check if createDa returns NULL
int test2(); // Passing NULL to insertDa
int test3(); // Passing NULL to removeDa
int test4(); // Test for DATA_OVERFLOW
int test5(); // Test for DATA_UNDERFLOW
int test6(); // Test for REALLOC_FAIL
int test7(); // Test for positive , insertDa and removeDa do what they supposed to do



int main() {

	// Expected PASS from all tests

	printf("Test 1 is %s\n", test1() ? "PASS" : "FAIL");
	printf("Test 2 is %s\n", test2() ? "PASS" : "FAIL");
	printf("Test 3 is %s\n", test3() ? "PASS" : "FAIL"); 
	printf("Test 4 is %s\n", test4() ? "PASS" : "FAIL"); 
	printf("Test 5 is %s\n", test5() ? "PASS" : "FAIL"); 
	printf("Test 6 is %s\n", test6() ? "PASS" : "FAIL"); 
	printf("Test 7 is %s\n", test7() ? "PASS" : "FAIL"); 

return 0;
}



/* Pass size=0 & incrBlockSize = 0 and check if createDa returns NULL */
int test1() {
		
	size_t size = 0, incrBlockSize = 0;
	DA* status = createDa(size,incrBlockSize);	
	if ( status == NULL ) {
		return PASS;
	}
	return FAIL;
}

/* Passing NULL to insertDa */
int test2() {

	int data = -666;
	
	if ( insertDa(NULL,data) == PTR_NOT_INIT )
		return PASS; 
	return FAIL;
}


/* Passing NULL to removeDa */
int test3() {

	int data;

	if ( removeDa(NULL, &data) == PTR_NOT_INIT )
		return PASS; 
	return FAIL;

}

/* Test for DATA_OVERFLOW */
int test4() {

	size_t size = 10, incrBlockSize = 0, data = 666;
	int i;
	DA* ptr = createDa(size,incrBlockSize);
	
	for( i=0; i<size+1; i++) {
		if ( insertDa(ptr, data) == DATA_OVERFLOW ) {
		
		destroyDa(ptr);
		return PASS;
		}
	}
	destroyDa(ptr);
	return FAIL;
}

/* Test for DATA_UNDERFLOW */
int test5() {

	size_t size = 5, incrBlockSize = 0, data = 666;
	int i, remData;
	DA* ptr = createDa(size,incrBlockSize);
	
	for( i=0; i<size; i++)
		insertDa(ptr, data);
	
	for(i=0; i<size+1; i++) {
		if (removeDa(ptr, &remData) != DATA_UNDERFLOW) {
			destroyDa(ptr);
			return PASS;
		}
	}	
	destroyDa(ptr);
}

/* Test for REALLOC_FAIL */
int test6() {

	size_t size = 1, incrBlockSize = 1E19, data = 666;
	
	DA* ptr = createDa(size,incrBlockSize);
	
	insertDa(ptr, data);
	
	if ( insertDa(ptr, data) == REALLOC_FAIL ) {
		destroyDa;
		return PASS;
	}
	destroyDa;
	return FAIL;
}

/* Test for positive , insertDa and removeDa do what they supposed to do */
int test7() {

	size_t size = 10, incrBlockSize = 0;
	int data = 666, remData;
	int i;
	
	DA* ptr = createDa(size,incrBlockSize);	
	
	for(i=0;i<size;i++)
		insertDa(ptr, data);
		
	for(i=0;i<size;i++) 
		removeDa(ptr,&remData);
		
	if( remData != data) {
		destroyDa;
	   return FAIL;
	}
	destroyDa(ptr);
	return PASS;
}

#include <stdio.h>
#include "miniProject.h"
#define PASS 1
#define FAIL 0


int test1(); // Test for meeting overlap
int test2(); // Test for NULL
int test3(); // Test for NULL
int test4(); // Test for Loading from file


int main() {




//printf("Test 1 is %s\n", test1() ? "PASS" : "FAIL" );
//printf("Test 1 is %s\n", test2() ? "PASS" : "FAIL" );
//printf("Test 1 is %s\n", test3() ? "PASS" : "FAIL" );
printf("Test 4 is %s\n", test4() ? "PASS" : "FAIL" );


return 0;
}


/* Comment for commit check */

/* Testing for meeting overlap */
int test1() {


	AD* ptr = createAD();

	createMeeting(ptr, 10, 11, 450);
	insertMeeting(ptr);
	createMeeting(ptr, 11.3, 11.8, 455);
	insertMeeting(ptr);
	createMeeting(ptr, 8, 9, 460);
	insertMeeting(ptr);

	if (insertMeeting(ptr) == MEETING_OVERLAP) {
		destroyAD(ptr);
		return PASS;
		}
	destroyAD(ptr);
	return FAIL;
}

/* Testing for null pointer */

int test2() {

	if (insertMeeting(NULL) == PTR_NOT_INIT) return PASS;
	return FAIL;	
	
return 0;
}

/* Testing for null pointer */

int test3() {

	if( createMeeting(NULL, 10, 11, 450) == PTR_NOT_INIT) return PASS;
	return FAIL;

return 0;
}

/* Testing for loading from file */
int test4() {

	AD* ptr = createAD();

	if(ptr == NULL) return FAIL;

	if( loadFromFile(ptr) != PTR_NOT_INIT) {
		printAD(ptr);
		return PASS;
	}

	return FAIL;
}

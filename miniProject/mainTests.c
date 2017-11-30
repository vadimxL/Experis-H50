#include <stdio.h>
#include "miniProject.h"
#define PASS 1
#define FAIL 0


int test1(); // Test for meeting overlap
int test2(); // Test for NULL
int test3(); // Test for NULL


int main() {



printf("Test 1 is %s\n", test1() ? "PASS" : "FAIL" );
printf("Test 1 is %s\n", test2() ? "PASS" : "FAIL" );
printf("Test 1 is %s\n", test3() ? "PASS" : "FAIL" );


return 0;
}


/* Testing for meeting overlap */
int test1() {


	AD* ptr = createAD();

	createMeeting(ptr, 10, 11, 450);
	insertMeeting(ptr);
	createMeeting(ptr, 11.3, 11.8, 455);
	insertMeeting(ptr);
	createMeeting(ptr, 10.5, 11.7, 460);
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

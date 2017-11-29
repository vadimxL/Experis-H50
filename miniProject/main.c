#include <stdio.h>
#include "miniProject.h"
#define PASS 1
#define FAIL 0


int test1(); // Test for meeting overlap
int test2(); // Test for inserting meetings

int main() {


	// printf("Test 1 is %s\n", test1() ? "PASS" : "FAIL" );
	   test2();


	

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

int test2() {


	AD* ptr = createAD();


	createMeeting(ptr, 10, 11, 450);
	insertMeeting(ptr);
	createMeeting(ptr, 11.3, 11.8, 455);
	insertMeeting(ptr);
	createMeeting(ptr, 12, 12.5, 460);
	insertMeeting(ptr);
	removeMeeting(ptr, 10);
	printAD(ptr);
	destroyAD(ptr);	
	

return 0;
}




#include "lotto.h" /* our library file */
#define PASS 1
#define FAIL 0


int test1(); // Test for...
int test2(); // Test for...
int test3(); // Test for...
int test4(); // Test for...


int main() {


lotto("myfile.txt");

//printf("Test 1 is %s\n", test1() ? "PASS" : "FAIL" );
//printf("Test 2 is %s\n", test2() ? "PASS" : "FAIL" );
//printf("Test 3 is %s\n", test3() ? "PASS" : "FAIL" );
//printf("Test 4 is %s\n", test4() ? "PASS" : "FAIL" );


return 0;
}


/* Testing for.. */

int test1() {

	if (1) return PASS;
	return FAIL;	
	
return 0;
}



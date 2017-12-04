#include "files.h"
#define PASS 1
#define FAIL 0

int test1(); // Test for meeting overlap
int test2(); // Test for NULL
int test3(); // Test for NULL
int test4(); // Test for Loading from file

int main() {

// countLetters("lettersTest.txt");

// countWords("Ghost.txt");


wordsFrequency("textfile.txt");


//printf("Test 1 is %s\n", test1() ? "PASS" : "FAIL" );
//printf("Test 1 is %s\n", test2() ? "PASS" : "FAIL" );
//printf("Test 1 is %s\n", test3() ? "PASS" : "FAIL" );
//printf("Test 4 is %s\n", test4() ? "PASS" : "FAIL" );

return 0;
}


int test1() {

	if (1) return PASS;
	return FAIL;	
	
	return 0;
}

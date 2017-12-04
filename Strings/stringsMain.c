#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "strings.h"

int test_myatoi(char* str);

int test_reverseStr(char* str);


int main() {

	char *str1 = "100";
	char *str2 = "    1234  15";
	char *str3 = "    -1234";
	char *str4 = "    +1234";
	char *str5 = "123four";
	char *str6 = "invalid123";
	char *str7 = "....21232...";
	
	test_myatoi(str1); // i = 100
	test_myatoi(str2); // i = 1234
	test_myatoi(str3); // i = -1234
	test_myatoi(str4); // i = 1234
	test_myatoi(str5); // i = 123
	test_myatoi(str6); // i = 0
	test_myatoi(str7); // i = 21232
	
	
	char *str8 = "Vadim";
	char *str9 = "V";
	char *str10 = "";
	char *str11 = "Poop";
	
	printf("\n\n\n\n");
	
	test_reverseStr(str8);
	test_reverseStr(str9);
	test_reverseStr(str10);
	test_reverseStr(str11);	

}


int test_myatoi(char* str) {

	printf("i=%d\n", myatoi(str) );


	return OK;
}

int test_reverseStr(char* str) {
	int status;
	status = reverseStr(str);
	printf("%s\n", str);
	
	return status;
}
	
	


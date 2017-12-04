#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define BUFFER 1024

typedef enum {FALSE=0, TRUE} bool_t;


bool_t isName(char* arr);
bool_t isAge(char* arr);

int main(int argc, char* argv[]) {
	
	if( argc != 3 ) {
		printf("Invalid number of arguments");
		return 0;
	}
		
	if ( isName(argv[1]) ) printf(" Second argument is name\n");
	if ( isName(argv[2]) ) printf(" Third argument is name\n");
		

	
	// printf("The name is %s and age is %s\n", argv[1], argv[2]);
	

return 0;
}

bool_t isName(char* arr) {

	if( isupper( *arr ) ) {
		while( *(++arr) != '\0' ) {
			
			if( islower(*arr) ) {
				continue;
			}
			else {
				return FALSE;
			}
		}
	}
	else {
		return FALSE;
	}
	
return TRUE;
}


bool_t isAge(char* arr) {

size_t size = strlen(arr);




}

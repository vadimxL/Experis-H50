#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER 2048


int nLastLines(char* fName, int n);

int main() {


nLastLines("Alice2.txt", 3);
	


return 0;
}


int nLastLines(char* fName, int n) {

	char line[BUFFER];
   int count=0;
   int i;
	int* pos = (int*)malloc(n*sizeof(int));
	FILE* fp = fopen(fName, "r");
	if(fp == NULL) return 0;
	
	
	while( 1 ) {
		if ( fgets(line, BUFFER, fp) == NULL) break;
		count++;
		pos[count % n] = ftell(fp); // insert the position into pos variables
	}
	
	// for(i = 0; i < n; i++) printf("%d\n",pos[i]);

	fseek(fp,pos[(count+1) % n],0); // seek the last line - n
	
	while( 1 ) {
	
		if ( fgets(line, BUFFER, fp) == NULL) break;
		printf("%s", line );
		
	}
	fclose(fp);
	
return 1;
}

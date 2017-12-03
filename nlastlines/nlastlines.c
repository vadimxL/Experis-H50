#include <stdio.h>
#include <string.h>


int nLastLines(char* fName, int n);

int main() {


nLastLines("Alice.txt", 5);
	


return 0;
}


int nLastLines(char* fName, int n) {
	int pos, lines=0;
	char ch;
	FILE* fp = fopen(fName, "r");
	if(fp == NULL) return 0;
	
	fseek(fp,0,SEEK_END); // put the position at end of file
	pos = ftell(fp); // insert the position into pos variable
	
	
	while(1) {
	
	if( ftell(fp) == 0 ) 
		break;
		
	ch = fgetc(fp);
	fseek(fp,-2,SEEK_CUR);
	
	if( ch == '\n' )
		lines++;
	
	if (lines==n)
		break;
		
	}
	
	putchar(ch);
	
return 1;
}

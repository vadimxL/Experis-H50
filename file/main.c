#include <stdio.h>

int main() {


	FILE* fp;

	fp = fopen("testFile.c","r+");

	if(fp != NULL) 
		printf("Open file succeded\n");
		
		
	fprintf(fp,"Vadim is the greatest!\n");
	
	fclose(fp);

return 0;

}

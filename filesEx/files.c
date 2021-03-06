#include "files.h"
#define BUFFER 1024

struct WA {
	word* WAptr;
	size_t size;
	size_t numOfWords;
};

struct word {
	char name[BUFFER];
	int repeats;
};


Err countLetters(char* fName) {
	FILE* fp;
	int capLetters['Z'-'A'+1] = {0}; // initialize the array
	int letters['z'-'a'+1] = {0}; // initialize the array
	char ch;
	int i;
	
	if( fName == NULL ) return PTR_NOT_INIT;
	fp = fopen(fName, "r");
	if(fp == NULL) return PTR_NOT_INIT;

	while(1) {
	
		ch = fgetc(fp);
	
		if(ch == EOF) break;
	
		if( ch >= 'A' && ch <= 'Z' ) capLetters[ch - 'A']++; // counting capital letters
	
		if( ch >= 'a' && ch <= 'z' )  letters[ch - 'a']++; // counting lowercase letters
	}

	
	for(i=0; i <= 'Z'-'A'; i++) printf("%c:     %d \n", 'A'+i ,capLetters[i] ); // Printing capital letters
	printf("\n\n\n");
	for(i=0; i <= 'z'-'a'; i++) printf("%c:     %d \n", 'a'+i ,letters[i] );  // Printing lowercase letters
			
return OK;
}






Err countWords(char* someText) {

	FILE* fp;
	FILE* fp2;
	int count=0,cnt;
	char nameOfFile[BUFFER];
	char word[BUFFER];
	char tmpWord[BUFFER];


	if( someText == NULL ) return PTR_NOT_INIT;
	
	fp = fopen(someText, "r");
	if(fp == NULL) return PTR_NOT_INIT;
	
	fscanf(fp, "%s %s", nameOfFile, word);
	
	fp2 = fopen(nameOfFile,"r");
	if(fp2 == NULL) return PTR_NOT_INIT;
	
	while(1) {
		cnt = fscanf(fp2," %s",tmpWord);
		if( cnt == EOF ) break;
		if ( strcmp(tmpWord,word) == 0 ) count++;
	}
	
	printf("In file %s the word %s appears %d times\n", nameOfFile, word, count);
	fclose(fp);
	fclose(fp2);
	return OK;
}


Err wordsFrequency(char* fName) {

	FILE* fp;
	FILE* fpGhost;
	char tmpWord[BUFFER];

	int i,cnt,count=0;
	word* tmpWordPtr;


	WA* ptr = (WA*)malloc(sizeof(WA));
	if (ptr == NULL) return PTR_NOT_INIT; 

	ptr->WAptr = (word*)malloc(BUFFER*sizeof(word));
	if (ptr->WAptr == NULL) return PTR_NOT_INIT;
		
	ptr->size = BUFFER;
	ptr->numOfWords = 0;
	
	fp = fopen(fName, "r");
	
	if( fp == NULL || fpGhost == NULL ) return PTR_NOT_INIT;
	
	while(1) {

		if( ptr->numOfWords == ptr->size ) {
			tmpWordPtr = (word*)realloc(ptr->WAptr, 2*(ptr->size)*sizeof(word));
			if( tmpWordPtr != NULL ) {
				ptr->WAptr = tmpWordPtr;
				ptr->size*=2;
			}
		else
			return REALLOC_FAIL;
		}
		
		count=0;		
		
		cnt = fscanf(fp,"%s",tmpWord);
		if( cnt == EOF ) break;

		if(ptr->numOfWords==0) {
			strcpy(ptr->WAptr[ptr->numOfWords].name, tmpWord);
			ptr->numOfWords++;
			continue;
		}
		
		for(i=0; i<ptr->numOfWords; i++) {
			if(strcmp(ptr->WAptr[i].name, tmpWord) == 0) {
				ptr->WAptr[i].repeats++;
				count++;
			}
		}
		if(count == 0) {
			strcpy(ptr->WAptr[ptr->numOfWords].name, tmpWord);
			ptr->numOfWords++;
		}
	}
	
	for(i = 0; i < ptr->numOfWords ; i++)
		printf("%s:        	%d\n", ptr->WAptr[i].name, ptr->WAptr[i].repeats+1);

	fclose(fp);
	free(ptr);
	free(ptr->WAptr);

return OK;
}




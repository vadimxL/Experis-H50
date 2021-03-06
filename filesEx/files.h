#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum { OK=50, PTR_NOT_INIT, REALLOC_FAIL} Err;
typedef struct WA WA;
typedef struct word word;


/* 
** description: Counting letters
** input: 		pointer to string with file name
** 					
** output: 		Err
** notes: 		checks for NULL pointers
** 				
** Error:      PTR_NOT_INIT
*/
Err countLetters(char* fName);



/* 
** description: Counting words
** input: 		pointer to string with file name
** 					
** output: 		Err
** notes: 		checks for NULL pointers
** 				
** Error:      PTR_NOT_INIT
*/
Err countWords(char* someText);


/* 
** description: Repeating words
** input: 		pointer to string with file name
** 					
** output: 		Err
** notes: 		checks for NULL pointers
** 				
** Error:      PTR_NOT_INIT
*/
Err wordsFrequency(char* fName);

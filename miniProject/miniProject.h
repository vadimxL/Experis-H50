#include <stdlib.h> // size_t


typedef struct AD AD;
typedef struct meeting meeting;

typedef enum ADErr { AD_OK=50, PTR_NOT_INIT, DATA_OVERFLOW, REALLOC_FAIL, DATA_UNDERFLOW, NO_MEETING_FOUND, MEETING_REMOVED, 
						   MEETING_OVERLAP, MEETING_NOT_OVERLAP, INSERT_SUCCESS,ALLOC_SUCCESS } ADErr;



/* 
** description: allocate memory for diary member and meetings array.
** input: 		Void.
** 					
** output: 		allocation success  - handler to the dynamic array.
** 				allocation fail 	- NULL.
** notes: 		1. the responsibility to destroyDA after use it is on the user.				
*/
AD* createAD(); 

			


/* 
** description: create struct of meeting type.
** input: 		startTime - end time of meeting, float format.
**              endTime - end time of meeting, float format.
				room - room number.s
** 					
** output: 		allocation success  - ALLOC_SUCCESS.
** 				allocation fail 	- PTR_NOT_INIT.
** notes: 		1.
** 				2.
** Error:      PTR_NOT_INIT, ALLOC_SUCCESS
*/
ADErr createMeeting(AD* ptr, float startTime, float endTime, size_t room);


/* 
** description: Destroying diary
** input: 		pointer to diary struct
** 					
** output: 		Void
** notes: 		1. Diary default size is 10
** 				2. checks for NULL pointers
** Error:      No Erros
*/

void destroyAD(AD* ptr);			


/* 
** Description: Insert member to the end of structure, heavy usage of realloc function
** Input: pointer to pointer, value, size of structure, number of elements, how much to increase
** Ouput: Status of a function
** Error: DATA_OVERFLOW, REALLOC_FAIL,PTR_NOT_INIT
*/ 
ADErr insertMeeting(AD* ptr);	
	
		
/* 
** description: create struct of meeting type.
** input: 		startTime - end time of meeting, float format.
**             endTime - end time of meeting, float format.
					room - room number.s
** 					
** output: 		allocation success  - handler to the dynamic array.
** 				allocation fail 	- null.
** notes: 		1. if both input arguments are zero, function return null.
** 				2. the responsibility to destroyDA after use it is on the user.
*/   
ADErr removeMeeting(AD* ptr, float startTime);	


/*
 Description: Prints the contents DA
 Input: pointer to DA
 Output: void
 Error: No Error
*/
void printAD(AD* ptr);




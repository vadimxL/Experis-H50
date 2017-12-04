#define DA_OK 0
#define PTR_NOT_INIT -1
#define DATA_OVERFLOW -2
#define REALLOC_FAIL -3
#define DATA_UNDERFLOW -4

/* 
 Description: function gets size and returns pointer to the memory allocation,
 Input: number of elements, size can be ZERO!
 Output: ptr to first member of memory allocation 
 Error: returns NULL
*/
int* createDa(size_t size); 


/* 
 Description: frees the allocation memory!, if NULL do nothing!
 Input: Pointer;
 Output: no Output 
 Error: No check
*/												         
void destroyDa(int* ptr);			


/* 
 Description: Insert member to the end of structure, heavy usage of realloc function
 Input: pointer to pointer, value, size of structure, number of elements, how much to increase
 Ouput: Status of a function
 Error: DATA_OVERFLOW, REALLOC_FAIL,PTR_NOT_INIT
*/ 
int insertDa(int **ptr, int data, size_t* size, size_t* numOfElements, size_t incrBlockSize);		
	
		
/*
 Description: Removes member from the end of structure
 Input: pointer to structure, size of structure, number of elements
 Output: status of a function  
 Error: DATA_UNDERFLOW
*/    
int removeDa(int *ptr, int *data, size_t *numOfElements);	





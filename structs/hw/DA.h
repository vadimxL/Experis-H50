
typedef struct DA DA;

typedef enum DAErr { DA_OK=0, PTR_NOT_INIT, DATA_OVERFLOW, REALLOC_FAIL, DATA_UNDERFLOW } DAErr;


/* 
 Description: Function creates DA,
 Input: size of DA and value of how much to increase DA size!
 Output: ptr to DA struct
 Error: returns NULL
*/
DA* createDa(size_t size, size_t incrBlockSize); 


/* 
 Description: frees the memory of DA struct and memory of array!, if NULL do nothing!
 Input: Pointer;
 Output: no Output 
 Error: No check
*/												         
void destroyDa(DA* ptr);			


/* 
 Description: Insert member to the end of structure, heavy usage of realloc function
 Input: pointer to pointer, value, size of structure, number of elements, how much to increase
 Ouput: Status of a function
 Error: DATA_OVERFLOW, REALLOC_FAIL,PTR_NOT_INIT
*/ 
DAErr insertDa(DA* ptr, int data);		
	
		
/*
 Description: Removes member from the end of structure
 Input: pointer to structure, size of structure, number of elements
 Output: status of a function  
 Error: DATA_UNDERFLOW, PTR_NOT_INIT
*/    
DAErr removeDa(DA *ptr, int *data);	


/*
 Description: Prints the contents DA
 Input: pointer to DA
 Output: void
 Error: No Error
*/
void printDa(DA* ptr);





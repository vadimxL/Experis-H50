#include <stdio.h>
#include <stdlib.h> // size_t
#include "DA.h"


struct DA {
	int* DAptr;
	size_t size;
	size_t numOfElements;
	size_t incrBlockSize;
};

void printDa(DA* ptr);


DA* createDa(size_t size, size_t incrBlockSize) {

		if( ( size == 0 ) && (incrBlockSize == 0) )
			return NULL;
			
		DA* ptr = (DA*)malloc(sizeof(DA));
		if (ptr == NULL) return NULL; 

		ptr->DAptr = (int*)malloc(size*sizeof(int));
		if (ptr->DAptr == NULL) return NULL;
		
		ptr->size = size;
		ptr->numOfElements = 0;
		ptr->incrBlockSize = incrBlockSize;
		
		return ptr;
}

void destroyDa(DA* ptr) {

	if ( ptr->DAptr != NULL ) 
		free(ptr->DAptr);
	if ( ptr != NULL ) 
		free(ptr);
}

DAErr insertDa(DA* ptr, int data) {
int* temp;

	if(ptr == NULL || ptr->DAptr == NULL )
		return PTR_NOT_INIT;
	
	if( ptr->numOfElements > ptr->size  )
		return DATA_OVERFLOW;
	
	if( ptr->numOfElements == ptr->size ) {
	
		if (ptr->incrBlockSize == 0) {
			return DATA_OVERFLOW;
		}
	
		temp = (int*)realloc(ptr->DAptr, ( (ptr->size)+(ptr->incrBlockSize))*sizeof(int) );
		if( temp != NULL ) {
			ptr->DAptr = temp;
			ptr->size += ptr->incrBlockSize;
		}
		else
			return REALLOC_FAIL;
	}

	*( (ptr->DAptr)+(ptr->numOfElements) ) = data;
	(ptr->numOfElements)++;
	
	
	return DA_OK;
}

DAErr removeDa(DA* ptr, int *data) {

	if(ptr == NULL || ptr->DAptr == NULL || data == NULL)
		return PTR_NOT_INIT;
		
	if (ptr->numOfElements == 0)
		return DATA_UNDERFLOW;
		
	(*data) = *(ptr->DAptr+ptr->numOfElements-1);
	(ptr->numOfElements)--;
	
	return DA_OK;
}


void printDa(DA* ptr) {
	printf("----------------- Printing an DA ----------------------\n\n");	
	printf("{ ");
	for(int i=0; i < ptr->numOfElements; i++) {
		printf("%d ", *((ptr->DAptr)+i));
	}
	printf(" }");
	printf("\n\n-------------------------------------------------------\n\n\n");
}


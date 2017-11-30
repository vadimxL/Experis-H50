#include <stdio.h>
#include <stdlib.h>
#include "dynAlloc.h"



int* createDa(size_t size) {

		return (int*)malloc(size*sizeof(int));
}

void destroyDa(int *ptr) {
	if (ptr != NULL) free(ptr);
}

int insertDa(int **ptr, int data, size_t* size, size_t* numOfElements, size_t incrBlockSize) {
int* temp;

	if(ptr == NULL || *ptr == NULL || size == NULL || numOfElements == NULL)
		return PTR_NOT_INIT;
	
	if( *numOfElements > *size  )
		return DATA_OVERFLOW;
	
	if( *numOfElements == *size ) {
	
		if (incrBlockSize == 0) {
			return DATA_OVERFLOW;
		}
	
		temp = (int*)realloc(*ptr, (*size+incrBlockSize)*sizeof(int) );
		if( temp != NULL ) {
			*ptr = temp;
			(*size) += incrBlockSize;
		}
		else
			return REALLOC_FAIL;
	}

	*(*ptr+*numOfElements) = data;
	(*numOfElements)++;
	
	
	return DA_OK;
}

int removeDa(int *ptr, int *data, size_t* numOfElements) {

	if(ptr == NULL || data == NULL || numOfElements == NULL )
		return PTR_NOT_INIT;
		
	if (numOfElements == 0)
		return DATA_UNDERFLOW;
		
	(*data) = *(ptr+(*numOfElements)-1);
	(*numOfElements)--;
	
	return DA_OK;
}


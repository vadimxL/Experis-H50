#include <stdio.h>
#include "weekendHW.h"
#define INT_SIZE 4

void swap(int* x, int* y);
int countRepeats(int arr[], int size, int place);
int onePassSort(int arr[], int size);
int findEven(int arr[], int size);
int onePassEvenOddSort(int arr[], int size);
int checkArray(int arr[], int size);


int mostPopular (int arr[], int size) {

	if(checkArray(arr, size) == ARRAY_OK) {
		int i,length,tmpRepeats,newRepeats,popularNum;
	
		length = size/INT_SIZE;
	
		for(i=0; i<length; i++) {
			tmpRepeats = countRepeats(arr+i, size, i);
			if(tmpRepeats >= newRepeats) {
				newRepeats = tmpRepeats;
				popularNum = arr[i+1];
			}
		}

	return popularNum;
	}
	else {
		return ARRAY_ERROR;
	}

}


int bubbleSort (int arr[], int size) {

	if(checkArray(arr, size) == ARRAY_OK) {
		int i,length;
		length = size/INT_SIZE;
	
		while (onePassSort(arr,size)) {
			size -= INT_SIZE;
		}
		return ARRAY_OK;
	}
	else {
		return ARRAY_ERROR;
	}
}



int sortEvenOdd (int arr[], int size) {
	if(checkArray(arr,size) == ARRAY_OK) {
		int i, length;
		length = size/INT_SIZE;
	
		while (onePassEvenOddSort(arr, size) ) {
			size -= INT_SIZE;
		}
	}
	else {
		return ARRAY_ERROR;
	}
}


/* Additional helping functions */


void swap(int* x, int* y) {
	int temp;
	temp =*x;
	*x=*y;
	*y=temp;
}

int countRepeats(int arr[], int size, int place) {
 	int i,counter=0,length;
 	length = size/INT_SIZE;
 	for (i=0;i<length;i++) {
 		if (arr[place] == arr[i]) {
 			counter++;
 		}
 	}
 	return counter;
}

int onePassSort(int arr[], int size) {
	int i,length,counter=0;
	length = size/INT_SIZE;
	for (i=0; i<length-1; i++) {
		if(arr[i] > arr[i+1]) {
			swap(&arr[i], &arr[i+1]);
			counter++;
		}
	}
	return counter;
}

int onePassEvenOddSort(int arr[], int size) {
	int i,length,counter=0;
	length = size/INT_SIZE;
	for (i=0; i<length-1; i++) {
		if(arr[i] % 2 && !(arr[i+1] % 2)) {
			swap(&arr[i], &arr[i+1]);
			counter++;
		}
	}
	return counter;
}

int findEven(int arr[], int size) {
	int i, length, Odd;
	length = size/INT_SIZE;
	
	for(i=0; i<length; i++) {
		if( !(arr[i] % 2) ) {
			return i;
		}
	}
	return 0;
}

int checkArray(int arr[], int size) {
	if(arr == NULL) {
		return ARRAY_ERROR;
	}
	else {
		return ARRAY_OK;
	}
}
			
	

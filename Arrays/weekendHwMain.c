#include <stdio.h>
#include "weekendHW.h"
#define INT_SIZE 4

void printArray(int arr[], int size);

int main() {
	
	int type;
	int arr[] = {1,1,1,1,1,1,1,1,1,1,1,1,2,3,4,5,5,5,5,5,5,6,7,8,9};
	int arr2[] = {1,5,2,3,1,1,1,4,9,5,3,6,2,3,0,9,4,3,2,1};
	
	printf("This program is maniulating an array and prints choosed action to screen!\n");	
	printf("Choose action:\n 1: Prints the original array \n 2: Print most popular number in array \n 3: Sort the array\n 4: Sort Even+Odd\n");
	scanf("%d", &type);

	switch (type) {
		case 1:
			printf("The original array:\n");
			printArray(arr2,sizeof(arr2));
			break;
		case 2:
			printf("Print the most popular number in Array\n");
			printf("%d\n", mostPopular(arr2, sizeof(arr2)) );
			break;
		case 3:
			bubbleSort(arr2,sizeof(arr2));
			printf("Bubble sorting\n");
			printArray(arr2, sizeof(arr2));
			break;
		case 4:
			sortEvenOdd(arr2,sizeof(arr2));
			printf("Sort Even at start and Odd later in Array\n");
			printArray(arr2, sizeof(arr2));
			break;
	}

	return 0;


}


void printArray(int arr[], int size) {
	int i,length;
	length = size/INT_SIZE;
	printf("{ ");
	for(i=0; i<length;i++) {
		printf("%d, ",arr[i]);
	}
	printf(" }");
	printf("\n\n");
}

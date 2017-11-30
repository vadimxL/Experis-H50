#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct person {
	int id;
	int age;
	char name[20];
	int education;
} person;

int  addPerson(person* ptr);
void swapPerson(person* x, person* y);
int bubbleSortById (person* ptr, size_t size);
int bubbleSortByName (person* ptr, size_t size);
int onePassPersonById(person* ptr, size_t size);
int onePassPersonByName(person* ptr, size_t size);


int main() {




/* 
	
	Code for testing that functions are working...	

	size_t size = 2;
	int i;
	person ppl[size];
	
	strcpy(ppl->name, "Malinovsky");
	strcpy((ppl+1)->name, "Vadim");
	
	printf("%s %s\n", ppl->name, (ppl+1)->name );
	
	printf("Applying sort by name!\n");
	bubbleSortByName(ppl, size);

	printf("%s %s\n", ppl->name, (ppl+1)->name );


	printf("%s\n", ppl->name );
	printf("%s\n", (ppl+1)->name );
	
	bubbleSortById (ppl, size);	
	
	for(i=0; i<size; i++)
		(ppl+i)->id = (size-i);
		
	for(i=0; i<size; i++)
		printf("%d ", (ppl+i)->id);	

*/	
	



return 0;
}

int  addPerson(person* ptr) {
	
	printf("Insert name:\n");
	scanf("%s", ptr->name);
	
	printf("Insert age:\n");
	scanf("%d", &(ptr->age));
	
	printf("Insert id:\n");
	scanf("%d", &(ptr->id));
	
	printf("Insert education:\n");
	scanf("%d", &(ptr->education));

}


void swapPerson(person* x, person* y) {
	person temp;
	temp =*x;
	*x=*y;
	*y=temp;
}

int bubbleSortById (person* ptr, size_t size) {

	while ( onePassPersonById(ptr, size) ) size--;

}

int bubbleSortByName (person* ptr, size_t size) {

	while ( onePassPersonByName(ptr, size) ) size--;

}

int onePassPersonById(person* ptr, size_t size) {
	int i, counter=0;
	for (i=0; i<size-1; i++) {
		if( (ptr+i)->id > (ptr+i+1)->id ) {
			swapPerson(ptr+i, ptr+i+1);
			counter++;
		}
	}
	return counter;
}


int onePassPersonByName(person* ptr, size_t size) {
	int i, counter=0;
	for (i=0; i<size-1; i++) {
		if( strcmp( (ptr+i)->name, (ptr+i+1)->name ) < 0 ) {
			swapPerson(ptr+i, ptr+i+1);
			counter++;
		}
	}
	return counter;
}




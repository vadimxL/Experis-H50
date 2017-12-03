#include <stdio.h>
#include <string.h>
#include "miniProject.h"
#define EXIT 9

typedef enum {FALSE=0, TRUE} bool_t;

int main() {

float startTime, endTime, removeTime;
size_t room, size = 9;
char choiceStr[200];
char fName[200];
int choice;
AD* ptr = NULL;
char* choicePrint[] = { "1. Create diary",   "2. Create meeting",  "3. Insert meeting",
						      "4. Remove meeting", "5. Destroy diary",   "6. Print diary", 
						      "7. Save to file",   "8. Load from file",  "9. Exit the program" } ;


while( choice != EXIT ) {


	puts("-------------- Diary Menu: ----------------");
	printf("Choose what you want to do from 1 to %lu \n", size); 
	for(int i = 0; i< size; i++) printf("%s%c", choicePrint[i], '\n' ); 
	puts("Please choose:");
		
	
	scanf("%s",choiceStr);
	choice = atoi(choiceStr);
	
	if ( choice < 1 || choice > EXIT ) {
		printf("Invalid Input\n\n");
	}

	switch (choice) {
		case 1:
			ptr = createAD();
			if(ptr == NULL) printf("Failed to create Diary");
			printf("Daily Diary created\n\n");
			break;
		case 2:
			printf("Choose start time of meeting:\n");
			scanf("%f", &startTime);
			printf("Choose end time of meeting:\n");
			scanf("%f", &endTime);
			printf("Choose meeting room:\n");
			scanf("%lu", &room);
	    	createMeeting(ptr,startTime,endTime,room);
			break;
		case 3:
			if( insertMeeting(ptr) == PTR_NOT_INIT ) {
				puts("diary is null");
				break;
			}
			printf("Meeting inserted\n\n");
			break;
		case 4:
			printf("Choose start time of meeting you want to remove:\n");
			scanf("%f", &removeTime);
			if ( removeMeeting(ptr,removeTime) == NO_MEETING_FOUND) {
				printf("No Meeting found\n");
				break;
			}
			removeMeeting(ptr,removeTime);			
			printf("Meeting removed\n");
			break;
		case 5:
			destroyAD(ptr);
			printf("Diary destroyed!\n");
			break;
		case 6:
			printAD(ptr);
			break;
		case 7:
			scanf("Please enter the name of file: %s\n",fName);
			saveToFile(ptr, fName);
			printf("Saved to a file!\n");
			break; 	 	
		case 8:
			loadFromFile(ptr);
			printf("Loaded from a file!\n");
			break;
		case 9:	
			printf("Exiting the program\n");
			break;
	}
}	
return 0;
}

/*

	printf("First create a diary\n\n");
	printf("First create a meeting\n\n");
	printf("First insert a meeting\n\n");

*/

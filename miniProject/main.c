#include <stdio.h>
#include <string.h>
#include "miniProject.h"
#define EXIT 8

typedef enum bool_t {FALSE=0, TRUE} bool_t;

int main() {

float startTime, endTime, removeTime;
size_t room;
int create_DA = FALSE, create_Meet = FALSE, insert_Meet = FALSE;
char choiceStr[200];
int choice;
AD* ptr;

 
while( choice != EXIT ) {

	printf("\n\n\n*******************  Daily Diary *************************** \n\n\n");
	printf("-------------- Diary Menu: ---------------- \n\n");
	printf("Choose what you want to do from 1 to 7 \n\n");
	printf("1. Create diary \n2. Create meeting \n3. Insert meeting \n4. Remove meeting \n"); 
    printf("5. Destroy Diary \n6. Print Diary \n7. Save to file \n8. Exit the program \n\n\n");     
	printf("------------------------------------------- \n");
	printf("Please choose:");
	scanf("%s",choiceStr);
	choice = atoi(choiceStr);
	
	if ( choice < 1 || choice > 8 ) {
		printf("Invalid Input\n\n");
	}

	switch (choice) {
		case 1:
			ptr = createAD();
			if(ptr == NULL) printf("Failed to create Diary");
			create_DA = TRUE;
			printf("Daily Diary created\n\n");
			break;
		case 2:
			if (create_DA == TRUE) {
				printf("Choose start time of meeting:\n");
				scanf("%f", &startTime);
				printf("Choose end time of meeting:\n");
				scanf("%f", &endTime);
				printf("Choose meeting room:\n");
				scanf("%lu", &room);

		    	createMeeting(ptr,startTime,endTime,room);
				create_Meet = TRUE;
			}	 
			else printf("First create a diary\n\n");
			break;
		case 3:
			if (create_DA == FALSE ) {
			 printf("First create a diary\n\n");
			 break;
			}
			
			if (create_Meet == FALSE) {
			 printf("First create a meeting\n\n");
			 break;
			}		
			insertMeeting(ptr);
			insert_Meet = TRUE;
			printf("Meeting inserted\n\n");
			break;
		case 4:
			if (create_DA == FALSE ) {
			 printf("First create a diary\n\n");
			 break;
			}
			if (create_Meet == FALSE) {
			 printf("First create a meeting\n\n");
			 break;
			}
			if (insert_Meet == FALSE) {
			 printf("First insert a meeting\n\n");
			 break;
			}
			
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
			if (create_DA == FALSE ) {
			 printf("First create a diary\n\n");
			 break;
			}
			destroyAD(ptr);
			printf("Diary destroyed!\n");
			break;
		case 6:
			if (create_DA == FALSE ) {
			 printf("First create a diary\n\n");
			 break;
			}
			printAD(ptr);
			printf("\n");
			break;
		case 7:
			if (create_DA == FALSE ) {
				printf("First create a diary\n\n");
				break;
			}
			if (create_Meet == FALSE) {
				printf("First create a meeting\n\n");
				break;
			}
			if (insert_Meet == FALSE) {
				printf("First insert a meeting\n\n");
				break;
			}
			saveToFile(ptr);
			printf("Saved to a file!\n");
			break; 	 	
				
		case 8:	
			printf("Exiting the program\n");
			break;
	}
}	

return 0;

}

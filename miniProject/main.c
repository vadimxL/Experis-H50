#include <stdio.h>
<<<<<<< HEAD
#include <string.h>
#include "miniProject.h"
#define EXIT 7

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
   printf("5. Destroy Diary \n6. Print Diary \n7. Exit Program \n\n\n");     
	printf("------------------------------------------- \n");
	printf("Please choose:");
	scanf("%s",choiceStr);
	choice = atoi(choiceStr);
	
	if ( choice < 1 || choice > 7 ) {
		printf("Invalid Input\n\n");
	}
	
	for(int i = 0; i<50; i++)
		printf("\n");

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
			printf("Exiting the program\n");
	}
}	

return 0;

}
=======
#include "miniProject.h"
#define PASS 1
#define FAIL 0


int test1(); // Test for meeting overlap
int test2(); // Test for inserting meetings

int main() {


	// printf("Test 1 is %s\n", test1() ? "PASS" : "FAIL" );
	   test2();


	

return 0;
}


/* Testing for meeting overlap */
int test1() {


	AD* ptr = createAD();

	createMeeting(ptr, 10, 11, 450);
	insertMeeting(ptr);
	createMeeting(ptr, 11.3, 11.8, 455);
	insertMeeting(ptr);
	createMeeting(ptr, 10.5, 11.7, 460);
	insertMeeting(ptr);

	if (insertMeeting(ptr) == MEETING_OVERLAP) {
		destroyAD(ptr);
		return PASS;
		}
	destroyAD(ptr);
	return FAIL;
}

int test2() {


	AD* ptr = createAD();


	createMeeting(ptr, 10, 11, 450);
	insertMeeting(ptr);
	createMeeting(ptr, 11.3, 11.8, 455);
	insertMeeting(ptr);
	createMeeting(ptr, 12, 12.5, 460);
	insertMeeting(ptr);
	removeMeeting(ptr, 10);
	printAD(ptr);
	destroyAD(ptr);	
	

return 0;
}



>>>>>>> 9acbcd566d018423c10143106dcc8aa9ffa3643c

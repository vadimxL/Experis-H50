#include <stdio.h>
#include <stdlib.h> // size_t
#include "miniProject.h"
#define SIZE 10


struct AD {
	FILE* fp;
	meeting** ADptr;
	meeting* tmpMeeting;
	size_t size;
	size_t numOfMeetings;
	size_t incrMeetingsNum;
};

struct meeting {
	float startTime;
	float endTime;
	size_t room;
};


int findMeeting(AD* ptr, float startTime);
int findMeetingForInsert(AD* ptr);
int checkOverlap (AD* ptr);
void shiftAndInsert(AD* ptr,int index);

AD* createAD() {

		AD* ptr = (AD*)malloc(sizeof(AD));
		if (ptr == NULL) return NULL; 

		ptr->ADptr = (meeting**)malloc(SIZE*sizeof(meeting*));
		if (ptr->ADptr == NULL) return NULL;
		
		ptr->size = SIZE;
		ptr->numOfMeetings = 0;
		ptr->incrMeetingsNum = 10;
		
		return ptr;
}

ADErr createMeeting(AD* ptr, float startTime, float endTime, size_t room) {
	

	if(ptr == NULL) return PTR_NOT_INIT;
	
	meeting* newMeeting = (meeting*)malloc(sizeof(meeting));
		if (newMeeting == NULL) return PTR_NOT_INIT; 
	
	newMeeting->startTime = startTime;
	newMeeting->endTime = endTime;
	newMeeting->room = room;

	ptr->tmpMeeting = newMeeting;

	return ALLOC_SUCCESS;
}

void destroyAD(AD* ptr) {

	if ( ptr->ADptr != NULL ) 
		free(ptr->ADptr);
	if ( ptr != NULL ) 
		free(ptr);
}

ADErr insertMeeting(AD* ptr) {

int indexOfMeeting;

meeting** tmpMeetingPtr;

	if(ptr == NULL || ptr->ADptr == NULL || ptr->tmpMeeting == NULL )
		return PTR_NOT_INIT;


	if( ptr->numOfMeetings == ptr->size ) {
		tmpMeetingPtr = (meeting**)realloc(ptr->ADptr, ((ptr->size)+(ptr->incrMeetingsNum))*sizeof(meeting*));
		if( tmpMeetingPtr != NULL ) {
			ptr->ADptr = tmpMeetingPtr;
			ptr->size += ptr->incrMeetingsNum;
		}
		else
			return REALLOC_FAIL;
	}

	if (ptr->numOfMeetings == 0) {
		shiftAndInsert(ptr,ptr->numOfMeetings);
		return INSERT_SUCCESS;
	}
		
		
	if( ptr->numOfMeetings > 0 ) {

		if( checkOverlap(ptr) == MEETING_OVERLAP )
			return MEETING_OVERLAP;

		shiftAndInsert(ptr, findMeetingForInsert(ptr) );
			return INSERT_SUCCESS;
	}
 
}

ADErr removeMeeting(AD* ptr, float startTime) {
int i, indexOfMeeting;
	
	if(ptr == NULL || ptr->ADptr == NULL )
		return PTR_NOT_INIT;
		
	if (ptr->numOfMeetings == 0)
		return DATA_UNDERFLOW;
	
	indexOfMeeting = findMeeting(ptr, startTime);
	
	if(indexOfMeeting == NO_MEETING_FOUND)
		return NO_MEETING_FOUND;
		
		
	if (indexOfMeeting != NO_MEETING_FOUND) {
	
		free(ptr->ADptr[indexOfMeeting]);
		
		for(i=indexOfMeeting; i < (ptr->numOfMeetings); i++) {
			ptr->ADptr[i] = ptr->ADptr[i+1];
		}
		(ptr->numOfMeetings)--;

	}
	
	return MEETING_REMOVED;
}

int findMeeting(AD* ptr, float startTime) {
		
	int index;
		
	for (index=0; index < ptr->numOfMeetings; index++) {
		if( ptr->ADptr[index]->startTime == startTime) return index;
	}
	return NO_MEETING_FOUND;
}

int findMeetingForInsert(AD* ptr) {

	int index;

		
	for (index=0; index < ptr->numOfMeetings; index++)
		if( !(ptr->ADptr[index]->startTime < ptr->tmpMeeting->startTime) ) return index;
		
}

int checkOverlap (AD* ptr) {
	int i;
	
	for(i=0; i < ptr->numOfMeetings; i++) {
	
		if ( !(ptr->tmpMeeting->startTime > ptr->ADptr[i]->endTime || ptr->tmpMeeting->endTime < ptr->ADptr[i]->startTime) )
			return  MEETING_OVERLAP; 
	} 
	return MEETING_NOT_OVERLAP;
}

void shiftAndInsert(AD* ptr,int index) {
	int i;
	for(i=ptr->numOfMeetings; i>index ; i--) {
		ptr->ADptr[i] = ptr->ADptr[i-1];
	}
	ptr->ADptr[index] = ptr->tmpMeeting;
	(ptr->numOfMeetings)++;
}


ADErr saveToFile(AD* ptr, char* fName) {
	
	int i;		
	if(ptr == NULL) return PTR_NOT_INIT;	
	FILE* fp = fopen(fName, "w");
	if(fp == NULL) return PTR_NOT_INIT;
	ptr->fp = fp;

	for(i=0; i < ptr->numOfMeetings; i++)
		fprintf(fp,"%f%f%lu\n",ptr->ADptr[i]->startTime,ptr->ADptr[i]->endTime,ptr->ADptr[i]->room);

	fclose(fp);
}

ADErr loadFromFile(AD* ptr) {
	float startTime, endTime;
	size_t room;
	int cnt;		
	if(ptr == NULL || ptr->ADptr == NULL) return PTR_NOT_INIT;	

	FILE* fp = fopen("dailyDiary.txt", "r");
	if(fp == NULL) return PTR_NOT_INIT;
	ptr->fp = fp;
	
	while(1) {	
		cnt = fscanf(fp,"%f %f %lu",&startTime,&endTime,&room);

		if (cnt != 3) {
			break;
		}
		
		if ( createMeeting(ptr, startTime,endTime,room) != ALLOC_SUCCESS ) return LOAD_FAIL;
		insertMeeting(ptr); 
	}
	fclose(fp);
	return LOAD_SUCCESS;
}


void printAD(AD* ptr) {
	printf("----------------- Printing an AD ----------------------\n\n");	
	for(int i=0; i < ptr->numOfMeetings; i++) {
		printf("%d meeting:\n\n", i+1);
		printf("start time is %f\n", ptr->ADptr[i]->startTime);
		printf("end time is %f\n", ptr->ADptr[i]->endTime);
		printf("room is %lu\n", ptr->ADptr[i]->room);
		printf("\n\n\n");
	}
	printf("\n\n-------------------------------------------------------\n\n\n");
}


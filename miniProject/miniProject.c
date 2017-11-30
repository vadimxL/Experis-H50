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

int indexOfMeeting, i;

meeting** tmpMeetingPtr;

	if(ptr == NULL || ptr->ADptr == NULL || ptr->tmpMeeting == NULL )
		return PTR_NOT_INIT;
		
	if( ptr->numOfMeetings > 0 ) {
	
		if( !(ptr->ADptr[0]->startTime > ptr->tmpMeeting->endTime || ptr->ADptr[ptr->numOfMeetings-1]->endTime < ptr->tmpMeeting->startTime) ) 
		
		{

			if( checkOverlap(ptr) == MEETING_OVERLAP )
				return MEETING_OVERLAP;
				
			if( ptr->numOfMeetings == ptr->size ) {
			tmpMeetingPtr = (meeting**)realloc(ptr->ADptr, ((ptr->size)+(ptr->incrMeetingsNum))*sizeof(meeting*));
			if( tmpMeetingPtr != NULL ) {
				ptr->ADptr = tmpMeetingPtr;
				ptr->size += ptr->incrMeetingsNum;
			}
			else
				return REALLOC_FAIL;
			}
			
			indexOfMeeting = findMeetingForInsert(ptr);
			
			if (indexOfMeeting != NO_MEETING_FOUND) {
				
				shiftAndInsert(ptr, indexOfMeeting);
				
			
				for(i=indexOfMeeting; i < (ptr->numOfMeetings); i++) {
					ptr->ADptr[i+1] = ptr->ADptr[i];
				}
				ptr->ADptr[indexOfMeeting] = ptr->tmpMeeting;
				
				(ptr->numOfMeetings)++;
				return INSERT_SUCCESS;
			}
		}
	} 

	if( ptr->numOfMeetings == ptr->size ) {
	
		tmpMeetingPtr = (meeting**)realloc(ptr->ADptr, ((ptr->size)+(ptr->incrMeetingsNum))*sizeof(meeting*));
		if( tmpMeetingPtr != NULL ) {
			ptr->ADptr = tmpMeetingPtr;
			ptr->size += ptr->incrMeetingsNum;
		}
		else
			return REALLOC_FAIL;
	}
	
	
	indexOfMeeting = findMeetingForInsert(ptr);
	shiftAndInsert(ptr, indexOfMeeting);
	ptr->ADptr[ptr->numOfMeetings] = ptr->tmpMeeting;
	(ptr->numOfMeetings)++;

	return INSERT_SUCCESS;
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
	
	if( ptr->numOfMeetings == 0)
		return 0;
		
	for (index=0; index < ptr->numOfMeetings; index++) {
		if( !(ptr->ADptr[index]->startTime < ptr->tmpMeeting->startTime) ) return index;
	}
		
	for (index=0; index < ptr->numOfMeetings; index++) {
		if( ptr->ADptr[index]->startTime > ptr->tmpMeeting->endTime) return index;
	}
	return NO_MEETING_FOUND;

}

int checkOverlap (AD* ptr) {
	int i;
	
	for(i=0; i < ptr->numOfMeetings; i++) {
	
		if ( ptr->tmpMeeting->startTime > ptr->ADptr[i]->endTime || ptr->tmpMeeting->endTime < ptr->ADptr[i]->startTime )
			return MEETING_NOT_OVERLAP;
		} 
	return MEETING_OVERLAP;
}

void shiftAndInsert(AD* ptr,int index) {
	int i;
	for(i=ptr->numOfMeetings; i>index ; i--) {
		ptr->ADptr[i] = ptr->ADptr[i-1];
	}
	ptr->ADptr[index] = ptr->tmpMeeting;
}


ADErr saveToFile(AD* ptr) {
	
	int i;		
	if(ptr == NULL) return PTR_NOT_INIT;	
	FILE* fp = fopen("dailyDiary.txt", "w");
	if(fp == NULL) return PTR_NOT_INIT;
	ptr->fp = fp;

	for(i=0; i < ptr->numOfMeetings; i++)
		fprintf(fp,"%f %f %lu\n",ptr->ADptr[i]->startTime,ptr->ADptr[i]->endTime,ptr->ADptr[i]->room);
}

ADErr loadFromFile(AD* ptr) {
	float startTime, endTime;
	size_t room;
	int i;		
	if(ptr == NULL) return PTR_NOT_INIT;	
	FILE* fp = fopen("dailyDiary.txt", "r");
	if(fp == NULL) return PTR_NOT_INIT;
	ptr->fp = fp;
	
	while(feof(fp)) {
		fscanf(fp,"%f %f %lu\n",&startTime,&endTime,&room);
		createMeeting(ptr, startTime,endTime,room);
		insertMeeting(ptr);
	}
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


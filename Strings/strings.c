#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "strings.h"
#define TRUE 1
#define FALSE 0


int swap(char* ch1, char* ch2);
int valid(char* str);                          // function that validates if a string is not a NULL


int reverseStr(char *str) {

   if( valid(str) != ERROR ) {		
		int size = strlen(str)-1;
		for(int i=0;i<strlen(str);i++) {
			for (int j=0;j<size;j++) {
			swap( &str[j], &str[j+1] );
			}
			size--;
		}
	}
return OK;
}


int isPolindrom(char *str) {
	int counter = 0; 
	if ( valid(str) != ERROR ) {
		for(int i = 0; i<strlen(str)/2 ;i++) {
			if( str[i] != str[strlen(str)-1-i] ) {
				counter++;
			}
		}
	
		if ( counter > 0 ) {
			return NOT_POLYNDROM;
		}
	}
		
return POLYNDROM;
}


int printBinary(size_t num) {
	int counter=0,power=1,tmpNum=num;
	while (tmpNum /= 2) {
		counter++;
		power *= 2;
	}
	for (int i=0; i<=counter; i++) {
		printf("%lu",num / power);
		num %= power;
		power /= 2;
	}
	printf("\n");
return OK;
}


int myatoi(char* str) {
	int num=0,isNegative=FALSE,nextSpace=FALSE;;
	if ( valid(str) != ERROR ) {
	
		if ( str[0] >= 'A' && str[0] <= 'z' ) {
			return 0;
		}
		
		for(int i=0; str[i] != '\0' ; i++) {	
		
			if(nextSpace==TRUE) break;
			
			switch(str[i]) {
			
			case ' ':
				break;
			
			case '-':
				if ( str[i+1] >= '0' && str[i+1] <= '9' ) {
					isNegative=TRUE;
				}
			case '+':
				break;
			
			default:
				if ( str[i] >= '0' && str[i] <= '9' )  {
					num = num*10 + (str[i] - '0');
					if(str[i+1] == ' ') nextSpace=TRUE;
				}
			}
		}

		if(isNegative == TRUE) {
			return -1*num;
		}
		
		return num;
	}
	
	return OK;
}


char* myitoa(int value, char * str) {
	int counter=0, base = 10;
	char ch;
	int isNegative = 0;
	
	if (value < 0) {
		value = -1* value;
		isNegative = 1;
	}
	
	do {
		ch = value % base + '0';
		str[counter] = ch;
		value /= base;
		counter++;
	} while (value > 0);
	
	if( isNegative ) {
		str[counter++] = '-';
	}
	
	reverseStr(str);
	str[counter] = '\0';
	printf("%s\n", str);
	
	return str;
}


char* myStrStr(char *s1, char *s2) {

	if ( valid(s1) || valid(s2) != ERROR ) {	
		char ch = '\0';
		int result=TRUE;

		for(int i = 0; i < strlen(s1)-strlen(s2); i++) {
			swap(s1+i+strlen(s2), &ch);
			result = strcmp(s1+i, s2);
			swap(s1+i+strlen(s2), &ch);
			if(result==FALSE) {
				return s1+i;
			}	
		}
	}
	
	return s2;
}

int swap(char* ch1, char* ch2) {
	char temp;
	temp =*ch1;
	*ch1=*ch2;
	*ch2=temp;
}

int valid(char* str) {
	if (str == NULL) {
		return ERROR;
	}
}


#include <stdio.h> 

void charIncrease (char ch, int length ) {
	int i,j;

	
	for ( i=0; i<length; i++ ) {
		for (j=0; j<=i; j++) {
			printf("%c", ch);
		}
		printf("\n");
	}
}

void charDecrease (char ch, int length ) {
	
	int i,j;

	for ( i=0; i<length; i++ ) {
		for (j=length; j>i; j--) {
			printf("%c", ch);
		}
		printf("\n");
	}
}

void charInDec (char ch, int length) {
	charIncrease(ch,length-1);
	charDecrease(ch,length);
}


void Pyramid (char ch, int length) {
	int i,j;

	for (i=0; i<length; i++) {

		for (j=length; j>i; j--) {                  /* using spaces to shift chars */
			printf(" ");
		}

		for (j=0; j<=i; j++) {								/*drawing chars */
			printf("%c ", ch);
		}
		printf("\n");
	}
}

void reversePyramid(char ch, int length) {
	int i,j;

	for (i=0; i<length; i++) {

		for (j=0; j<=i; j++) {
			printf(" ");
		}

		for (j=length; j>i; j--) {
			printf("%c ", ch);
		}
		printf("\n");
	}
}

void Rhombus (char ch, int length) {
	int i,j;

	for (i=0; i<length-1; i++) {

		for (j=length; j>i; j--) {
			printf(" ");
		}

		for (j=0; j<=i; j++) {
			printf("%c ", ch);
		}
		printf("\n");
	}


reversePyramid(ch, length);
}






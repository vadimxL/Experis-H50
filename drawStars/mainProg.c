#include <stdio.h>
#include "drawChars.h"

int main() {
	
	char ch;
	int length,type;
	printf("Enter character you want to draw: \n");
	scanf("%c", &ch);
	printf("Enter the length of a drawing: \n");
	scanf("%d", &length);
	printf(" 1 = Stairs \n 2 = Upside Down Stairs \n 3 = End of Arrow \n 4 = A pyramid \n 5 = Upside down pyramid \n 6 = A Rhombus \n\n\n");
	printf("Enter the type of drawing you want from 1-6 \n");
	scanf("%d", &type);
	printf("\n\n");
	

	switch (type) {
		case 1:
			charIncrease(ch , length);
			printf("\n");
			break;
		case 2:
			charDecrease (ch , length);
			printf("\n");
			break;
		case 3:
			charInDec (ch , length);
			printf("\n");
			break;
		case 4:
			Pyramid (ch, length);
			printf("\n");
			break;
		case 5:
			reversePyramid (ch, length);
			printf("\n");
			break;
		case 6:
			Rhombus (ch, length);
			printf("\n");
			break;
	}

	return 0;
}

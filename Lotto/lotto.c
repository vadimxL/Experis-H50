#include "lotto.h" /* our library file */
#define SIZE 6
#define LOTTOSIZE 49
#define M 5
#define N 10

Err lotto(char* fname) {

	FILE* fp;
	int randArr[SIZE];
	char lottoCard[LOTTOSIZE];
	int i,j,k;
	srand (time(NULL));
	
	fp = fopen(fname, "w+");
	if(fp == NULL) return PTR_NOT_INIT;
  	
    for(i = 0 ; i < LOTTOSIZE ; i++) {   
  		lottoCard[i] = '-';                  /* Init the array with '-' */
    }
 
	for(i = 0 ; i < SIZE ; i++) {
  		randArr[i] = rand()%49+1;        /* create array with random numbers */
    }
  
  
	for(k = 0 ; k < SIZE ; k++) {
  		lottoCard[randArr[k]-1] = '+';     /* filling the lotto card */
  	}
	
	fprintf(fp,"   ");
	for(i=0; i < N ; i++) fprintf(fp,"%d  ",i+1);
	fputc('\n',fp);

    for(i = 0 ; i < M ; i++) {
  		fprintf(fp,"%d  ", i);
  		for(j= 0 ; j < N ; j++) {
  			fprintf(fp,"%c  ", lottoCard[i*10+j]);
  		}
  		fputc('\n',fp);
  	}
  	
	fclose(fp);
	return OK;
}

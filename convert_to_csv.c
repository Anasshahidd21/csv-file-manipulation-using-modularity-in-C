#include "convert_to_csv.h"
#include<stdio.h>
#include<string.h>
#include <stdlib.h>


void load_and_convert(const char* filename){
	FILE *f1 = fopen(filename, "r");
	FILE *f2 = fopen("output.csv", "w+");
	char *saveptr1 = NULL;
	char *saveptr2 = NULL;
	char *saveptr3 = NULL;


	char line1[1000];
	fgets(line1,sizeof(line1), f1);
	line1[(strlen(line1)-1)]='\0';			//Last character is \n when fgets() is called
	

	char line2[1000];
	fgets(line2,sizeof(line2), f1);
	line2[(strlen(line2)-1)]='\0';			//Last character is \n when fgets() is called


	char line3[1000];
	fgets(line3,sizeof(line3), f1);
	
	

	char* token;
	char* token2;
	char* token3;


	token =  strtok_r(line1, " " , &saveptr1);
	token2 = strtok_r(line2, " " , &saveptr2);
	token3 = strtok_r(line3, " " , &saveptr3);

	


	while(token!=NULL && token2!=NULL && token3!=NULL){
		
		fprintf(f2, "%s, ", token );
		token = strtok_r(NULL, " " , &saveptr1);

		fprintf(f2, "%s, ", token2 );
		token2 = strtok_r(NULL, " " ,  &saveptr2);
		

		fprintf(f2, "%s\n", token3 );
		token3 = strtok_r(NULL, " " ,  &saveptr3);
	}

		fclose(f2);
		fclose(f1);
	
}

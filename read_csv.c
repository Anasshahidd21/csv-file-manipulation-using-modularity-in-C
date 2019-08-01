#include "read_csv.h"
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

void read_csv(const char* csv_filename){
	FILE *f1 = fopen(csv_filename, "r");
	
	char line[1000];

	while(fgets(line,sizeof(line),f1)!=NULL){
		printf("%s", line );
	}
	
	printf("\n");

	fclose(f1);
}
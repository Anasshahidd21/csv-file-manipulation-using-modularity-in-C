#include<stdio.h>
#include<string.h>
#include <stdlib.h>

#include"convert_to_csv.h"
#include"read_csv.h"

void find_name(const char* csv_filename, const char* name){
	FILE *f1 = fopen(csv_filename, "r");

	char line[1000];
	char *token;
	int found=0;

	 while(fgets(line,sizeof(line),f1)!=NULL){
	 	char *oldstr=malloc(sizeof(line));
	 	strcpy(oldstr,line);

	 	token =  strtok(line, ",");
		if (strcmp(token,name)==0)
		{
			found=1;
			printf("%s" , oldstr);
			free(oldstr);
			oldstr=NULL;
			
		}

		else
		{
			free(oldstr);
			oldstr = NULL;
		}

	}

	if (found!=1)
	{
		printf("\nSearching for records of %s in the list: \n",name );
		printf("Name not found\n\n");
	}

	fclose(f1);

}


void add_record(const char* csv_filename, const char* name, const int age, const char* city){

	FILE *f1 = fopen(csv_filename, "a");
	char line[1000];

	while(fgets(line,sizeof(line),f1)!=NULL){}
			if (fgets(line,sizeof(line),f1)==NULL)
			{
				fprintf(f1, "%s , %d ,%s\n", name, age, city);
			}

	fclose(f1);
}


void delete_record(const char* csv_filename, const char* name){
	FILE *f1 = fopen(csv_filename, "r");
	FILE *f2 = fopen("tempfile.csv", "w+");



	int isFirst=0;
	char line[1000];
	char line2[1000];
	char *token;
	char *p;
	char *saveptr;


	 while(fgets(line,sizeof(line),f1)!=NULL){
	 	char *oldstr=malloc(sizeof(line));
    	strcpy(oldstr,line);

	 	token =  strtok(line, ",");
	 	
			if (strcmp(token,name)==0)
			{
				
					if (isFirst==1)
					{
						fprintf(f2 , "%s", oldstr );
					}
					isFirst=1;
					free(oldstr);
					continue;
			}

			else{
				
				fprintf(f2 , "%s", oldstr );
				free(oldstr);
			}

	}

	fclose(f2);
	fclose(f1);



	FILE *f3 = fopen("tempfile.csv", "r");
	FILE *f4 = fopen(csv_filename, "w");
		
		while(fgets(line2,sizeof(line2),f3)!=NULL){
			fprintf(f4, "%s", line2 );

		}

	fclose(f3);
	fclose(f4);



}





int main ()
{
/* Question 1 */
load_and_convert( "input.txt" );

/* Question 2 */
 read_csv( "output.csv" );
// /* Question 3.1 
 find_name( "output.csv" , "Maria" );
 find_name( "output.csv" , "Jason" ); //Jason doesn't exist
// /* Question 3.2 
 add_record( "output.csv" , "Jason" , 36 , "Skookumchuk" );
 read_csv( "output.csv" ); // to print to the screen
// /* Question 3.3 
 delete_record( "output.csv" , "Maria" );
 read_csv( "output.csv" ); // to print to the screen
return 0 ;
}

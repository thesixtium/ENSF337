// ENSF 337 - lab 5 - exercise D
// M. Moussavi
// lab5exe_D.c

#include <stdio.h>
#include <stdlib.h>
#include "lab5exe_D.h"

int main(void) {
    char input_filename[30] = "lab5exe_D.txt";
    char output_filename[30]= "lab5exe_D_output.txt";
    IntVector intVec;
    intVec.number_of_data = 0;
    
    read_text_file(&intVec, input_filename);
    
    display_single_column(&intVec);
    
    display_multiple_column(&intVec, 4, output_filename);
    
    return 0;
}

void read_text_file (IntVector* vec, const char* input_filename){
    int nscan;
    FILE *fp = fopen (input_filename, "r");
    
    if(fp == NULL){
        fprintf(stdout, "Sorry cannot open the text file %s.\n", input_filename);
        exit(1);
    }
    
    do{
        nscan = fscanf(fp,"%d", &vec->storage[vec->number_of_data]);
        if(nscan == 1)
            (vec->number_of_data)++;
        else if (nscan != EOF){
            fprintf(stderr, "Invalid data in %s.\n", input_filename);
            exit(1);
        }
    }while ((nscan != EOF) & (vec->number_of_data < MAX_CAPACITY));
    
    fclose(fp);
}

void display_single_column(const IntVector* intV){
    int i;
    for (i = 0; i < intV ->number_of_data; i++ )
        printf("%10d\n", intV ->storage[i]);
}

void display_multiple_column(const IntVector *intV, int col, const char* output_filename)
{
    int i = 0;
    int j = 0;
    while (intV->storage[i] != EOF){
        j=0;
        while(j<col){
            printf("%d\t", intV->storage[i]);
            j++;
            i++;
        }
        i++;
        printf("\n");
    }
    if(intV->storage[i] == EOF){
        printf("\n");
    }
}


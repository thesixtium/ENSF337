/*
*  File Name: lab3exe_F.c
*  Assignment: Lab 3 Exercise F
*  Lab section: B04
*  Completed by: Aleksander Berezowski
*  Submission Date: On or before Oct 14, 2021
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 100


/* function prototypes*/
int is_palindrome (const char *str);
/* REQUIRES: str is pointer to a valid C string.
 * PROMISES: the return value is 1 if the string a is palindrome.*/


void strip_out(char *str);
/* REQUIRES: str points to a valid C string terminated with '\0'.
 * PROMISES: strips out any non-alphanumerical characters in str*/

int main(void)
{
    int p =0;
    char str[SIZE], temp[SIZE];
    
    fgets(str, SIZE, stdin);
    
    /* Remove end-of-line character if there is one in str.*/
    if (str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';
    
    strcpy(temp,str);
    
    /* This loop is infinite if the string "done" never appears in the
     * input.  That's a bit dangerous, but OK in a test harness where
     * the programmer is controlling the input. */
    
    while(strcmp(str, "done") !=0) /* Keep looping unless str matches "done". */
    {
        strip_out(str);
        
        p = is_palindrome(str);
        
        if(!p)
            printf("\n \"%s\" is not a palindrome.", temp);
        else
            printf("\n \"%s\" is a palindrome.", temp);
        
        fgets(str, SIZE, stdin);
        
        /* Remove end-of-line character if there is one in str.*/
        if(str[strlen(str) - 1] == '\n')
            str[strlen(str) - 1]= '\0';
        strcpy(temp, str);
    }
    
    return 0;
}

void strip_out(char *str){
	char tempString[SIZE];
	int i = 0;
	int j = 0;
	
	//Fill temp string with '\0' characters
	for(i=0; i<SIZE; i++){
		tempString[i] = '\0';
	}
	
	//Build temporary string with only alphanumerical characters
	for(i=0; i<strlen(str); i++){
        if(isalnum(str[i])){
            tempString[j] = tolower(str[i]);
            j += 1;
        }
    }
	
	//Set string to tempString
	for(i=0; i< strlen(str); i++){
		str[i] = tempString[i];
	}
}

int is_palindrome (const char *str){
	int i = 0;
	for(i=0; i<strlen(str); i++){
		//I'm so proud of this, it's just one line that does everything
        // Compares the n-th character of the string to the string-length-n-th to see if they match
        if(tolower(str[strlen(str)-i-1]) != tolower(str[i])){
			return 0;
		}
	}
	return 1;
}
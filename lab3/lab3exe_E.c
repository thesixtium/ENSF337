/*
*  File Name: lab3exe_E.c
*  Assignment: Lab 3 Exercise E
*  Lab section: B04
*  Completed by: Aleksander Berezowski
*  Submission Date: On or before Oct 14, 2021
*/

#include <stdio.h>
#include <string.h>

int substring(const char *s1, const char *s2);
/* REQUIRES
 * s1 and s2 are valid C-string terminated with '\0';
 * PROMISES
 * returns one if s2 is a substring of s1). Otherwise returns zero.
 */

void select_negatives(const int *source, int n_source,
                      int* negatives_only, int* number_of_negatives);
/* REQUIRES
 *   n_source >= 0.
 *   Elements source[0], source[1], ..., source[n_source - 1] exist.
 *   Elements negatives_only[0], negatives_only[1], ..., negatives_only[n_source - 1] exist.
 * PROMISES
 *   number_of_negatives == number of negative values in source[0], ..., source[n_source - 1].
 *   negatives_only[0], ..., negatives_only[number_of_negatives - 1] contain those negative values, in
 *   the same order as in the source array.                           */

int main(void)
{
    char s[] = "Knock knock! Who's there?";
    int a[] = { -10, 9, -17, 0, -15 };
    int size_a;
    int i;
    int negative[5];
    int n_negative;
    
    size_a = sizeof(a) / sizeof(a[0]);
    
    printf("a has %d elements:", size_a);
    for (i = 0; i < size_a; i++)
        printf("  %d", a[i]);
    printf("\n");
    select_negatives(a, size_a, negative, &n_negative);
    printf("\nnegative elements from array a are as follows:");
    for (i = 0; i < n_negative; i++)
        printf("  %d", negative[i]);
    printf("\n");
    
    printf("\nNow testing substring function....\n");
    printf("Answer must be 1. substring function returned: %d\n" , substring(s, "Who"));
    printf("Answer must be 0. substring function returned: %d\n" , substring(s, "knowk"));
    printf("Answer must be 1. substring function returned: %d\n" , substring(s, "knock"));
    printf("Answer must be 0. substring function returned: %d\n" , substring(s, ""));
    printf("Answer must be 1. substring function returned: %d\n" , substring(s, "ck! Who's"));
    printf("Answer must be 0. substring function returned: %d\n" , substring(s, "ck!Who's"));
    return 0;
}

int substring(const char *s1, const char* s2)
{
    //Define variables
    int j,i=0;
    int k=2;

    //Constant loop that will break by changing k's value
    while(k==2){

        //Check if s1's character and s2's character are not the same
        if(s1[i] != s2[j]){
            //Go back to start of s2, increase s1's index
            j = 0;
            i++;

            //If reached end of s1 there are no substrings, set k to 0
            if(s1[i] == '\0')
                k=0;

        //Check if s1's character and s2's character are the same
        } else if(s1[i] == s2[j]) {
            //Increase index of both strings to check next characters
            i += 1;
            j += 1;

            //If reached end of s1 there is at least 1 substring, set k to 1
            if(s2[j] == '\0')
                k=1;
        }
    }
    return k;
 }

void select_negatives(const int *source, int n_source,
                      int* negatives_only, int* number_of_negatives)
{
    //define variables
    int i;
    int j = 0;
    *number_of_negatives = 0;

    //Check each entry in the list
    for(i=0; i<n_source; i++){
        if(source[i] < 0){
            //If source's number at i is 0, add to the negatives list and increase the number of negitives counter
            negatives_only[j] = source[i];
            *number_of_negatives += 1;
            j += 1;
        }
    }
}


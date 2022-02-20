/*
*  File Name: read_double.c
*  Assignment: Lab 4 Exercise E
*  Lab section: B04
*  Completed by: Aleksander Berezowski
*  Submission Date: On or before Oct 21, 2021
*/

#include "read_input.h"

int read_double(char* digits,int n, double* num)
{
  if(get_string(digits, n)== EOF)
    return EOF;

  if(is_valid_double(digits)){
    if(digits[0] == '-')
      *num = -convert_to_double(digits + 1);
    else if(digits[0] == '+') 
      *num = convert_to_double(digits + 1);
    else
      *num = convert_to_double(digits);
    return 1;
  }

  return 0;
}


int is_valid_double(const char* digits)
{
  int valid = 1;
  int i;
  int has_decimal = 0;

  /* i = index where first digit should be */
  if(digits[0] == '+' || digits[0] == '-')
    i = 1;
  else
    i = 0;

  /* Must have at least one digit, and no non-digits. */
  if (digits[i] == '\0')
    valid = 0;
  else
    while (valid && (digits[i] != '\0')) {
      if(digits[i] == 46) {
          i++;
          has_decimal += 1;
      }
      if ( ( (digits[i] < '0' ||  digits[i] > '9') || digits[i] == 46 ) || has_decimal > 1) {
          valid = 0;
      }
      i++;
    }
  
  return valid;
}


double convert_to_double(const char* digits)
{
  double sum = 0;
  double sum_int = 0;
  double sum_decimal = 0;
  int i = 0;
  int j = 0;
  int has_decimal = 0;
  int multiplier = 1;

  while(digits[j] != '\0'){
      if(digits[j] == 46)
          has_decimal = 1;
      j++;
  }

  j = 0;
  if(has_decimal == 0){
      while(digits[i] != '\0') {
          sum = 10 * sum + (digits[i] - '0');
          i++;
      }
  } else {
      while(digits[i] != 46) {
          sum_int = 10 * sum_int + (digits[i] - '0');
          i++;
      }
      i++;
      j=i;
      while(digits[i] != '\0'){
          sum_decimal = 10 * sum_decimal + (digits[i] - '0');
          i++;
      }
      for(int k = 0; k < i-j; k++)
          multiplier *= 10;
      sum_decimal = sum_decimal / multiplier;
    sum = sum_int + sum_decimal;
  }


  return sum;
}

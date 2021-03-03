
/********************************/
/* Program Name:                */
/* Author:                      */
/* Date:                        */
/********************************/
/* Description:                 */
/* Validation Checks:           */
/* Enhancements:                */
/********************************/

#include "stdio.h"
#include "stdlib.h"
#include <unistd.h>

#define byte char

int main (int argc, char * argv[], char ** envp) {

  int ascii_value;
  int offset = 48;
  int number = 0;
  int count = 0; 
  
    int retval = read(0, &ascii_value, 1);
    while (retval == 1)
	{
		count++;

    if (count > 32) {
      fprintf(stderr, "%s", "Error, number exceeds 2^32!");
      return 1;
    }

    if (ascii_value != '0' && ascii_value != '1') {
      fprintf(stderr, "%s", "Error, invalid input!");
      return 1;
    }
        int digit = ascii_value - offset;
        number = (number << 1) + digit;  
        retval = read(0, &ascii_value, 1);
	if (ascii_value == 10 || ascii_value == 13) 
		{break;}
    }
    printf("%u\n", number);
    return 0;

}

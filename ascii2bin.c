/********************************/
/* Program Name: ascii2bin      */
/* Author:Kagen Christoph       */
/* Date: 3/1/2021              */
/********************************/
/* Description:                 */
/* Validation Checks:           */
/* Enhancements:                */
/********************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define byte unsigned char


int main (int argc, char * argv[], char ** envp)
{
        byte ascii_value = 0;
        byte offset = 0x30; //48
        byte digit = 0;
        unsigned int number = 0;
        int retval;

        retval = read(0, &ascii_value, 1);
        
            while (retval == 1)
            {
				printf("%d\n",ascii_value);
                if(ascii_value != 48 && ascii_value != 49) // needs to be within range 48-49 
                {                                                          
                   break;
                }
                else
                {
		    digit = ascii_value - offset;
                    number = (number << 1) + digit;         
                    retval = read(0, &ascii_value, 1);  
                }
            }        
    if(ascii_value == 0x30 || ascii_value == 0x31 || ascii_value == 0x0a) // check for LF
    {
        printf("%u\n", number);
        return 0;
    }
    return 1;
}

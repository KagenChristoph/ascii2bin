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
#define max_count (32)


int main (int argc, char * argv[], char ** envp)
{
        byte ascii_value = 0;
        byte offset = 48; 
        byte digit = 0;
        unsigned int number = 0;
        int retval;
	int count = 0;

        retval = read(0, &ascii_value, 1);
        
            while (retval == 1)
            {
		if(count > max_count)                                           /  
        	{                                                               
            	fprintf(stderr,"%s","The calculated number exceeds 2^32.");
		return 1;
        	}
                if(ascii_value != 48 && ascii_value != 49) // needs to be within range 48-49 
                {                                                          
                   break;
                }
                else
                {
		    count++;
		    digit = ascii_value - offset;
                    number = (number << 1) + digit;         
                    retval = read(0, &ascii_value, 1);  
                }
            }        
    if(ascii_value == 48 || ascii_value == 49 || ascii_value == 10) // check for LF
    {
        printf("%u\n", number);
        return 0;
    }
    else
    {
	    fprintf(stderr,"%s","A non binary input has been detected");
	    return 1;
    }
    
}

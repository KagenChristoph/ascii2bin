#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char * argv[], char ** envp)
{
        char ascii_value = 0;
        char offset = 0x30;                  //48
        char digit = 0;
        unsigned int number = 0;
        int retval;

        retval = read(0, &ascii_value, 1);
        
            while (retval == 1)
            {
                if(ascii_value == 0x30 || ascii_value == 0x31) 
                {                                                          
                    digit = ascii_value - offset;
                    number = (number << 1) + digit;         
                    retval = read(0, &ascii_value, 1);  
                }
                else
                {
                        break;
                }
            }        
    if(ascii_value == 0x30 || ascii_value == 0x31 || ascii_value == 0x0a)
    {
        printf("%u\n", number);
        return 0;
    }
    return 1;



}

/*
 * buffer.c
 *
 *  Created on: Mar 10, 2015
 *      Author: home
 */


#include<stdio.h>
#include<conio.h>
#include<math.h>

#include "buffer.h"

int main(void)
{
 
   int i;
   
   printf("Ring Buffer");
   printf("\n W XX  :  Write xx Message to Buffer");
   printf("\n R     :  Read XX Message from Buffer");
   printf("\n N     :  Show Pending Message from Buffer");
   printf("\n Q     :  Quit\n");  
 
   	  do
	    {	
	       
	    choice:
	    printf("\nEnter Choice:"); // Taking Input From User
		scanf(" %c",&input);    	// leading space ignores white space from input thereby ignoring flase looping		
	  
	    switch(input)  // Checking for the valid input
	    {
	    case  'q' :
	   	case  'Q' :
	   		
	    {
	  	printf("Program Ends");
	  	break;
	    }  
	   
       	case  'w' :
	  	case  'W' :
	  	{
	  	
			  scanf("%d",&add);
          	   push_char(add);
          	   goto choice; 
		 	    
        }	
    
	      case  'r' :
		  case  'R' : 
   	    {
   	
   	       	   int data;  
   	           data=pull_char();
               printf("\nData Read From Buffer: %d\n", data);
		       goto choice;
			
   		} 
   
  			  	
       	 case  'n' :
	   	 case  'N' :
	
		 {
		 	unsigned int msg;
		 	msg=get_count();
		    printf("Message : %d\n",msg); 
		    printf("Write Counter : %d  Read Counter : %d Overflow : %d\n",write_pointer,read_pointer,overflow_flag);
		    for (i = 0; i < BUFFER_SIZE; i++) printf("[%d]", buffer[i]);
			goto choice;   
   		 }
		 	          
  		default:printf("Invalid Choice\n");goto choice;
       	
		}
       
    } while(input!='q' && input!='Q');
   
  getch();
  return 0;
}

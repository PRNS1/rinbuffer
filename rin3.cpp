/* Ring Buffer */

/*Header Files*/

#include<stdio.h>
#include<conio.h>
 
//Macro Definition 
#define BUFFER_SIZE 4
 
//Global Variables 
 
int data_size = 0;      // number of chars in buffer
int read_pointer = 0;   // indice number of last read char
int write_pointer = 0;  // indice number of last written char
int input=0;              // Scan user input to this variable
unsigned int add;               // char to add
 
int buffer[BUFFER_SIZE];
 
// Function Prototypes
int buffer_full(void);
int buffer_empty(void);
void push_char(unsigned int c);
void pull_char(void);
 
 //Main Function Starting from Here
int main(void)
{
 
   int i;
   printf("Ring Buffer");
   printf("\n W    :  Write Message to Buffer");
   printf("\n R    :  Read XX Message from Buffer");
   printf("\n N    :  Show Pending Message from Buffer");
   printf("\n Q    :  Quit\n");  
 
   	  do
	    {	
	     choice:printf("\nEnter Choice:"); // Taking Input From User
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
      	
         printf("Enter Data:");
         scanf("%d",&add);
      
       if (! buffer_full())
         push_char(add);
       else
         printf("\nBUFFER IS FULL!");
		 goto choice;      
       }
    

	// Read Message
      case  'r' :
	  case  'R' : 
   	    {
 
     		 if (! buffer_empty())
        	pull_char();
     		 else
        	printf("\nBUFFER IS EMPTY!");  
		 	goto choice;    
   		}
   
    	// Display Number of Pending Messages in Buffer
       	 case  'n' :
	   	 case  'N' :
	
		 {
 
    	  printf("\n data_size: %d read_pointer: %d write_counter: %d", 
    	  data_size, read_pointer, write_pointer);
      
     			 printf("\nQueue content:\n");
   		  for (i = 0; i < BUFFER_SIZE; i++) printf("[%d]", buffer[i]);
   		           
					  int pending=0;                                // For unread message
   			   pending =  write_pointer - read_pointer;
    		  printf("\n Unread/Pending Messages  : %d \n",pending);
   				     goto choice;
   			 }
  
  			 default:printf("Invalid Choice\n");goto choice;
  				     
       }
    } while(input!='q' && input!='Q');
   
  getch();
  return 0;
}
 
// Save Message to Buffer 
void push_char(unsigned int c)
{
    // increase write_pointer, check if at end of array
    if (++write_pointer <= BUFFER_SIZE) //write_pointer = 0;
     
    buffer[write_pointer] = c;
	printf("Data Added Successfully");    
    data_size++;
}
 
// returns 1 if buffer is full, 0 if buffer is not full
int buffer_full(void) 
{
//	return read_pointer == write_pointer &&
	 	return	data_size == BUFFER_SIZE;
}
// returns 1 if buffer is empty, 0 if buffer is not empty
int buffer_empty(void)
{
	//return read_pointer == write_pointer && 
	return	data_size == 0;
}
 
// Read Message From Buffer
void pull_char(void) 
{  
  if (++read_pointer >= BUFFER_SIZE) read_pointer = 0;
 
  printf("\nData Read From Buffer: %d", buffer[read_pointer]);
 
  // enter space on place of read char so we can see it is removed
  buffer[read_pointer] = 0x20; 
  data_size--;  
}

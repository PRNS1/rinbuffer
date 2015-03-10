/*
 * buffer.h
 *
 *  Created on: Feb 10, 2015
 *      Author: home
 */

#ifndef BUFFER_H_
#define BUFFER_H_

#ifdef __cplusplus
extern "C"
{
#endif

/*********************************************************************
 * MACROS
 */
#define BUFFER_SIZE 4


/*********************************************************************
 * GLOBAL VARIABLES
 */

int overflow_flag=0; 
int read_pointer = 0;  
int write_pointer = 0; 
int input=0;            
unsigned int add;      
int buffer[BUFFER_SIZE];



/*********************************************************************
 * GLOBAL FUNCTIONS
 */
unsigned int get_count(void);
void push_char(unsigned int c);
unsigned int pull_char(void);


void push_char(unsigned int c)
{
	buffer[write_pointer] = c;
	++write_pointer;
	
    if (write_pointer >= BUFFER_SIZE) 	
    {
   		write_pointer = 0; 
   		printf("Buffer Overflow !!");		
    }
    
    if(write_pointer==read_pointer) 
   	{
   		overflow_flag = 1;
        }
   
}
 
unsigned int get_count(void)
{
	if(read_pointer==write_pointer)
	{
	  if (overflow_flag==1)
		{   
			return BUFFER_SIZE;
		}
		else
		{
			return 0;
		}
	}
 else
        {
    	 return abs(read_pointer-write_pointer);
	}
	
}

unsigned int pull_char(void) 
{  
  int data; 
  data=buffer[read_pointer];
  read_pointer++;
  overflow_flag=0;
  if(read_pointer>=BUFFER_SIZE)
  {
  	read_pointer=0;
	printf("Buffer is Empty");
  }
  return  data;
}
 



/*
 * Allocate a block of memory.
 */
//extern void *osal_bm_alloc( uint16 size );

/*
 * Add or remove header space for the payload pointer.
 */
//extern void *osal_bm_adjust_header( void *payload_ptr, int16 size );

/*
 * Add or remove tail space for the payload pointer.
 */
//extern void *osal_bm_adjust_tail( void *payload_ptr, int16 size );

/*
 * Free a block of memory.
 */
//extern void osal_bm_free( void *payload_ptr );

/*********************************************************************
*********************************************************************/

#ifdef __cplusplus
}
#endif


#endif /* BUFFER_H_ */

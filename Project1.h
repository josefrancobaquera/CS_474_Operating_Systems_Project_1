/****************************************************************************************************
 * 
 * CS474: Operating Systems
 * Project #1 (Shared memory)
 * October 13, 2019
 * 
 * Team Member 1: 
 * Liliana Aguirre Esparza
 * 
 * Team Member 2: 
 * Jose Franco Baquera
 *
 * Problem Description: In this project, you need to create 4 processes. Each of these processes will 
 * share a variable named "total". Within each process, you need to create a loop and increase the variable 
 * “total” one by one until 100,000, 200,000, 300,000 and 500,000 respectively. Print out the value of 
 * “total” after each process finishes the loop. Make sure that only the newly created child calls the 
 * function “process#()”. After all the children have finished, the parent process should release the 
 * shared memory and terminate. Use the "wait" function so that the parent knows exactly when each child 
 * completes. The parent should print the process id of each child as the child finishes execution. Then 
 * it should release shared memory and print "End of Program".         
 * 
 ****************************************************************************************************/

#ifndef PROJECT1_H
#define PROJECT1_H

/* Include all the required libraries. */
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

/* Key number provided in project slides. */
#define SHMKEY ((key_t) 1497) 

/* Function prototypes. */
void process1 ( );
void process2 ( );
void process3 ( ); 
void process4 ( );

/* Define a new structure named "shared_mem" with one integer attribute. 
 * This integer attribute will be the value incremented by the processes. 
 */
typedef struct {
    
   int value;

} shared_mem;

/* Declare a pointer that will point to a shared_mem structure. */
shared_mem *total;

#endif

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

/* Include the header file. */
#include "Project1.h"


/*******************************************************************************************************
 * Function: process1 - This function will be called by process 1 and will increment the shared memory
 * value until it reaches 100000, print the value of the variable and then exit.
 * Parameters: None
 * Preconditions: 
 *      - Function will be called only by the first newly created process.
 * Postconditions: The shared memory value will be incremented to ~100000. The value of the shared
 * variable will be printed.
 * Return - No return value.
 ********************************************************************************************************/
void process1 ( ) {
    
   /* Loop that increments the shared variable one by one until 100000. */
   while (total->value < 100000)
       total->value++;
   
   /* Print the final value of shared variable and terminate the child process by exiting. */
   printf ("From Process 1: Total = %d\n", total->value);
   exit(0);
   
} /* end process1 */ 


/*******************************************************************************************************
 * Function: process2 - This function will be called by process 2 and will increment the shared memory
 * value until it reaches 200000,
 * print the value of the variable and then exit.
 * Parameters: None
 * Preconditions: 
 *      - Function will be called only by the first newly created process.
 * Postconditions: The shared memory value will be incremented to 200000. The value of the shared
 * variable will be printed.
 * Return - No return value.
 ********************************************************************************************************/
void process2 ( ) {
    
   /* Loop that increments the shared variable one by one until 200000. */
   while (total->value < 200000)
      total->value++;
   
   /* Print the final value of shared variable and terminate the child process by exiting. */
   printf ("From Process 2: Total = %d\n", total->value); 
   exit(0);
   
} /* end process2 */ 


/*******************************************************************************************************
 * Function: process3 - This function will be called by process 3 and will increment the shared memory
 * value until it reaches 300000,
 * print the value of the variable and then exit.
 * Parameters: None
 * Preconditions: 
 *      - Function will be called only by the first newly created process.
 * Postconditions: The shared memory value will be incremented to 300000. The value of the shared
 * variable will be printed.
 * Return - No return value.
 ********************************************************************************************************/
void process3 ( ) {   
   
   /* Loop that increments the shared variable one by one until 300000. */
   while (total->value < 300000) 
      total->value++;
   
   /* Print the final value of shared variable and terminate the child process by exiting. */
   printf ("From Process 3: Total = %d\n", total->value);
   exit(0);
   
} /* end process3 */ 


/*******************************************************************************************************
 * Function: process4 - This function will be called by process 4 and will increment the shared memory
 * value until it reaches 500000,
 * print the value of the variable and then exit.
 * Parameters: None
 * Preconditions: 
 *      - Function will be called only by the first newly created process.
 * Postconditions: The shared memory value will be incremented to 500000. The value of the shared
 * variable will be printed.
 * Return - No return value.
 ********************************************************************************************************/
void process4 ( ) {
   /* Loop that increments the shared variable one by one until 500000. */
   while (total->value < 500000)
      total->value++;
   
   /* Print the final value of shared variable and terminate the child process by exiting. */
   printf ("From Process 4: Total = %d\n", total->value);
   exit(0);
   
} /* end process4 */ 


/*******************************************************************************************************
 * Function: main - Program will start executing from here. 
 * Parameters: None
 * Preconditions: 
 *      - Shared memory key must have been previously defined.
 *      - Necessary libraries must have been defined
 * Postconditions: In the parent process this function will print a message each time a child terminates
 * Return - No return value.
 ********************************************************************************************************/
int main ( ) {
    
   /* Declaration of shared memory variable and pid variables*/
   int   shmem_id, pid1, pid2, pid3, pid4, status;
   int child_pid = 0;

   int parent_pid = 0;
   char *shm_add;

   shm_add = (char *) 0;

   /* Allocate a shared memory segment using the shmget system call. This system call returns
    * the identifier to the shared memory segment. If shmget fails we will print an error and exit*/
   if ((shmem_id = shmget (SHMKEY, sizeof(int), IPC_CREAT | 0666)) < 0) {
      perror ("shmget");
      exit (1);     
   }

   /* Attach a shared memory segment to an address space by calling the shmat system call.
    * This system call returns the address of the attached memory segment. If shmat fails we will 
    * print an error and exit */
   if ((total = (shared_mem *) shmat (shmem_id, shm_add, 0)) == (shared_mem *) -1) {
      perror ("shmat");
      exit(1);
   }
   
   /* Initialize the shared memory value to 0 */
   total->value = 0;
   printf( "\n" );

   /* Create first child process. */
   if ( (pid1 = fork()) == 0 ) {
      process1 (); }
      
   /* Create second child process */
   if ((pid2 = fork()) == 0) {
      process2 ();
   }
   
   /* Create third child process */
   if ((pid3 = fork()) == 0) {
      process3 ();
   }
   
   /* Create fourth child process */
   if ((pid4 = fork()) == 0) {
      process4 ();
   }

   /* Parent process will wait for all children processes to end and then print a message with their PID */
   while((child_pid = wait(&status)) != -1)
      printf("Child with ID %d has just exited.\n", child_pid);

   /* Detach shared memory from address space. Prints an error if shmdt fails and exits. */
   if (shmdt(total) == -1) {
      perror ("shmdt");
      exit (-1);
   }
   
   /* Remove shared memory and exit */
   shmctl(shmem_id, IPC_RMID, NULL); 
   printf("\nEnd of Program.\n\n");
   exit(0);

} /* end main */

# OSProject1

CS474: Operating Systems
Project #1 (Shared memory)
October 13, 2019
 
Team Member 1: 
Liliana Aguirre Esparza
 
Team Member 2: 
Jose Franco Baquera

Problem Description: In this project, you need to create 4 processes. Each of these processes will 
share a variable named "total". Within each process, you need to create a loop and increase the variable 
“total” one-by-one until 100,000, 200,000, 300,000 and 500,000 respectively. Print out the value of 
“total” after each process finishes the loop. Make sure that only the newly created child calls the 
function “process#()”. After all the children have finished, the parent process should release the 
shared memory and terminate. Use the "wait" function so that the parent knows exactly when each child 
completes. The parent should print the process id of each child as the child finishes execution. Then 
it should release shared memory and print "End of Program".

## Step 1: Change Current Working Directory to Appropriate Folder
First, change the current working directory (using the command line) to the folder where these files are located.

## Step 2: Compile Program 
Second, compile the program using the following command: make

## Step 3: Execute Program 
Third, execute the program by using the following command: ./project1

## (Optional Feature): Cleaning the File Directory
An optional feature was implemented. Users can run the following command in the appropriate working directory: make clean 
This command will delete the current executable file "project1" in the current working directory. NOTE: This command will error if not "project1" executable is found in the current working directory.  

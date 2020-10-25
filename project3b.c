//*********************************************************
// Alexa Ceja
// Operating Systems
// Project #3: Programming with pThreads - Part B
// Computing Fibonacci Numbers With Threads
//*********************************************************

//*********************************************************
// Includes and Defines
//*********************************************************
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//*********************************************************
// Global Variables and Defines
//*********************************************************
#define MAX_THREADS 512

//Variables Used in Functions and Main//
int input;
unsigned long long *fibArray;

//*********************************************************
// Functions
//*********************************************************

//void printArray(unsigned long long *array, int input):
//Prints the Fibonnaci sequence (content of array) in paranthesis.//
void printArray(unsigned long long *array, int input)
{
    for (unsigned long long i = 0; i < input; i++)
    {
        printf("(%llu) ", array[i]);
    }
	printf("\n");
    return;
}

//void *pthread_run(void *arg): 
//The thread runner takes care of the sequence generator required 
//for the child process to work.//
void *pthreadRun(void *arg)
{
    for (int i = 2; i < input; i++)
    {
        fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
    }
    pthread_exit(0);
}

//*********************************************************
// Main Function
//*********************************************************
int main(int argc, char const *argv[])
{
    //Program requests user to input the number that it will generate and records it in vairable 'input'//
    printf ("Enter the # of Fibonnaci numbers you want the code to generate: \n");
    scanf("%d", &input);
	
    //Error checking for Max value//
    if (input > 100)
    {
        printf("Input cannot be higher than 100. \n");
        exit(0);
    }

    //Size of array is determined using calloc and number input// 
    fibArray = (unsigned long long *)calloc(input, sizeof(unsigned long long));

    //Defines the first two elements of fibArray which are always the same in the Fibonnaci sequence//
    fibArray[0] = 0;
    fibArray[1] = 1;

    //Create thread instance//
    pthread_t p_thread;
    pthread_attr_t attr;
    pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);

    //Uses pthread_create function to create a new thread and run pthreadRun within it//
    pthread_create(&p_thread, NULL, pthreadRun, &attr);
   
    //Uses pthread_join function to join child thread after completion//
    pthread_join(p_thread, NULL);

    //Calls on printArray function for parent thread (main) to print Fibonnaci sequence through function//
    printArray(fibArray, input);

return 0;
}

//*********************************************************
// Alexa Ceja
// Operating Systems
// Project #3: Programming with pThreads - Part C
// Printing Words with sched_yield()
//*********************************************************

//*********************************************************
// Includes and Defines
//*********************************************************
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
//Define MAX_THREADS from code provided by Dr. Kar//
#define MAX_THREADS 512

//*********************************************************
// Global Variables
//*********************************************************
char consArray[1000];
char vowsArray[12] = {'a','e','i','o','u','A','E','I','O','U'};
char *input[1000];

//*********************************************************
// Functions
//*********************************************************
//void *vow(void *v):
//Compares the words from user input and prints if word begins with vowel//
void *vow(void *v)
{
   //Assigns int value to array subscript
   int a = v;

   for(int i = 0; i < 12; i++)
   {
		if(consArray[a] == vowsArray[i])
		{
			printf("Vowel Words: %s \n", input[a]);
		}
   }
}

//void *cons(void *c):
//Compares the words from user input and prints if word begins with consonant
//Sends those that arent to *vow thread.//
void *cons(void *c)
{
   //Assigns int value to array subscript
   int b = c;
   
   for(int i = 0; i < 12; i++ )
   {
		if(consArray[b] == vowsArray[i])
		{
			pthread_exit(0);
		}
   }
  printf("Conso Words: %s \n", input[b]);
}

//*********************************************************
// Main Function
//*********************************************************
int main(int argc, char *argv[])
{

	//Local Variables//
    int i = 0;
    int count = 0;

	//While loop that goes through the command line arguments (phrase input by user)
	//and stores in input and consArray until there are no more words in the phrase.//
    while(argv[i] != NULL)
    {
		input[i - 1]  = argv[i];
		consArray[i - 1] = *input[i - 1];
		i++;
    }

	//Create vow and conthread instance//
    pthread_t p_thread_Vow[MAX_THREADS];
    pthread_t p_thread_Con[MAX_THREADS];
	
	//Initialize thread attribute objects by Dr. Kar //
    pthread_attr_t attr;
    pthread_attr_init (&attr);
    pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
	
	//Keeps track of amount of words in phrase//
	count = i - 1;
	
	//For loops that creates threads and calls on vows/cons functions
	//for every word in the phrase.//
	for(int i = 0; i < count; i++)
	{			
		//Uses pthread_create function to create new threads (p_thread_Con/p_thread_Vow) and run cons/vow within it//
		pthread_create(&p_thread_Con[i], &attr, cons, (void *)i);
		pthread_create(&p_thread_Vow[i], &attr, vow, (void *)i);
		
		//Uses pthread_join function to join threas after every iteratiation to avoid segmentation fault.//
		pthread_join(p_thread_Vow[i],NULL);
		pthread_join(p_thread_Con[i],NULL);
	}

	return(0);
}


//*********************************************************
// Alexa Ceja
// Operating Systems
// Project #3: Programming with pThreads - Part A
// Computing PI with Threads
//*********************************************************

//*********************************************************
// Includes and Defines
//*********************************************************
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
//Added time.h for timing purposes //
//#define _POSIX_C_SOURCE 199309L necessary if compiling with -std=c99//
#include <time.h>

#define MAX_THREADS 512
//Define added to indicate BILLION value used in timing calculation // 
#define BILLION  1E9

//Function prototype by Dr. Kar // 
void *compute_pi( void * );

//Global variables provided by Dr. Kar - deleted a duplicate of sample_points. //
int total_hits;
int total_misses;
int hits[ MAX_THREADS ];
int sample_points;
int sample_points_per_thread;
int num_threads;

//*********************************************************
// Main Function - code provided by Dr. Kar has been indicated in comments
//*********************************************************
int main( int argc, char *argv[] )
{
  /*Local variables by Dr. Kar */
  int ii;
  int retval;
  pthread_t p_threads[MAX_THREADS];
  pthread_attr_t attr;
  double computed_pi;
  
  //Local Variables necessary for clock_gettime //
  struct timespec wall_start, wall_end;
  struct timespec cpu_start, cpu_end;
  double wall_total, cpu_total;

  /*Initialize local variables by Dr. Kar */
  retval = 0;
  
  //Process begins timing using clock_gettime, MONOTONIC_RAW to measure wall clock time without NTP jumps//
  //and CPUTIME_ID to measure CP time.//
  clock_gettime(CLOCK_MONOTONIC_RAW, &wall_start);
  clock_gettime(CLOCK_THREAD_CPUTIME_ID, &cpu_start);
  
  //Initialize thread attribute objects by Dr. Kar //
  pthread_attr_init( &attr );
  pthread_attr_setscope( &attr, PTHREAD_SCOPE_SYSTEM );

  /* COMMENT CODE NOT USED //////////////////////////////////////////////
  parse command line arguments into sample points and number of threads
  there is no error checking here!!!!! 
  sample_points = atoi(argv[1]);
  num_threads = atoi(argv[2]); 
  */// COMMENT CODE NOT USED ///////////////////////////////////////////


  /* uncomment this block if you want interactive input!!!! */
  /* if so...comment out the two statements above */ 
  printf( "Enter number of sample points: " );
  scanf( "%d", &sample_points );
  printf( "Enter number of threads: " );
  scanf( "%d%", &num_threads );

  total_hits = 0;
  sample_points_per_thread = sample_points / num_threads;

  //For loop provided by Dr. Kar to calculate PI by calling compute_pi function//
  for( ii=0; ii<num_threads; ii++ )
    {
      hits[ii] = ii;
      pthread_create( &p_threads[ ii ], &attr, compute_pi, (void *) &hits[ii] );
    }

  for( ii=0; ii<num_threads; ii++ )
    {
       pthread_join( p_threads[ ii ], NULL );
       total_hits += hits[ ii ];
    }

   //Calculation provided by Dr. Kar//
   computed_pi = 4.0 * (double) total_hits / ((double) (sample_points));
	
  //Process ends timing using clock_gettime.//
  clock_gettime(CLOCK_MONOTONIC_RAW, &wall_end);
  clock_gettime(CLOCK_THREAD_CPUTIME_ID, &cpu_end);

  //Variable stores the CPU time spent running the program in terms of Seconds//
  wall_total = (wall_end.tv_sec - wall_start.tv_sec) + (wall_end.tv_nsec - wall_start.tv_nsec) / BILLION;
  cpu_total = (cpu_end.tv_sec - cpu_start.tv_sec) + (cpu_end.tv_nsec - cpu_start.tv_nsec) / BILLION;

  //Print statements//
  printf( "Computed PI = %lf \n", computed_pi );
  printf("Wall Clock Time Taken: %lf seconds \n", wall_total);
  printf("CPU Time Taken: %lf seconds \n", cpu_total);

  /* return to calling environment by Dr. Kar */
  return( retval );
}

//********************************************************
//Compute_Pi Function Provided by Dr. Kar
//********************************************************
void *compute_pi( void *s )
{
  int seed;
  int ii;
  int *hit_pointer;
  int local_hits;
  double rand_no_x;
  double rand_no_y;

  hit_pointer = (int *) s;
  seed = *hit_pointer;
  local_hits = 0;

  for( ii=0; ii < sample_points_per_thread; ii++ )
    {
      rand_no_x = (double) (rand_r( &seed ))/(double)RAND_MAX;
      rand_no_y = (double) (rand_r( &seed ))/(double)RAND_MAX;
      if(((rand_no_x - 0.5) * (rand_no_x - 0.5) +
	  (rand_no_y - 0.5) * (rand_no_y - 0.5)) < 0.25)
	local_hits++;
      seed *= ii;
    }

  *hit_pointer = local_hits;
  pthread_exit(0);
}

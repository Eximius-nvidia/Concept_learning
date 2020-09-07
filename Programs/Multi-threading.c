#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 
#define NUM_THREADS 5

pthread_t thread_id[NUM_THREADS];
// Let us create a global variable to change it in threads 
int g = 0, s = 0;
  
// The function to be executed by all threads 
void *myThreadFun(void *vargp) 
{ 
    int p_id;
  // Store the value argument passed to this thread 
    long int *myid = (long int *)vargp; 
    
   // process id 
    p_id=getpid();
	
    //printf("Process ID: %d\n",p_id);
    printf("Process ID: %d,Thread ID: %ld, Static: %d, Global: %d\n", p_id, *myid, s++, g++); 
    sleep(1);
    return 0;
} 
  
int main() 
{ 
    int x=1;
    if(x)
    {
    	// Create three threads 
    	for (int i = 0; i < NUM_THREADS; i++)
    	{
        pthread_create(&thread_id[i], NULL, (void *) myThreadFun, (void *)&thread_id[i]);  
    	}   
    }else
    {
    	for(int j = 0; j < NUM_THREADS; j++)
        {
        myThreadFun(&x);
        }
    }
    for(int k = 0;k<NUM_THREADS; k++)
    {
    pthread_join(thread_id[k], NULL);
    }

    // thread_id   - Is the location where the ID of the newly created thread should be stored, or NULL if the thread ID is not required.
    // attr        - Is the thread attribute object specifying the attributes for the thread that is being created. 
    //               If attr is NULL, the thread is created with default attributes.
    // myThreadFun - Is the main function for the thread; the thread begins executing user code at this address.
    // thread_id   - Argument passed to myThreadFun.

    // Thread termination
    pthread_exit(NULL); 
    return 0; 
} 

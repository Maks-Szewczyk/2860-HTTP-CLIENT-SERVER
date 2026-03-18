#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

void* threadFn(void* vargp) 
{
    
    printf ( " Thread ID %p .\n " , pthread_self () );

    return NULL;
}

int main( int argc, char **argv )
{
    //
    // Initialisation and set-up.
    //
    pthread_t thread_id ;
    // Main thread creates a second pthread_create () .
    printf ( " MAIN THREAD ID %ld \n ",pthread_self () );
    pthread_create ( & thread_id , NULL , threadFn , NULL );
    pthread_create ( & thread_id , NULL , threadFn , NULL );

    pthread_join ( thread_id , NULL ) ;
    printf ( " MAIN THREAD ID %p \n " , pthread_self () ) ;

    return EXIT_SUCCESS;


   
}


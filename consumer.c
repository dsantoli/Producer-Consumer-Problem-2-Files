// Domenic Santoli
// Operating Systems
// Professor Guan
// Project 1

// How I solved the producer consumer problem
// ----------------------------------------------------------------------------------------------
// Creates one producer and one consumer (more producers can be created by altering THREADSIZE)                                    
// Size of buffer is 2
// Producer produces 100 numbers and consumer consumes 100 numbers
// Producer and consumer are synchronized working as fast as possible 
// Producer will produce 2 items to start then consumer will start consuming 
// Producer produces after item is consumed 
// First item produced is last consumed
// ----------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

// defined in producer.c
extern int buffer[2];
extern int counter, counter3;
extern pthread_mutex_t mutex;
extern sem_t full, empty;

// Consumer Section contains while true loop as well 
void* consumer() {
    while (counter3 < 100) {
        // wait until element is in buffer
        // if full = 0 - will wait
        sem_wait(&full);

        // lock 
        pthread_mutex_lock(&mutex);

        // consume the last item produced and decrement counter
        int y = buffer[counter -1];
        counter--;

        // unlock when done
        pthread_mutex_unlock(&mutex);

        // consumed element from buffer - 
        sem_post(&empty);
        
        // print item consumed
        printf("Consumed %d\n",y);

        // increment counter3
        ++counter3;
    }
}
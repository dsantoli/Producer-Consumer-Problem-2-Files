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

// one producer one consumer - threadsize will be 2
#define THREADSIZE 2

// Declaration of size
// buffer size
const int BUFFER_SIZE = 2;

// consumer already defined in consumer.c
extern void *consumer ();

// buffer
int buffer[2];
int counter = 0;

// producer and consumer counters
int counter2 = 0;
int counter3 = 0;

// declare pthread
pthread_t thread[THREADSIZE];

// Semaphore Declaration
// declare semaphores - one for number of empty and one for number of full spots in buffer
sem_t empty;
sem_t full;

// mutual exclusion 
// decalre mutex - so producer does not increment counter at same time as consumer decrements counter
pthread_mutex_t mutex;

// initialized mutex and semaphores
void setup() {
    // create mutex lock
    pthread_mutex_init(&mutex,NULL);

    // create semamphores empty and full
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
}

// Producer Section contains while true loop
void* producer() {
    while (counter2 < 100) {
        // generate random number
        int x = rand() % 300;

        // wait until spot is open
        // if empty = 0 - no slots - should wait
        sem_wait(&empty);

        // lock 
        pthread_mutex_lock(&mutex);

        // add to buffer and increment counter
        buffer[counter] = x;
        ++counter;
        // print item produced
        printf("Produced %d\n",x);

        // unlock when done
        pthread_mutex_unlock(&mutex);
        
        // produced element to buffer - increment semaphore representing number of elements
        sem_post(&full);

        // increment counter2
        ++counter2;
    }
}

// in the main section you need to declare threads, attribuites, and processes
int main(int argc, char* argv[]) {
    // seed for random number to be generated
    srand(time(NULL));
    // call setup - initializes mutex and semaphores
    setup();

    // declare i
    int i;
    // while i < number of threads create prodcuer and consumers
    for (i = 0; i < THREADSIZE; i++) {
        // create consumer initially then one or more producers
        if (i > 0) {
            // create thread to producer
            // check for error while creating
            if (pthread_create(&thread[i], NULL, &producer, NULL) != 0) {
                printf("error\n");
            }
        }
        // consumer created first
        else {
            // create thread to consumer
            // check for error while creating
            if (pthread_create(&thread[i], NULL, &consumer, NULL) != 0) {
                printf("error\n");
            }
        }
    }

    // while i < number of threads suspend execution of the calling thread until the target thread terminates, unless the target thread has already terminated.
    for (i = 0; i < THREADSIZE; i++) {
        // wait for threads
        // check for error while creating
        if (pthread_join(thread[i], NULL) != 0) {
            printf("error\n");
        }
    }

    // destroy semaphores
    sem_destroy(&empty);
    sem_destroy(&full);

    // destroy mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}

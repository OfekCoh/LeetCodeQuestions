#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem1, sem2, sem3;

void* f1(void* p) {
    while(1) {
        sem_wait(&sem1);
        printf("A");
        sem_post(&sem2); 
    }
}

void* f2(void* p) {
    while(1) {
        sem_wait(&sem2);
        sem_wait(&sem2); 
        printf("B");
        sem_post(&sem3); 
    }
}

void* f3(void* p) {
    while(1) {
        sem_wait(&sem3);
        printf("C");
        sem_post(&sem1); 
        sem_post(&sem1); 
    }
}

int main() {
    pthread_t t1, t2, t3;

    sem_init(&sem1, 0, 2); 
    sem_init(&sem2, 0, 0); 
    sem_init(&sem3, 0, 0); 

    pthread_create(&t1, NULL, f1, NULL);
    pthread_create(&t2, NULL, f2, NULL);
    pthread_create(&t3, NULL, f3, NULL);
    return 0;
}
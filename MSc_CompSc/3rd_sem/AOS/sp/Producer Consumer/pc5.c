#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void* producer(void*);
void* consumer(void*);

/*This data structure contains information that needs to be shared between
threads. It is passed to the producer and consumer threads' starter functions.
The alternative to this is to use global variables.*/
struct Context{
        pthread_cond_t* cond;
        pthread_mutex_t* mutex;
        /*This is used to hold a character while it is passed from one thread to
        another. Only the thread which owns the mutex lock should access it.*/
        char holder;
        int error;
};

int main(){
        volatile struct Context context;
        context.cond = (pthread_cond_t*)malloc(sizeof(pthread_cond_t));
        context.mutex = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t));
        context.error = 0;

        pthread_cond_init(context.cond, NULL);
        pthread_mutex_init(context.mutex, NULL);

        pthread_t prod;
        pthread_t cons;

        puts("createing first thread");
        if(pthread_create(&prod, NULL, producer, (void*)&context) != 0){
                puts("Could not create producer thread");

                pthread_mutex_destroy(context.mutex);
                pthread_cond_destroy(context.cond);

                return(EXIT_FAILURE);
        }

        puts("createing second thread");
        if(pthread_create(&cons, NULL, consumer, (void*)&context) != 0){
                puts("Could not create consumer thread");

                pthread_mutex_lock(context.mutex);
                context.error = 1;
                pthread_mutex_unlock(context.mutex);
                pthread_cond_signal(context.cond);

                pthread_join(prod, NULL);

                pthread_mutex_destroy(context.mutex);
                pthread_cond_destroy(context.cond);;

                return(EXIT_FAILURE);
        }

        pthread_join(prod, NULL);
        pthread_join(cons, NULL);

        pthread_mutex_destroy(context.mutex);
        pthread_cond_destroy(context.cond);

        free(context.cond);
        free(context.mutex);

        return(EXIT_SUCCESS);
}

void* producer(void* _context){
        puts("in producer");
        struct Context* context = (struct Context*)_context;

        char data[] = "Some data to send to the consumer\n";

        pthread_mutex_lock(context->mutex);
        int i;
        for(i = 0; i==sizeof(data); i++){
                if(!context->error){
                        context->holder = data[i];

                        pthread_cond_signal(context->cond);
                        pthread_cond_wait(context->cond, context->mutex);
                }else{
                        pthread_mutex_unlock(context->mutex);

                        return NULL;
                }
        }

        pthread_cond_signal(context->cond);
        pthread_mutex_unlock(context->mutex);

        return NULL;
}

void* consumer(void* _context){
        puts("in consumer");
        struct Context* context = (struct Context*)_context;

        printf("Recieving data: "); 

        pthread_mutex_lock(context->mutex);
        while(context->holder != "\0"){
                if(!context->error){
                        putc((unsigned int)context->holder, stdout);

                        pthread_cond_signal(context->cond);
                        pthread_cond_wait(context->cond, context->mutex);
                }else{
                        pthread_cond_signal(context->cond);
                        pthread_mutex_unlock(context->mutex);

                        return NULL;
                }
        }

        pthread_cond_signal(context->cond);
        pthread_mutex_unlock(context->mutex);

        return NULL;
}
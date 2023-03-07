#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>
#include<semaphore.h>

#define FILESIZE 20
#define BUFFER_SIZE 5
#define PRODUCERS 20
#define CONSUMERS 5

struct fifo_struct
{
        char fileName[1024];
        struct fifo_struct* next;
};

struct linked_list
{
        struct fifo_struct* head;
        struct fifo_struct* tail;
};

char buffer[BUFFER_SIZE][128];
int counter;

pthread_mutex_t mutex;
sem_t full, empty;


void print_queue(const struct linked_list* ps)
{
        struct fifo_struct* p = NULL;

        if(ps)
        {
                for(p = ps->head; p; p = p->next)
                {
                        if(p)
                                printf("int = %s\n", p->fileName);
                        else
                                printf("can't print NULL STRUCT\n");
                }
        }
}
void *producer(void *q);
void *consumer(void *q);
struct linked_list *s;

int main()
{
        pthread_t producerVar[PRODUCERS];
        pthread_t consumerVar[CONSUMERS];
        char str[200];
        int i = 0;
        counter = 0;
        sem_init(&full, 0, 0);
        sem_init(&empty, 0, BUFFER_SIZE);
        pthread_mutex_init(&mutex,NULL);
        struct fifo_struct* fifo;

        // Initialize the 5 buffer slots
        for(i = 0; i < BUFFER_SIZE; i++)
        {
                buffer[i][0] = '\n';
        }

        // Create linked list
        s = malloc( 1 * sizeof(*s));
        if(s == NULL)
        {
                fprintf(stderr, "LINE: %d, malloc() failed\n", __LINE__);
        }
        s->head = s->tail = NULL;

        for(i = 0; i < (FILESIZE); i++)
        {
                // Generates file names to store into queue
                sprintf(str, "in%d.txt", i);

                // Create queue to store file names
                fifo = malloc(1 * sizeof(*fifo));

                // Error in creating fifo
                if(fifo == NULL)
                {
                        fprintf(stderr, "IN %s, %s: malloc() failed\n", __FILE__, "list_add");
                }

                // Store filename into queue
                strcpy(fifo->fileName,str);
                fifo->next = NULL;

                if(s == NULL)
                {
                        printf("Error: Queue has not been initialized\n");
                }
                else if(s->head == NULL && s->tail == NULL)
                {
                        // First element in queue
                        s->head = s->tail = fifo;
                }
                else if(s->head == NULL || s->tail == NULL)
                {
                        printf("Error: Problem with code\n");
                        free(fifo);
                }
                else
                {
                        // Increments queue
                        s->tail->next = fifo;
                        s->tail = fifo;
                }
        }
        //print_queue(s);

        // Create producer threads
        for(i = 0; i < PRODUCERS; i++)
        {
                pthread_create(&producerVar[i], NULL, producer, &i);
                //pthread_join(producerVar[i], NULL);
        }
        // Create consumer threads
        for(i = 0; i < CONSUMERS; i++)
        {
                pthread_create(&consumerVar[i], NULL, consumer, s);
        }
        for(i = 0; i < PRODUCERS; i++)
        {
                pthread_join(producerVar[i], NULL);
        }

        return 0;
}

void *producer(void *idx)
{
        int myidx = * (int *) idx;
        int i = 0;
        char fileContent[1024];
        char line[1024];
        FILE * myfile;
        struct linked_list *q;
        //print_queue(q);
        struct fifo_struct* tmp1 = NULL;
        struct fifo_struct* tmp2 = NULL;
        pthread_mutex_lock(&mutex);
        printf("IN PRODUCER\n");
        q = s;
        if(q == NULL)
        {
                printf("List is empty\n");
                return(NULL);
        }
        else if(q->head == NULL && q->tail == NULL)
        {
                printf("List is empty\n");
                return(NULL);
        }
        else if(q->head == NULL || q->tail == NULL)
        {
                printf("Error: Problem with code\n");
                return(NULL);
        }

        printf("Producer: %d\n", myidx);
        //print_queue(q);
        myfile = fopen(q->head->fileName,"r");
        tmp1 = q->head;
        tmp2 = tmp1->next;
        free(tmp1);
        q->head = tmp2;

        if(q->head == NULL)
                      q->tail = q->head;
        //print_queue(q);
        printf("After printq\n");
        fflush(stdout);
        printf("\n");

        if((fgets(line, 1024, myfile)) != NULL)
        {
                strcpy(fileContent, line);
                printf("%s",fileContent);
        }
        strcpy(fileContent, line);
        printf("Myfile: %s",fileContent);
        fclose(myfile);

        while(fileContent[i] != '\n')
        {
                fileContent[i] = toupper(fileContent[i]);
                i++;
        }

        pthread_mutex_unlock(&mutex);
        sem_wait(&empty);
        if(counter < BUFFER_SIZE) {
                strncpy(buffer[counter],fileContent,128);
                printf("buffer[%d] = %s\n", counter, buffer[counter]);
                counter++;
        }

        sem_post(&full);
        return(NULL);
}

void *consumer(void *q)
{
        int myidx = * (int *) q;

        printf("\t\t\t\tCONSUMER: %d\n", myidx);

        while(1)
        {
                sem_wait(&full);
                if(counter > 0) {
                printf("\t\t\tbuffer[%d] = %s\n", counter - 1, buffer[(counter - 1)]);
                counter--;
                }
                sem_post(&empty);
        }
        return(NULL);
}
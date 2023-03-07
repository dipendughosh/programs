/* prodcons3.c is an implementation of the bounded buffer producer consumer
   problem.  In this implementation there may be any number of producers and
   any number of consumers.  The program is run with three arguments: (1) the number 
   of items to be placed in the buffer,  (2) the number of producers who will
   create the items (3) number of consumers. */
#include        <pthread.h> 
#include        <semaphore.h>
#include        <sys/time.h>    /* timeval{} for select() */
#include        <stdio.h>
#include        <stdlib.h>

#define NBUFF            10
#define MAXNTHREADS     100

int nitems, nproducers;         /* read-only by producer and consumer */

struct
{                               /* data shared by producers and consumer */
  int buff[NBUFF];
  int nput;
  int nputval;
  sem_t mutex, nempty, nstored; /* semaphores, not pointers */
}
shared;

void *produce (void *), *consume (void *);

int
main (int argc, char **argv)
{
  int i, pcount[MAXNTHREADS];
  pthread_t tid_produce[MAXNTHREADS], tid_consume;

  if (argc != 3)
    {
      printf ("Invalid no. of arguments. Need nitems and nproducers. \n");
      exit (3);
    };

  nitems = atoi (argv[1]);

  nproducers = min (atoi (argv[2]), MAXNTHREADS);

  /* initialize three semaphores */
  sem_init (&shared.mutex, 0, 1);
  sem_init (&shared.nempty, 0, NBUFF);
  sem_init (&shared.nstored, 0, 0);

  /* create all producers and one consumer */
  for (i = 0; i < nproducers; i++)
    {
      pcount[i] = 0;
      pthread_create (&tid_produce[i], NULL, produce, &pcount[i]);
    }
  pthread_create (&tid_consume, NULL, consume, NULL);

  /* wait for all producers and the consumer */
  for (i = 0; i < nproducers; i++)
      pthread_join (tid_produce[i], NULL);
  pthread_join (tid_consume, NULL);

  printf ("\n Number of buffer items contributed by each thread: \n");
  for (i = 0; i < nproducers; i++)
      printf ("pcount[%d] = %d\n", i, pcount[i]);
  sem_destroy (&shared.mutex);
  sem_destroy (&shared.nempty);
  sem_destroy (&shared.nstored);
  exit (0);
}
/* end main */

/* include produce */
void *
produce (void *arg)
{
  for (;;)
    {
      sem_wait (&shared.nempty);        /* wait for at least 1 empty slot */
      sem_wait (&shared.mutex);

      if (shared.nput >= nitems)
        {
          sem_post (&shared.nempty);
          sem_post (&shared.mutex);
          return (NULL);        /* all done */
        }
      shared.buff[shared.nput % NBUFF] = shared.nputval;
      printf ("p:%d ", shared.nputval);
      shared.nput++;
      shared.nputval++;
      sem_post (&shared.mutex);
      sem_post (&shared.nstored);       /* 1 more stored item */
      *((int *) arg) += 1;   /*increment count of items contributed by this thread. */
    }
}
/* end produce */

/* include consume */
void *
consume (void *arg)
{
  int i;

  for (i = 0; i < nitems; i++)
    {
      sem_wait (&shared.nstored);       /* wait for at least 1 stored item */
      sem_wait (&shared.mutex);
      if (shared.buff[i % NBUFF] != i)
        printf ("error: buff[%d] = %d\n", i, shared.buff[i % NBUFF]);
      printf ("c:%d ", shared.buff[i % NBUFF]);
      sem_post (&shared.mutex);
      sem_post (&shared.nempty);        /* 1 more empty slot */
    }
  return (NULL);
}
/* end consume */
int
min (int a, int b)
{
  if (a < b)
    return a;
  else
    return b;
}

 /*i got this to work for only 1 consumer but im having trouble , cause it wont work when i specify the number of  consumers as a parameter please help

my script file

# Compile the producer consumer program.
gcc -c prodcons3.c

# Link the program using the POSIX C threads library
gcc  -D_REENTRANT -lpthread -o prodcons3 prodcons3.o

# Run the program. The first parameter is the number of items.
# The second is the number of producer processes.  In prodcons2 there
# is only one consumer process.
./prodcons2 500 10 10
*/
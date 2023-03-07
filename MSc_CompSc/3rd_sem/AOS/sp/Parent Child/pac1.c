#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main ()
{
   int pid, j, i;
   int pfds[2];
   pipe(pfds);
   char buf[30];

   int once = 0;
   pid = fork();



   if (pid == 0)
   {

      for (j=0; j < 10; j++)
      {
    	  printf ("Child :  %d (PID: %d)\n", j, getpid());
    	  write(pfds[1], "test", 5);
	  sleep (1);
      }
      exit (0);
   }
   else if (pid > 0)
   {
      for (i=0; i < 10; i++)
      {
         printf ("Parent: %d (PID: %d)\n", i, getpid());
         read(pfds[0], buf, 5);
         printf("PARENT: read \"%s\"\n", buf);

         sleep (1);
      }
   }
   else
   {
      fprintf (stderr, "Error");
      exit (1);
   }
   return 0;
}

#include <stdio.h>   /* printf, stderr, fprintf */
#include <unistd.h>  /* fork */
#include <stdlib.h>  /* exit */
#include <errno.h>   /* errno */

int main(void)
{
   pid_t  pid;
   int gv=0;
   /* Output from both the child and the parent process
    * will be written to the standard output,
    * as they both run at the same time.
    */
   pid = fork();
   if (pid == 0)
   {
      int clv=0;
      /* Child process:
       * When fork() returns 0, we are in
       * the child process.
       * Here we count up to ten, one each second.
       */
      gv++;
      clv++;
      int j;
      for (j = 0; j < 2; j++)
      {
         printf("Child Process:-\nC PID :-- %d\nC Local Variable :-- %d\nC Global Variable :-- %d\n",pid,clv,gv);
         sleep(1);
      }
      /*gv++;
      clv++;
      printf("Child Process:-\nC PID :-- %d\nC Local Variable :-- %d\nC Global Variable :-- %d\n",pid,clv,gv);*/
      exit(0); 
   }
   else if (pid > 0)
   { 
      int plv=0;
      /* Parent process:
       * When fork() returns a positive number, we are in the parent process
       * (the fork return value is the PID of the newly-created child process).
       * Again we count up to ten.
       */
      gv++;
      plv++;
      int i;
      for (i = 0; i < 2; i++)
      {
         printf("Parent Process:-\nP PID :-- %d\nP Local Variable :-- %d\nP Global Variable :-- %d\n",pid,plv,gv);
         sleep(1);
      }
      /*
      gv++;
      plv++;
      printf("Parent Process:-\nP PID :-- %d\nP Local Variable :-- %d\nP Global Variable :-- %d\n",pid,plv,gv);*/
      exit(0);
   }
   else
   {   
      /* Error:
       * When fork() returns a negative number, an error happened
       * (for example, number of processes reached the limit).
       */
      fprintf(stderr, "can't fork, error %d\n", errno);
      exit(EXIT_FAILURE);
   }
}

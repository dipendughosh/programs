#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdbool.h>
#include <sys/types.h>

#define MAXBUF 20
#define FALSE 0
#define TRUE 1

struct sockaddr_in sockme;
int s;

struct servent *pse;
char * transport = "tcp";
int portnum;
char *hostnum;

char bufout[MAXBUF+1];
char bufin[MAXBUF+1];
char *cp;
char c;

int result;
int n;

int main(int argc, char *argv[])
{

	if (argc == 3) {
		hostnum = argv[1];
		(void) sscanf(argv[2], "%d", &portnum);
	}
	else {
		(void) printf("usage: client <hostnum> <portnum>\n");
		exit(-1);
	}

	sockme.sin_family = AF_INET;

	if ((sockme.sin_addr.s_addr = inet_addr(hostnum)) == INADDR_NONE) {
		(void) printf("Invalid dotted decimal address\n");
		exit(-1);
	}

	sockme.sin_port = htons(portnum);
	
	if((s = socket(PF_INET, SOCK_STREAM, 0)) == 0)
	{
		/* if socket failed then display error and exit */
		perror("Create socket");
		exit(EXIT_FAILURE);
	}

	if ((result = connect (s, (struct sockaddr *) &sockme, sizeof(sockme)))) {
		perror("Connect failed\n");
		close (s);
		exit(-1);
	};

	(void) printf("Enter Message: \n");
	cp = bufout;
	while ((c = getchar()) != '\n') {
		*cp++ = c;
	}
	*cp = '\0';
	
	result = send (s, bufout, strlen(bufout), 0);
	
	if(result != strlen(bufout)){
		perror("send");
		exit(EXIT_FAILURE);
	}
	
	printf("Message Sent.\nWaiting for response.\n");
	
	do{
		n = read ( s, bufin, MAXBUF );
	}while(n != 0);
	
	(void) printf("Recieved: %s\n", bufin);
	result = close(s);

	return 0;
}
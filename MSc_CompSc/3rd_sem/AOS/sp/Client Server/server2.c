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

struct sockaddr_in sockme, newsockme;
int s, childs;
char *hostnum;

int type;
int portnum;

int result;

char bufout[MAXBUF+1];
char bufin[MAXBUF+1];
char *cp;
char c;

int n;


int main(int argc, char *argv[])
{

	if (argc == 2) {
		(void) sscanf(argv[1], "%d", &portnum);
	}
	else {
		(void) printf("usage: server <portnum>\n");
		exit(-1);
	}
	
	sockme.sin_family = AF_INET;
	sockme.sin_addr.s_addr = INADDR_ANY;
	sockme.sin_port = htons(portnum);

	/* the following socket is used to listen for incoming connection
	 * requests by any clients
	 */
	
	if((s = socket(PF_INET, SOCK_STREAM, 0)) == 0)
	{
		/* if socket failed then display error and exit */
		perror("Create socket");
		exit(EXIT_FAILURE);
	}


	result = bind(s, (struct sockaddr *) &sockme, sizeof(sockme));
	
	if(result < 0){
		perror("bind");
		exit(-1);
	}
		
	result = listen(s, 5);
	
	if(result < 0){
		perror("listen");
		exit(-1);
	}

	while (1) {
		socklen_t alen = sizeof(newsockme);
		
		childs = accept(s, (struct sockaddr *) &newsockme, &alen);
		if(childs < 0){
			perror("accept");
			exit(-1);
		}
		printf("Handling client %s\n", inet_ntoa(newsockme.sin_addr));
		
		
		do{
			n = read ( s, bufin, MAXBUF );
		}while(n != 0);
		
		bufin[MAXBUF] = '\0';
	
		(void) printf("Message recieved: %s\n", bufin);
		(void) printf("Sending: %s\n", bufin);
		
		result = send (childs, bufin, strlen(bufin), 0);
		result = close(childs);
	}

	return 0;
}

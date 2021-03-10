//CLIENT PROGRAM
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	
//SOCKET
int fd = socket( AF_INET, SOCK_STREAM , 0);
if( fd == -1 )
{
	printf("Socket Failed\n");
	exit(0);
}
else
printf("Socket Success\n");


//Connect
struct sockaddr_in connectaddr;
connectaddr.sin_family=AF_INET;
connectaddr.sin_port=htons(8085);
connectaddr.sin_addr.s_addr=INADDR_ANY;
int connect_ret= connect ( fd, (struct sockaddr*)(&connectaddr), sizeof(connectaddr));
if (connect_ret==-1)
{
	printf("Connect Failed");
	exit(0);
}
else
	printf("Connect Success");

while(1)
{

//Send
printf("Enter the message to send now:- ");
char msg_send[50];
scanf("%s",msg_send);
struct sockaddr_in senda;
senda.sin_family=AF_INET;
senda.sin_port=htons(8085);
senda.sin_addr.s_addr = INADDR_ANY;

int send_ret = send( fd , msg_send , strlen(msg_send) , 0 );
if(send_ret == -1)
{
	printf("Send Failed");
	exit(0);
}
else
{
	if(strcmp("bye",msg_send)==0)
	{
		exit(0);
	}
	printf("Send Success\n");
}


//recv
char msg_recv[50];
int recv_ret = recv( fd , msg_recv , sizeof(msg_recv), 0 );
if( recv_ret == -1 )
{
	printf("Receive Failed");
	exit(0);
}
else
{
	if(strcmp("bye",msg_recv)==0)
	{
		exit(0);
	}
	printf("Message Received:- %s\n",msg_recv);
}



//end of while
}

}

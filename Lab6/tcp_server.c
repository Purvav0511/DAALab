//SERVER PROGRAM
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
 #include <sys/socket.h>
       #include <netinet/in.h>
       #include <arpa/inet.h>


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


//Bind
struct sockaddr_in bind_send;
bind_send.sin_family=AF_INET;
bind_send.sin_port=htons(8085);
bind_send.sin_addr.s_addr=INADDR_ANY;

int bind_ret = bind( fd, (struct sockaddr *) &bind_send , sizeof(bind_send));

if(bind_ret == -1)
{
	printf("Bind Failed");
	exit(0);
}
else
	printf("Bind Success\n");


//Listen
int listen_ret= listen( fd, 10);
if(listen_ret == -1)
{
	printf("Listen Failed");
	exit(0);
}
else
	printf("Listen Success\n");

//Accept
struct sockaddr_in bind_accept;
int len = sizeof(bind_accept);
int accept_fd=accept( fd, (struct sockaddr *) &bind_accept, &len);
if(accept_fd==-1)
{
	printf("Accept Failed");
	exit(0);
}
else
	printf("Accept Success\n");


while(1)
{

//recv
char msg_recv[50];
struct sockaddr_in recva;
int name=sizeof(recva);
int recvfrom_ret = recv( accept_fd , msg_recv , sizeof(msg_recv), 0 );
if( recvfrom_ret == -1 )
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
	
	int t=getsockname(accept_fd, (struct sockaddr*)(&recva),&len); 
	printf("\nSocket:- %d\n",htons(recva.sin_port));
	printf("IP:- %s\n", inet_ntoa(recva.sin_addr));
}

//Send
printf("Enter the message to send now:- ");
char msg_send[50];
scanf("%s",msg_send);
struct sockaddr_in senda;
senda.sin_family=AF_INET;
senda.sin_port=htons(8085);
senda.sin_addr.s_addr = INADDR_ANY;


int send_ret = send( accept_fd , msg_send , strlen(msg_send) , 0 );
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


//end of while
}

printf("\nThe message to send now:");

char msg_send [50]:

int mtu, msglen, nofrg;

scanf("%s" msg_send); 
printf("Enter MTU size: );

scanf("%d", &mtu);

msglen= strlen(msg_send):

struct fragment
{
int identification;
int a;
int fragmentation_offset;
char buffer[mtu];
}
if(msglen > mtu)
{

if(msglen/mtu==0)
	nofrg=msglen/mtu;
else

	nofrg = msglen/mtu+1;

struct fragment arr[nofrg];
}


}

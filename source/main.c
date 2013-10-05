#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

int main(int argc, char* argv[])
{
	int sockfd = 0, connfd = 0;
	struct sockaddr_in serv_addr;

	char sendBuff[1025];
	time_t ticks;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	memset(&serv_addr, '0', sizeof(serv_addr));
	memset(sendBuff, '0', sizeof(sendBuff));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(5000);

	bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

	listen(sockfd, 10);

	while(1)
	{
		connfd = accept(sockfd, (struct sockaddr*)NULL, NULL);

		char *welcome_msg = "Welcome to the Server";
		int welcome_len = strlen(welcome_msg);
		int bytes_sent = 0;
		while (bytes_sent < welcome_len)
		{
			bytes_sent = send(connfd, welcome_msg, welcome_len, 0);
		}
		send(connfd, "\n", 2, 0);
		close(connfd);
		sleep(1);
	}

	return 0;
}
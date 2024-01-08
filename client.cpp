#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <sys/types.h>
#include <unistd.h>

int main(){
	int clientFd = socket(AF_INET, SOCK_STREAM,0);

	struct sockaddr_in clientAddr = {
	AF_INET,
	htons(8443),
	inet_addr("0.0.0.0"),
};

	connect(clientFd, (struct sockaddr*)&clientAddr, sizeof(clientAddr));

	char buffer[256];
	ssize_t bytesRead = recv(clientFd, buffer, sizeof(buffer), 0);
	buffer[bytesRead] = '\0';

	std::cout << "Message Recieved: "<< buffer <<  std::endl;


	close(clientFd);



	return 0;
}

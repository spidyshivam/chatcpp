#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(){
	int sockfd = socket(AF_INET, SOCK_STREAM,0);

	struct sockaddr_in addr = {
	AF_INET,
	htons(8443),
	INADDR_ANY
};

	struct sockaddr_in iteraddr;

	bind(sockfd, (struct sockaddr*)&addr, sizeof(addr));

	listen(sockfd, 10);

	socklen_t iteraddr_len = sizeof(iteraddr);
	int itterfd = accept(sockfd, (struct sockaddr*)&iteraddr, &iteraddr_len);


	send(itterfd, "Conected to Shivam's Chat\n",30 ,0 );

	close(sockfd);
	close(itterfd);

	return 0;
}

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT    5000
#define MAXLINE 1000

int main() {
    char buffer[MAXLINE];
    char *message = "Hello Client";
    int listenfd;
    socklen_t len;
    struct sockaddr_in servaddr, cliaddr;

    bzero(&servaddr, sizeof(servaddr));

    listenfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (listenfd < 0) {
        perror("socket creation failed");
        return 1;
    }

    servaddr.sin_family      = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port        = htons(PORT);

    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        return 1;
    }

    while (1) {
        len  = sizeof(cliaddr);
        int n = recvfrom(listenfd, buffer, MAXLINE, 0, (struct sockaddr *)&cliaddr, &len);
        if (n < 0) {
            perror("recvfrom failed");
            continue;
        }

        buffer[n] = '\0';
        printf("Client: %s\n", buffer);

        sendto(listenfd, message, strlen(message), 0, (struct sockaddr *)&cliaddr, len);
    }

    return 0;
}

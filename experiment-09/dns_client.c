#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sockfd;
    struct sockaddr_in server;
    char domain[50], response[100];

    memset(&server, 0, sizeof(server));
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
#ifdef __APPLE__
    server.sin_len = sizeof(server);
#endif

    if (connect(sockfd, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("connect");
        close(sockfd);
        return 1;
    }

    printf("Enter domain name: ");
    if (scanf("%49s", domain) != 1) {
        fprintf(stderr, "Failed to read domain name\n");
        close(sockfd);
        return 1;
    }

    if (send(sockfd, domain, strlen(domain), 0) < 0) {
        perror("send");
        close(sockfd);
        return 1;
    }

    int bytes = recv(sockfd, response, sizeof(response) - 1, 0);
    if (bytes < 0) {
        perror("recv");
        close(sockfd);
        return 1;
    }
    response[bytes] = '\0';
    printf("IP Address: %s\n", response);

    close(sockfd);
    return 0;
}
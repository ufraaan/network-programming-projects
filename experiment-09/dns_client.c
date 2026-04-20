#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sockfd;
    struct sockaddr_in server;
    char domain[50], response[100];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sockfd, (struct sockaddr*)&server, sizeof(server));

    printf("Enter domain name: ");
    scanf("%49s", domain);

    send(sockfd, domain, strlen(domain), 0);

    int bytes = recv(sockfd, response, sizeof(response) - 1, 0);
    response[bytes] = '\0';
    printf("IP Address: %s\n", response);

    close(sockfd);
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

struct dns {
    char domain[50];
    char ip[50];
} dns_db[] = {
    {"google.com",   "142.250.190.78"},
    {"facebook.com", "157.240.22.35"},
    {"youtube.com",  "142.250.190.14"},
    {"openai.com",   "104.18.12.123"}
};

#define DB_SIZE (sizeof(dns_db) / sizeof(dns_db[0]))

int main() {
    int sockfd, new_sock;
    struct sockaddr_in server, client;
    char buffer[100];
    socklen_t len;
    int found;

    memset(&server, 0, sizeof(server));
    memset(&client, 0, sizeof(client));
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = INADDR_ANY;
#ifdef __APPLE__
    server.sin_len = sizeof(server);
#endif

    if (bind(sockfd, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("bind");
        close(sockfd);
        return 1;
    }

    if (listen(sockfd, 5) < 0) {
        perror("listen");
        close(sockfd);
        return 1;
    }
    printf("DNS Server is running...\n");

    while (1) {
        len = sizeof(client);
        new_sock = accept(sockfd, (struct sockaddr*)&client, &len);
        if (new_sock < 0) {
            perror("accept");
            continue;
        }

        int bytes = recv(new_sock, buffer, sizeof(buffer) - 1, 0);
        if (bytes < 0) {
            perror("recv");
            close(new_sock);
            continue;
        }
        buffer[bytes] = '\0';
        printf("Client requested: %s\n", buffer);

        found = 0;
        for (int i = 0; i < (int)DB_SIZE; i++) {
            if (strcmp(buffer, dns_db[i].domain) == 0) {
                send(new_sock, dns_db[i].ip, strlen(dns_db[i].ip), 0);
                found = 1;
                break;
            }
        }

        if (!found) {
            char msg[] = "Domain not found";
            if (send(new_sock, msg, strlen(msg), 0) < 0) {
                perror("send");
            }
        }

        close(new_sock);
    }

    close(sockfd);
    return 0;
}
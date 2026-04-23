#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "echo.h"

int main(int argc, char *argv[]) {
    CLIENT *clnt;
    char **result;
    char *message;

    if (argc != 3) {
        printf("Usage: %s <server_host> <message>\n", argv[0]);
        exit(1);
    }

    message = argv[2];

    clnt = clnt_create(argv[1], ECHO_PROG, ECHO_VERS, "udp");
    if (clnt == NULL) {
        clnt_pcreateerror(argv[1]);
        exit(1);
    }

    result = echo_1(&message, clnt);
    if (result == NULL) {
        clnt_perror(clnt, "RPC call failed");
        clnt_destroy(clnt);
        exit(1);
    }

    printf("Message sent : %s\n", message);
    printf("Echo from server: %s\n", *result);

    clnt_destroy(clnt);
    return 0;
}
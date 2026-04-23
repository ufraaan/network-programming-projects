#include <stdio.h>
#include <stdlib.h>
#include "day.h"

int main(int argc, char *argv[]) {
    CLIENT *clnt;
    time_out *result;

    if (argc != 2) {
        printf("Usage: %s <server_host>\n", argv[0]);
        exit(1);
    }

    clnt = clnt_create(argv[1], DAY_PROG, DAY_VERS, "udp");
    if (clnt == NULL) {
        clnt_pcreateerror(argv[1]);
        exit(1);
    }

    result = gettime_1(NULL, clnt);
    if (result == NULL) {
        clnt_perror(clnt, "RPC call failed");
        clnt_destroy(clnt);
        exit(1);
    }

    printf("Current Date and Time from Server: %s", result->current_time);

    clnt_destroy(clnt);
    return 0;
}
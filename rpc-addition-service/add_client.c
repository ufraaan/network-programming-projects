#include <stdio.h>
#include <stdlib.h>
#include "add.h"

int main(int argc, char *argv[]) {
    CLIENT *cl;
    numbers num;
    int *result;

    if (argc != 4) {
        printf("Usage: %s <server_ip> <num1> <num2>\n", argv[0]);
        exit(1);
    }

    cl = clnt_create(argv[1], ADD_PROG, ADD_VERS, "tcp");
    if (cl == NULL) {
        clnt_pcreateerror(argv[1]);
        exit(1);
    }

    num.a = atoi(argv[2]);
    num.b = atoi(argv[3]);

    result = add_1(&num, cl);
    if (result == NULL) {
        clnt_perror(cl, "Call failed");
        clnt_destroy(cl);
        exit(1);
    }

    printf("%d + %d = %d\n", num.a, num.b, *result);

    clnt_destroy(cl);
    return 0;
}
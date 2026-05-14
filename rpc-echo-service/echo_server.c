#include "echo.h"
#include <string.h>
#include <stdlib.h>

char **echo_1_svc(char **argp, struct svc_req *rqstp) {
    static char *result = NULL;

    if (result != NULL) {
        free(result);
    }

    result = strdup(*argp);
    return &result;
}
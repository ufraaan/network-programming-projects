#include "day.h"
#include <time.h>
#include <string.h>

time_out *gettime_1_svc(void *argp, struct svc_req *rqstp) {
    static time_out result;
    time_t now;
    char *time_str;

    time(&now);
    time_str = ctime(&now);

    result.current_time = time_str;

    return &result;
}
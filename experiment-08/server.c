#include "day.h"
#include <time.h>
#include <string.h>

time_out *gettime_1_svc(struct svc_req *rqstp) {
    static time_out result;
    static char time_buf[64];
    time_t now;
    char *time_str;

    time(&now);
    time_str = ctime(&now);

    strncpy(time_buf, time_str, sizeof(time_buf) - 1);
    time_buf[sizeof(time_buf) - 1] = '\0';

    result.current_time = time_buf;
    return &result;
}
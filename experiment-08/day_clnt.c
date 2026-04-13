#include <memory.h>
#include <string.h>
#include "day.h"

static struct timeval TIMEOUT = { 25, 0 };

time_out *
gettime_1(CLIENT *clnt)
{
    static time_out clnt_res;

    memset((char *)&clnt_res, 0, sizeof(clnt_res));
    if (clnt_call(clnt, GETTIME,
            (xdrproc_t) xdr_void, NULL,
            (xdrproc_t) xdr_time_out, (caddr_t) &clnt_res,
            TIMEOUT) != RPC_SUCCESS) {
        return (NULL);
    }
    return (&clnt_res);
}
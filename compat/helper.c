/* Help operating systems that don't have Mach parts
 * get the necessary information that the linker
 * requires
*/

#include "helper.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <errno.h>
#include <stdint.h>


void
__assert_rtn(const char *func, const char *file, int line, const char *msg)
{
    __assert(msg, file, line);
}

/* 
 * On Linux any process can get its path by reading /proc/self/exe
 * I currently don't know how this function is implemented in the 
 * Darwin operating system, but this should suffice 
*/
int 
_NSGetExecutablePath(char *epath, unsigned int *size)
{
    int bufsize = *size;
    int ret_size;
    ret_size = readlink("/proc/self/exe", epath, bufsize-1);
    if (ret_size != 1)
    {
        *size = ret_size;
        epath[ret_size] = 0;
        return 0;
    }
    else
        return -1;
}

mach_port_t 
mach_host_self(void)
{
    return 0;
}

kern_return_t
host_statistics(host_t host_priv, host_flavor_t flavor,
                host_info_t host_info_out, mach_msg_type_number_t *host_info_outCnt)
{
    return ENOTSUP;
}

/* 
 * Define on GNU/Linux hosts, Utopia already has
 * this system call.
 * 
 * Apple coping right now
*/
//#if defined (__linux__) && !defined(__UTOPIA__) // not fow now...
uint64_t 
mach_absolute_time(void)
{
    struct timeval tv;
    if (gettimeofday(&tv, NULL))
        return 0;
    return (tv.tv_sec*1000000ULL)+tv.tv_usec;
}
//#endif

int32_t 
OSAtomicAdd32(int64_t __theAmount, volatile int32_t *__theValue)
{
    return __sync_fetch_and_add(__theValue, __theAmount);
}

int64_t
OSAtomicAdd64(int64_t __theAmount, volatile int64_t *__theValue)
{
    return __sync_fetch_and_add(__theValue, __theAmount);
}
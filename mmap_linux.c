#include <sys/mman.h>
#include <fcntl.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include "error.h"

#define BUF_SIZE 4096   /* Maximum size for exchanged string */

typedef struct shmbuf {
               sem_t  sem1;            /* POSIX unnamed semaphore */
               sem_t  sem2;            /* POSIX unnamed semaphore */
               size_t cnt;             /* Number of bytes used in 'buf' */
               char   buf[BUF_SIZE];   /* Data being transferred */
           }shmbuf;

/* Create shared memory object and set its size to the size
of our structure */
err_code open_shm(char *shm_path, int recov) {
    if (!shm_path)
    {
        return NULL_PATH;    
    }
    int accFlags = 0;
    // Check flags for read, write, execute, exist.
    int fd = shm_open(shm_path, O_RDWR |
                                 O_EXCL,
                                 S_IRUSR |
                                 S_IWUSR);
    if (fd < 0)
    {
        return handle_error(errno);
    }  
    if (!recov)
    {
        if (ftruncate(fd, sizeof(struct shmbuf)) == -1)
            return handle_error(errno);
    }
}

err_code crt_shm(char *path) {
    if (!path)
    {
        return NULL_PATH;
    }

    int fd = shm_open(path, O_RDWR  |
                            O_CREAT |
                            O_EXCL,
                            S_IRUSR |
                            S_IWUSR);
    if (fd < 0)
    {
        return handle_error(errno)
    }

    if (ftruncate(fd, sizeof(struct shmbuf)))
    
}
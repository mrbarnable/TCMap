#ifndef __ERROR_H
#define __ERROR_H

typedef int err_code;

const err_code NULL_PATH = -1;
const err_code INVALID_PATH = -2;
const err_code ACCESS_DENIED = -3;
const err_code NAME_TOO_LONG = -4;
const err_code FILE_NOT_EXIST = -5;
const err_code FILE_EXIST = -6;

#ifdef __linux__ 
#include <errno.h>

err_code handle_error(int code) {
    switch (code)
    {
    //#define ENOENT  2  /* No such file or directory */
    case 2:

    // #define EACCES 13 /* Permission denied */
    case 13:
        return ACCESS_DENIED;
        break;
    // #define EEXIST 17 /* File exists */
    case 17:
        return FILE_EXIST;
    // #define ENAMETOOLONG 36 /* File name too long */
    case 36:
        return NAME_TOO_LONG;
        break;
    default:
        break;
    }
}
#elif _WIN32
    // windows code goes here
#else

#endif

#endif // __ERROR_H
#include <stdio.h>
#include <stdarg.h>

#include "print.h"

int verbose;

int verbose_print(const char* format, ...) {
    int ret;
    if (!verbose)
        return 0;

    va_list args;
    va_start(args, format);
    ret = vprintf(format, args);
    va_end(args);

    return ret;
}

#include <stdio.h>
#include <stdarg.h>

#include "print.h"

/// A variable describing whether the verbose_print should print to console.
int verbose;

/**
 * @brief A simple wrapper over printf.
 *
 * Chooses to write out to console based on the value of the verbose variable.
 *
 * @param format A string holding the format to be printed
 * @param ... Variable arguments used to format the string.
 * @return int Same as vprintf...
 */
int verbose_print(const char* restrict format, ...) {
    int ret;
    if (!verbose)
        return 0;

    va_list args;
    va_start(args, format);
    ret = vprintf(format, args);
    va_end(args);

    return ret;
}

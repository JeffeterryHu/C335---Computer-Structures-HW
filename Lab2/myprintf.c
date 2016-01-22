/* myprintf.c
 *
 * Author: Shichao Hu
 * Date Created: 1/21/2016
 * Last Modified by: Shichao Hu
 * Date Last Modified: 1/21/2016
 * Assignment: my own printf
 * Part of: Lab2
 */


#include <stdarg.h>
#include <stdio.h>

void myprintf(const char *fmt, ...) {
    const char *p;
    va_list argp;
    int i;
    char *s;

    va_start(argp, fmt);

    for (p = fmt; *p != '\0'; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        switch (*++p) {
        case 'c':
            i = va_arg(argp, int);
            putchar(i);
            break;

        case 'd':
            i = va_arg(argp, int);
            printint(i);
            break;

        case 's':
            s = va_arg(argp, char *);
            printstring(s);
            break;

        case 'x':
            i = va_arg(argp, int);
            printhex(i);
            break;

        case '%':
            putchar('%');
            break;
        }
    }
    va_end(argp);
}

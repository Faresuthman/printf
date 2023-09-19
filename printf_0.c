#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: A format string.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;

    va_start(args, format);

    while (format && *format)
    {
        if (*format == '%')
        {
            format++; // Move past '%'

            if (*format == '\0') // Handle a '%' at the end of the string
                break;

            if (*format == 'c')
            {
                int c = va_arg(args, int);
                putchar(c);
                count++;
            }
            else if (*format == 's')
            {
                char *s = va_arg(args, char *);
                if (s)
                {
                    while (*s)
                    {
                        putchar(*s);
                        count++;
                        s++;
                    }
                }
            }
            else if (*format == '%')
            {
                putchar('%');
                count++;
            }
        }
        else
        {
            putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);
    return count;
}


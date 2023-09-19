#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: A format string.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
    int count = 0;  // To keep track of the number of characters printed
    va_list args;   // A list to hold the variable arguments

    va_start(args, format);  // Initialize the argument list

    while (format && *format)
    {
        if (*format == '%')
        {
            format++; // Move past '%'

            if (*format == '\0') // Handle a '%' at the end of the string
                break;

            if (*format == 'c')
            {
                // Handle character specifier
                int c = va_arg(args, int);
                write(1, &c, 1); // Write the character to stdout
                count++;
            }
            else if (*format == 's')
            {
                // Handle string specifier
                char *s = va_arg(args, char *);
                if (s)
                {
                    int len = 0;
                    while (s[len])
                        len++;
                    write(1, s, len); // Write the string to stdout
                    count += len;
                }
                else
                {
                    // Handle NULL string
                    write(1, "(null)", 6);
                    count += 6;
                }
            }
            else if (*format == '%')
            {
                // Handle '%' specifier
                write(1, "%", 1); // Write '%' to stdout
                count++;
            }
        }
        else
        {
            // Normal character, not a specifier
            write(1, format, 1); // Write the character to stdout
            count++;
        }
        format++; // Move to the next character in the format string
    }

    va_end(args); // Clean up the argument list
    return count; // Return the total number of characters printed
}


#include "main.h"
#include <stdarg.h>

int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int char_count = 0;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c': 
					putchar(va_arg(args, int)); 
					break;
				case 's': 
					for (char *str = va_arg(args, char *); *str; str++) 
						putchar(*str);
					break;
				case '%': 
					putchar('%'); 
					break;
				default: 
					putchar('%'); 
					putchar(*format); 
					char_count++;
			}
		}
		else
		{
			putchar(*format);
			char_count++;
		}
		format++;
	}

	va_end(args);
	return char_count;
}

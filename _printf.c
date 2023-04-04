#include "main.h"

int (*fmt_specifier(const char *fmt))(va_list);
/**
 * _printf - prints any given output to the screen
 * @format: string
 * @...: represent large number of argument
 * Return: -1 for null or total times looped
 */

int _printf(const char *format, ...)
{
        va_list pf;

        int i = 0, count = 0, total = 0;
        int (*f)(va_list);

        va_start(pf, format);

        if (format == NULL) /*prevent null pointer*/
                return (-1);
        while (format[i])
        {
		if (format[i] != '%')
                {
                        count = write(1, &format[i], 1); /*strings without format specifier*/
                        total += count;
                        i++;
                        continue;
                }
                if (format[i] == '%')
                {
                        f = fmt_specifier(&format[i + 1]); /*building on format specifier*/
                        if (f != NULL)
                        {
                                count = f(pf);
                                total += count;
                                i += 2;
                                continue;
                        }
                        if (format[i + 1] == '\0')
                                break;
                        if (format[i + 1] != '\0')
                        {
                                count = write(1, &format[i + 1], 1);
				      total += count;
                                i += 2;
                                continue;
                        }
                } i++;
        } return (total);
        va_end(pf);
}

/**
 * fmt_specifier - function that checks for valid format specifier
 * and assigns an appropriate function for printing
 * @fmt: input the function takes
 * Return: null or char
 */

int (*fmt_specifier(const char *fmt))(va_list)
{
        int i;

        /* struct array that holds all format specifier*/
        fun_t my_array[11] = {
                {"c", print_char},
		{"s", print_str},
                {"%", print_pcent},
                {"d", print_dec},
                {"i", print_dec},
                {"b", print_binary},
                {"u", print_u},
                {"o", print_octal},
                {"x", print_hex},
                {"X", print_HEX},
                {NULL, NULL}
        };

        /* loops through struct, searching for format requested*/
        /* returns null if not found*/
        for (i = 0; my_array[i].t != NULL; i++)
        {
                if (*(my_array[i].t) == *fmt)
                {
                        return (my_array[i].f);
                }
        }
        return (NULL);
}

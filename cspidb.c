#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - function to print/pass character as output
 * @pf: variadic function recieve as input
 * Return: 0
 */

int print_char(va_list pf)
{
        int count = 0;
        char c;

        c = (char)va_arg(pf, int);

        if (c)
        {
                count = write(1, &c, 1);
                return (count);
        }

        return (0);
}
/************************* PRINT A STRING *************************/
/**
 * print_str - function to print/pass string as output
 * @pf: variadic function to recieve as input
 * Return: number of strings passed in
 */

int print_str(va_list pf)
{
        int count = 0, i = 0;
        char *str;

        str = va_arg(pf, char *);

        if (str == NULL)
                return (-1);

        while (str[i])
        {
                count = write(1, &str[i], 1);
                i++;
        }
	
                return (count);
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Prints a percent sign
 * @pf: recevie varadic function
 * Return: Number of chars printed
 */
int print_pcent(va_list pf)
{
        (void)pf;
        write(1, "%", 1);

        return (0);
}

/************************* PRINT INT *************************/
/**
 * print_dec - function converts an integer to a string
 * @pf: The integer to convert
 * Return: pointer to the buffer containing the string
 * representation of the integer
 */

int print_dec(va_list pf)
{
        char buffer[20];
        int i = 0, j, is_negative = 0, n;

        n = va_arg(pf, int);

        if (n < 0)
        {
                is_negative = 1;
                n = -n;
        }
        do {
                buffer[i++] = n % 10 + '0';
                n /= 10;
        } while (n > 0);

        if (is_negative)
                buffer[i++] = '-';

        for (j = i - 1; j >= 0; j--)
                write(1, &buffer[j], 1);
        return (0);
}
/************************* PRINT BINARY *************************/
/**
 * print_binary - print in binary
 * @pf: variadic input
 * Return: count
 */

int print_binary(va_list pf)
{
        unsigned int num, mod, i;
        size_t size = 32;
        size_t count = 0;
        char *binary = NULL;

        num = va_arg(pf, unsigned int); /* expecting a positive num */

        if (num == 0) /* if the num input is zero; print 0 and return success(1) */
        {
                write(1, "0", 1);
                return (1);
        }

        binary = malloc(size + 1); /* create space to receive binary digits */
        if (binary == NULL) /* if allocation is not successful return -1 */
                return (-1);

        while (num > 0) /* convert num to binary */
        {
                mod = num % 2;
                num /= 2;
		if (count >= size)
                {
                        size *= 2; /* if initial space is not enough then double it */
                        binary = realloc(binary, size + 1); /* add +1 for null terminator '\0' */
                        if (binary == NULL) /* if allocation is not successful return -1 */
                                return (-1);
                }
                binary[count++] = mod + '0';
        }
        binary[count] = '\0'; /* add null terminator */

        for (i = count; i > 0; i--) /* reverse string and print */
                write(1, &binary[i - 1], 1);

        free(binary); /* free allocated memory */
        return (count);
}

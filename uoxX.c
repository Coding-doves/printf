#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Prints an unsigned number
 * @pf: List a of arguments
 * 
 * Return: Number of chars printed.
 */
int print_u(va_list pf)
{
        unsigned int num, mod, i;
        size_t size = 32;
        size_t count = 0;
        char *buff = NULL;

        num = va_arg(pf, unsigned int); /* expecting a positive num */

        if (num == 0) /* if the num input is zero; print 0 and return success(1) */
        {
                write(1, "0", 1);
                return 1;
        }

        buff = malloc(size + 1); /* create space to receive binary digits */
        if (buff == NULL) /* if allocation is not successful return -1 */
                return -1;
	while (num > 0) /* convert num to binary */
        {
                mod = num % 10;
                num /= 10;
        if (count >= size)
        {
                size *= 2; /* if initial space is not enough then double it */
                buff = realloc(buff, size + 1); /* add +1 for null terminator '\0' */
                if (buff == NULL) /* if allocation is not successful return -1 */
                        return -1;
        }
        buff[count++] = mod + '0';
        }
        buff[count] = '\0'; /* add null terminator */

        for (i = count; i > 0; i--) /* reverse string and print */
                write(1, &buff[i - 1], 1);

        free(buff); /* free allocated memory */
        return count;
}
/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Prints an unsigned number in octal notation
 * @pf: Lista of arguments
 * 
 * Return: Number of chars printed
 */
int print_octal(va_list pf)
{
        unsigned int num, mod, i;
        size_t size = 32;
        size_t count = 0;
        char *buff = NULL;

        num = va_arg(pf, unsigned int); /* expecting a positive num */

        if (num == 0) /* if the num input is zero; print 0 and return success(1) */
        {
                write(1, "0", 1);
                return 1;
        }
        buff = malloc(size + 1); /* create space to receive binary digits */
        if (buff == NULL) /* if allocation is not successful return -1 */
                return -1;

        buff = malloc(size + 1); /* create space to receive binary digits */
        if (buff == NULL) /* if allocation is not successful return -1 */
                return -1;

        while (num > 0) /* convert num to binary */
	{
                mod = num % 8;
                num /= 8;
                if (count >= size)
                {
                        size *= 2; /* if initial space is not enough then double it */
                        buff = realloc(buff, size + 1); /* add +1 for null terminator '\0' */
                        if (buff == NULL) /* if allocation is not successful return -1 */
                                return -1;
                }
                buff[count++] = mod + '0';
        }
        buff[count] = '\0'; /* add null terminator */

        for (i = count; i > 0; i--) /* reverse string and print */
        write(1, &buff[i - 1], 1);

        free(buff); /* free allocated memory */
        return count;
}
/************** PRINT UNSIGNED NUMBER IN LOWER HEXADECIMAL **************/
/**
 * print_hx - Prints an unsigned number in hexadecimal notation
 * @pf: List of arguments
 * @value: input
 * @buffer: cointainer
 * @buffer_size: cointainer size
 *
 * Return: Number of chars printed
 */
static int print_hx(unsigned int value, char *buffer, size_t buffer_size)
{
        const char *hex_chars = "0123456789abcdef";
        size_t i;
        int count = 0;

        for (i = 0; i < sizeof(unsigned int) * 2 && count < (int) buffer_size - 1; i++)
        {
                char digit = hex_chars[(value >> ((sizeof(unsigned int) * 2 - 1 - i) * 4)) & 0xf];
                buffer[count++] = digit;
        }
        buffer[count] = '\0';
        return count;
}

/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @pf: List of arguments
 *
 * Return: Number of chars printed
 */
int print_hex(va_list pf)
{
        unsigned int num;
        char buffer[17];

        num = va_arg(pf, unsigned int); /* expecting a positive num */

        print_hx((unsigned int) num, buffer, sizeof(buffer));
	/* Write the buffer to standard output*/
        return write(1, buffer, strlen(buffer));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hx - Prints an unsigned number in hexadecimal notation
 * @pf: List of arguments
 * @value: input
 * @buffer: cointainer
 * @buffer_size: cointainer size
 *
 * Return: Number of chars printed
 */
static int print_HX(unsigned int value, char *buffer, size_t buffer_size)
{
        const char *hex_chars = "0123456789ABCDEF";
        size_t i;
        int count = 0;

        for (i = 0; i < sizeof(unsigned int) * 2 && count < (int) buffer_size - 1; i++)
        {
                char digit = hex_chars[(value >> ((sizeof(unsigned int) * 2 - 1 - i) * 4)) & 0XF];
                buffer[count++] = digit;
        }
        buffer[count] = '\0';
        return count;
}

/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @pf: List of arguments
 *
 * Return: Number of chars printed
 */

int print_HEX(va_list pf)
{       
        unsigned int num;
        char buffer[17];

        num = va_arg(pf, unsigned int); /* expecting a positive num */

        print_HX((unsigned int) num, buffer, sizeof(buffer));
	 /* Write the buffer to standard output*/
        return write(1, buffer, strlen(buffer));
}

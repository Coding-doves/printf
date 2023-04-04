**_printf**
	_printf is a custom implementation of the C standard library function printf(). It provides a way to print formatted output to the console or to a file.

**Usage**
	The function prototype for _printf is as follows:
	int _printf(const char *format, ...);
	The first argument is a format string that specifies how the output should be formatted. The remaining arguments are values to be printed, which are inserted into the format string using format specifiers.
	Format specifiers begin with the % character, followed by a conversion character that indicates the type of data to be printed. For example, %s is used to print a string, %d is used to print a decimal integer, and %f is used to print a floating-point number.

**_printf supports the following format specifiers:**

	%c: print a single character,
	%s: print a string,
	%d: print a decimal integer,
	%i: print a decimal integer,
	%b: print an unsigned integer in binary format,
	%u: print an unsigned decimal integer,
	%o: print an unsigned octal integer,
	%x: print an unsigned hexadecimal integer (lowercase),
	%X: print an unsigned hexadecimal integer (uppercase),
	%: print a literal % character

**Return value**
	_printf returns the number of characters printed (excluding the null byte used to end output to strings). If an error occurs, it returns -1.

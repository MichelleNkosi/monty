#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * custom_getline - Custom implementation of getline for C89.
 * @lineptr: Pointer to the buffer that will hold the input.
 * @n: Pointer to the size of the buffer.
 * @stream: File stream to read from.
 *
 * Return: The number of characters read, or -1 on failure.
 */
int custom_getline(char **lineptr, size_t *n, FILE *stream)
{
size_t pos = 0;
int c;
if (*lineptr == NULL)
{
*n = 128;  /* Initial size for the buffer */
*lineptr = malloc(*n);
if (*lineptr == NULL)
return (-1);
}

while ((c = fgetc(stream)) != EOF)
{
if (pos + 1 >= *n)  /* Need to resize the buffer */
{
*n *= 2;
*lineptr = realloc(*lineptr, *n);
if (*lineptr == NULL)
return (-1);
}
(*lineptr)[pos++] = c;
if (c == '\n')  /* End of the line */
break;
}
if (pos == 0 && c == EOF)
return (-1);
(*lineptr)[pos] = '\0';  /* Null-terminate the string */
return (pos);
}

#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: A pointer to the name of the file.
 * @text_content: The string to add to the end of the file.
 * Return: -1 If the function fails or filename is NULL
 *         -1 If the file does not exist the user lacks write permissions
 *         Otherwise 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int s, v, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	s = open(filename, O_WRONLY | O_APPEND);
	v = write(s, text_content, len);

	if (s == -1 || v == -1)
		return (-1);

	close(s);

	return (1);
}

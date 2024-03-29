#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - Allocate 1024 bytes for a buffer.
 * @file: The name of the file buffer is storing chars for.
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(char *file)
{
	char *crack;

	crack = malloc(sizeof(char) * 1024);

	if (crack == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (crack);
}

/**
 * close_file - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
	int e;

	e = close(fd);

	if (e == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 * Return: 0 (success).
 * Description: If the argument count is incorrect - exit code 97.
 *              If file_from does not exist or cannot be read - exit code 98.
 *              If file_to cannot be created or written to - exit code 99.
 *              If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int out, via, d, v;
	char *crack;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	crack = create_buffer(argv[2]);
	out = open(argv[1], O_RDONLY);
	d = read(out, crack, 1024);
	via = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (out == -1 || d == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(crack);
			exit(98);
		}

		v = write(via, crack, d);
		if (via == -1 || v == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(crack);
			exit(99);
		}

		d = read(out, crack, 1024);
		via = open(argv[2], O_WRONLY | O_APPEND);

	} while (d > 0);

	free(crack);
	close_file(out);
	close_file(via);

	return (0);
}

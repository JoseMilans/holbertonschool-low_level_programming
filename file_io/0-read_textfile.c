#include "main.h"
/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: the name of the file to be read
 * @letters: the number of letters to be read and printed
 *
 * Return: actual number of letters it could read and print, or 0 if failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_descriptor;
	char *temp_storage;
	ssize_t bytes_read, bytes_written;

	if (filename == NULL)
		return (0);
	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (0);
	temp_storage = malloc(sizeof(char) * letters);
	if (temp_storage == NULL)
	{
		close(file_descriptor);
		return (0);
	}
	bytes_read = read(file_descriptor, temp_storage, letters);
	if (bytes_read == -1)
	{
		free(temp_storage);
		close(file_descriptor);
		return (0);
	}
	bytes_written = write(STDOUT_FILENO, temp_storage, bytes_read);
	if (bytes_written == -1 || bytes_written != bytes_read)
	{
		free(temp_storage);
		close(file_descriptor);
		return (0);
	}
	free(temp_storage);
	close(file_descriptor);
	return (bytes_written);
}

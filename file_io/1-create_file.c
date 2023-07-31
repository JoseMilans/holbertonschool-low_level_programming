#include "main.h"
/**
 * create_file - creates a file with given content
 * @filename: name of the file to create
 * @text_content: NULL terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int file_descriptor, write_status, length = 0;

	if (filename == NULL)
		return (-1);
	file_descriptor = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (file_descriptor == -1)
		return (-1);
	if (text_content == NULL)
	{
		close(file_descriptor);
		return (1);
	}
	while (text_content[length])
		length++;
	write_status = write(file_descriptor, text_content, length);
	close(file_descriptor);
	if (write_status == -1)
		return (-1);
	return (1);
}

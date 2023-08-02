#include "main.h"
/**
 * close_files - closes file descriptors
 * @fd_from: the file descriptor of the source file to close
 * @fd_to: the file descriptor of the destination file to close
 */
void close_files(int fd_from, int fd_to)
{
	if (close(fd_from) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
	exit(100);
	if (close(fd_to) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
	exit(100);
}
/**
 * copy_content - copies content from one file to another
 * @fd_from: the file descriptor of the source file
 * @fd_to: the file descriptor of the destination file
 */
void copy_content(int fd_from, int fd_to)
{
	char buffer[BUF_SIZE];
	ssize_t bytes_read, write_status;

	while ((bytes_read = read(fd_from, buffer, BUF_SIZE)) > 0)
	{
		write_status = write(fd_to, buffer, bytes_read);
		if (write_status != bytes_read)
			dprintf(STDERR_FILENO, "Error: Can't write to %d\n", fd_to);
		exit(99);
	}
	if (bytes_read == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %d\n", fd_from);
	exit(98);
}
/**
 * check_args - checks if the correct number of arguments is passed
 * @argc: number of arguments
 */
void check_args(int argc)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
}
/**
 * main - main function for the cp command
 * @argc: argument count (number of arguments)
 * @argv: argument vector (the arguments)
 * Return: 0 on success, other values on failure
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	mode_t file_perm = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	check_args(argc);
	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
	exit(98);
	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, file_perm);
	if (fd_to == -1)
		close(fd_from);
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
	exit(99);
	copy_content(fd_from, fd_to);
	close_files(fd_from, fd_to);
	return (0);
}

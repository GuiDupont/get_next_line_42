#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

static int array[2];

int	get_buffer_full(int fd, void *buffer)
{
	int i;

	i = array[0];
	while (i < BUFFER_SIZE)
	{
		if (!(read(fd, &((char *)buffer)[i], 1)))
		{
			((char *)buffer)[i] = '\0';
			return (0);
		}
		if (((char *)buffer)[i] == '\n')
		{
			((char *)buffer)[i] = '\0';
			return (1);
 		}
		i++;
	}
	array[0] += strlen(((char *)buffer));
	return (-1);
}



int	get_next_line(int fd, char *line)
{
	void	*buffer;
	int		returned_value;

	if (!(buffer = malloc((sizeof(*buffer) * (BUFFER_SIZE + 1)))))
		return (-1);
	returned_value = -1;
	while (returned_value == -1)
	{
		returned_value = get_buffer_full(fd, buffer);
		strcat(&line[array[0]], ((char *)buffer));
	}
	if (returned_value == 0)
		return (0);
	return (1);
}

int	main (int ac, char **av)
{
	char line[1000];
	int fd;

	line[0] = '\0';
	fd = open("test.txt", O_RDONLY);
	if (fd != -1)
	{
		while (get_next_line(fd, &line[0]) != 0)
		{ }
	printf("%s", &line[0]);
	}
}

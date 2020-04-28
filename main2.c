#include "get_next_line.h"

int main ()
{
	char *line;
	int fd;
	int result;

	fd = open("tests/marseillaise.txt", O_RDONLY);
	while (fd >= 0)
	{
		while (1)
		{
			result = get_next_line(fd, &line);
			if (result == -1)
				break;
			printf("line : %s\n", line);
			if (line)
			{
				free(line);
				line = NULL;
			}
			if (result == 0)
				break;
		}
	}
	getchar();
	close (fd);
	return (0);
}
#include "get_next_line.h"

int main ()
{
	char *line;
	int fd;

	int result;


	fd = open("tests/marseillaise.txt", O_RDONLY);
	if (fd != -1)
	{
		while (1)
		{
			result = get_next_line(fd, &line);
			if (result == -1)
				break;
			printf("File 1 = -%s-\n", line);
			if (line)
			{
				free(line);
				line = NULL;
			}
			if (result == 0)
				break;
		}
	}
	return (0);
}

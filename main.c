#include "get_next_line.h"

int main ()
{
	char *line;
	char *line2;
	int fd;
	int fd2;
	int result;
	int result2;

	fd = open("marseillaise.txt", O_RDONLY);
//	fd = open("link", O_RDONLY);
	fd2 = open("short_lines.txt", O_RDONLY);
//	fd2 = open("empty.txt", O_RDONLY);
	if (fd != -1)
	{
		while (1)
		{
			result = get_next_line(fd, &line);
			result2 = get_next_line(fd2, &line2);
			if (result == -1 || result2 == -1)
				break;
			printf("File 1 = -%s-\n", line);
			printf("FIle 2 = -%s-\n", line2);
			if (line)
			{
				free(line);
				line = NULL;
			}
			if (line2)
			{
				free(line);
				line2 = NULL;
			}
			if (result == 0 || result2 == 0)
				break;
		}
	}
	return (0);
}

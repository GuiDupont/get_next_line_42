#include "get_next_line.h"

int main (int ac, char **av)
{
	char *line[50];
	int fd[50];
	int result;
	int i;

	i = 0;
	while (i < ac)
	{
		fd[i] = open(av[1], O_RDONLY);
		i++;
	}
	i = 0;
	while (fd[i] >= 0 && i < ac)
	{
		while (1)
		{
			result = get_next_line(fd[i], &line[i]);
			if (result == -1)
				break;
			printf("file nb %d : %s", i, line[i]);
			if (line[i])
			{
				free(line[i]);
				line[i] = NULL;
			}
			if (result == 0)
				break;
		}
		printf("\n\n");
		i++;
	}
	return (0);
}

#include "get_next_line.h"

int main ()
{
	char *line;
	
	int fd;
      
	int result;

	fd = open("tests/marseillaise.txt", O_RDONLY);
		while (1)
		{
		      result = get_next_line(fd, &line);
		      printf("%d line : %s\n", result, line);
					  
			if (line)
			{
				free(line);
				line = NULL;
			}
			if (result <= 0 )
				break;
		}
	
	close (fd);
	return (0);
}